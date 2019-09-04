(load "quant.scm")

(define both
    (lambda (pred)
        (letrec
            ((fn (compose not pred)))

            (lambda (arg1 arg2)
                (not ((at-least-one fn) arg1 arg2))
            )
        )
    )
)

(define neither
    (lambda (pred)
        (letrec
            ((fn (at-least-one pred)))

            (lambda (arg1 arg2)
                (not (fn arg1 arg2))
            )
        )
    )
)
