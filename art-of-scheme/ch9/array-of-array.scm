; we note that (m1xm2xm3) is the size of all the elements in the array of arrays of arrays
; to get array i, we times i by m1 to get index i, to get array j we add i to the product of jxm2 to get p
; and then to get k, we add p to the product of kxm3.

; In general, to get the index i in the vector for any array of arrays with dimension M1xM2...xMn, given indices i1, i2, i3,..., in,
; we perfom the following computation; i = i1xM1 + ... + inxMn

; On the other hand, to perform the computation the other way around; that given an index i the vector, how do we get the i,j,k
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

(define array-ref
    (lambda (arr)

    )
)
