(load "quant.scm")

(define equal?
    (lambda (arg1 arg2)
        (letrec
            (
                (both-atoms? (neither pair?))
                (both-lists? (both pair?))
                (both-empty? (both null?))
                (at-least-one-empty? (at-least-one null?))
                (helper (lambda (item1 item2)
                    (cond
                        ((both-atoms? item1 item2) (eqv? item1 item2))
                        ((both-lists? item1 item2)
                            (cond
                                ((both-empty? item1 item2) #t)
                                ((at-least-one-empty? item1 item2) #f)
                                (else
                                    (and
                                        (helper (car item1) (car item2))
                                        (helper (cdr item1) (cdr item2))
                                    )
                                )
                            )
                        )
                        (else #f)
                    )
                ))
            )

            (helper arg1 arg2)
        )
    )
)
