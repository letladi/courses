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
