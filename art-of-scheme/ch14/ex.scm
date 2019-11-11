(define-syntax letrec2
    (syntax-rules ()
        [(_ ((var val)) p1 ...)
            ((lambda (var) p1 ...) val)
        ]
        [(_ ((var1 val1) (var2 val2) ...) p1 ...)
            ((lambda (var1)
                (letrec2
                    ((var2 val2) ...)
                    p1 ...
                )
            ) val1)
        ]
    )
)
