(load "../util.scm")

(define both
    (lambda (pred)
        (lambda (arg1 arg2)
            (and
                (pred arg1)
                (pred arg2)
            )
        )
    )
)

(define neither
    (lambda (pred)
        (lambda (arg1 arg2)
            (not
                (or
                    (pred arg1)
                    (pred arg2)
                )
            )
        )
    )
)

(define at-least-one
    (lambda (pred)
        (lambda (arg1 arg2)
            (or (pred arg1) (pred arg2))
        )
    )
)
