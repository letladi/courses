(define deep-recur
    (lambda (seed item-proc list-proc)
        (letrec
            ((helper (lambda (ls)
                (if (null? ls)
                    seed
                    (let ((a (car ls)))
                        (if (or (pair? a) (null? a))
                            (list-proc (helper a) (helper (cdr ls)))
                            (item-proc a (helper (cdr ls)))
                        )
                    )
                )
            )))

            helper
        )
    )
)

(define filter-in-all-c
    (lambda (pred)
        (deep-recur
            '()
            (lambda (x y)
                (if (pred x)
                    (cons x y)
                    y
                )
            )
            cons
        )
    )
)

(define filter-in-all
    (lambda (pred ls)
        ((filter-in-all-c pred) ls)
    )
)

(define sum-all (deep-recur 0 + +))
