(define-syntax freeze
    (syntax-rules ()
        [(_ expr1 expr2 ...)
            (lambda ()
                expr1 expr2 ...
            )
        ]
    )
)

(define thaw
    (lambda (thunk)
        (thunk)
    )
)

(define cycle-proc
    (lambda (th)
        (letrec ((loop (lambda ()
            (thaw th)
            (loop)
        )))
            (loop)
        )
    )
)
