(load "../util.scm")
(load "vec-2.scm")

(define num-rows
    (lambda (mat)
        (vector-length mat)
    )
)

(define num-cols
    (lambda (mat)
        (vector-length (vector-ref mat 0))
    )
)

(define matrix-ref
    (lambda (mat)
        (lambda (i j)
            (vector-ref
                (vector-ref mat i)
                j
            )
        )
    )
)

(define matrix-set!
    (lambda (mat)
        (lambda (i j obj)
            (let
                ((vec (vector-ref mat i)))
            )
            (vector-update! vec j obj)
        )
    )
)

(define matrix-generator
    (lambda (gen-proc)
        (lambda (nrows ncols)
            (let
                ((gen-mat (lambda (i)
                    ((vector-generator (lambda (k)
                        (gen-proc i k)
                    )) ncols)
                )))
                ((vector-generator gen-mat) nrows)
            )
        )
    )
)
