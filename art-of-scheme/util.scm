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

(define writeln
    (lambda args
        (for-each display args)
        (newline)
    )
)

(define error
    (lambda args
        (display "Error: ")
        (for-each (lambda (value) (display " ") (display value)) args)
        (newline)
        (reset)
    )
)
