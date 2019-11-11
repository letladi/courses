(define member?
    (lambda (a lat)
        (cond
            ((null? lat) #f)
            (else
                (or
                    (eq? a (car lat))
                    (member? a (cdr lat))
                )
            )
        )
    )
)
