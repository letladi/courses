(define index
    (lambda (ls el)
        (letrec
            ((index-helper (lambda (ls el i)
                (cond
                    ((null? ls) -1)
                    ((equal? (car ls) el) i)
                    (else
                        (index-helper (cdr ls) el (1+ i))
                    )
                )
            )))

            (index-helper ls el 0)
        )
    )
)

(define console-error
    (lambda (msg)
        (console-log msg)
    )
)

(define console-log
    (lambda (msg)
        (begin
            (newline)
            (display msg)
            (newline)
        )
    )
)
