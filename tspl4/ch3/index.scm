(define-syntax and
    (syntax-rules ()
        [(_) #t]
        [(_ e) e]
        [(_ e1 e2 e3 ...)
            (if e1 (and e2 e3 ...) #f)
        ]
    )
)

(define-syntax and ; incorrect
    (syntax-rules ()
        [(_) #t]
        [(_ e1 e2 ...)
            (if e1 (and e2 ...) #f)
        ]
    )
)

(define-syntax or
    (syntax-rules ()
        [(_) #f]
        [(_ e) e]
        [(_ e1 e2 e3 ...)
            (let ([t e1])
                (if t t (or e2 e3 ...))
            )
        ]
    )
)

(define-syntax or ; incorrect!
    (syntax-rules ()
        [(_) #f]
        [(_ e1 e2 ...)
            (let ([t e1])
                (if t t (or e2 ...))
            )
        ]
    )
)
