; we note that (m1xm2xm3) is the size of all the elements in the array of arrays of arrays
; to get array i, we times i by m1 to get index i, to get array j we add i to the product of jxm2 to get p
; and then to get k, we add p to the product of kxm3.

; In general, to get the index i in the vector for any array of arrays with dimension M1xM2...xMn, given indices i1, i2, i3,..., in,
; we perfom the following computation; i = i1xM1 + ... + inxMn

; On the other hand, to perform the computation the other way around; that is, given an index i in the vector, how do we get the i,j,k
; in the array of arrays of arrays
(define size-dim-1
    (lambda (arr)
        (let
            (
                (size (vector-length arr))
                (m2-times-m3 (vector-ref arr (1- size)))
                (m1-times-m2-times-m3 (- size 2))
            )
            (quotient m1-times-m2-times-m3 m2-times-m3)
        )
    )
)

(define size-dim-2
    (lambda (arr)
        (let
            ((size (vector-length arr)))
            (vector-ref arr (- size 2))
        )
    )
)

(define size-dim-3
    (lambda (arr)
        (let
            (
                (size (vector-length arr))
                (m2-times-m3 (vector-ref arr (1- size)))
                (m2 (vector-ref arr (- size 2)))
            )
            (quotient m2-times-m3 m2)
        )
    )
)

(define get-vec-index
    (lambda (arr i j k)
        (+
            (* (size-dim-1 arr) i)
            (* (size-dim-2 arr) j)
            k
        )
    )
)

(define get-array-of-array-indices
    (lambda (vec-size vec-index m1 m2 m3)
        (letrec*
            (
                (m2-times-m3 (* m2 m3))
                (m1-sized-divisions (quotient vec-size m2))
                (m2-sized-divisions (quotient vec-size m2))
                (i (quotient vec-index m1-sized-divisions))
                (j (quotient vec-index m2-sized-divisions))
                (k (remainder vec-index m3))
            )
            (list i j k)
        )
    )
)

(define array-ref
    (lambda (arr i j k)
        (vector-ref
            arr
            (get-vec-index arr i j k)
        )
    )
)

(define array-set!
    (lambda (arr i j k obj)
        (let
            ((index (get-vec-index arr i j k)))
            (vector-update! arr index obj)
        )
    )
)

(define array-generator
    (lambda (gen-proc)
        (lambda (m1 m2 m3)
            (let
                (
                    (size (+ 2 (* m1 m2 m3)))
                    (m2-times-m3 (* m2 m3))
                    (array-proc (lambda (vec-index)
                        (cond
                            ((= vec-index (1- size)) m2-times-m3)
                            ((= vec-index (- size 2)) m2)
                            (else
                                (apply gen-proc (get-array-of-array-indices size vec-index m1 m2 m3))
                            )
                        )
                    ))
                )

            )
        )
    )
)
