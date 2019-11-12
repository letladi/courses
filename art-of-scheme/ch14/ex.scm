; ex14.2
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

; ex14.4
(define-syntax and2
    (syntax-rules ()
        [(_) #t]
        [(_ e1)
            e1
        ]
        [(_ e1 e2 e3 ...)
            (let ((val e1))
                (if val
                    (and2 e2 e3 ...)
                    #f
                )
            )
        ]
    )
)

; ex14.8
(define-syntax n-let
    (syntax-rules ()
        [(_ ((v1 val1) ...) p1 p2 ...)
            ((lambda (v1 ...) p1 p2 ...) val1 ...)
        ]
        [(_ let-name ((v1 val1) ...) p1 p2 ...)
            ((letrec ((let-name (lambda (v1 ...) p1 p2 ...)))
                let-name
            ) val1 ...)
        ]
    )
)

; ex14.10
(define-syntax while
    (syntax-rules ()
        [(_ pred expr1 expr2 ...)
            (letrec
                ((loop (lambda ()
                    (if pred
                        (begin expr1 expr2 ... (loop))
                    )
                )))
                (loop)
            )
        ]
    )
)

; ex14.11
(define-syntax repeat
    (syntax-rules ()
        []
    )
)
