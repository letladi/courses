(load "../util.scm")
(load "vec-2.scm")

(define num-cols
    (lambda (mat)
        (let
            ((size (1- (vector-length mat))))
            (/ size (vector-ref mat size))
        )
    )
)

(define num-rows
    (lambda (mat)
        (let
            ((size (1- (vector-length mat))))
            (vector-ref mat size)
        )
    )
)

(define matrix-ref
    (lambda (mat)
        (lambda (i j)
            (let
                (
                    (nrows (num-rows mat))
                    (index-in-vec (+ i (* j nrows)))
                )
                (vector-ref mat index-in-vec)
            )
        )
    )
)

(define matrix-set!
    (lambda (mat)
        (lambda (i j obj)
            (let
                (
                    (nrows (num-rows mat))
                    (index-in-vec (+ i (* j nrows)))
                )
                (vector-update! mat index-in-vec obj)
            )
        )
    )
)

(define matrix-generator
    (lambda (gen-proc)
        (lambda (nrows ncols)
            (let
                ((size (* nrows ncols)))
                (let
                    ((vec-gen-proc (lambda (k)
                        (if (< k size)
                            (gen-proc (remainder k nrows) (quotient k nrows))
                            nrows
                        )
                    )))

                    ((vector-generator ven-gen-proc) (1+ size))
                )
            )
        )
    )
)
