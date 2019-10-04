(define list-linear-search
    (lambda (ls num)
        (letrec
            ((search (lambda (ls i)
                (cond
                    ((null? ls) -1)
                    ((= (car ls) num) i)
                    (else
                        (search (cdr ls) (1+ i))
                    )
                )
            )))
            (search ls 0)
        )
    )
)
