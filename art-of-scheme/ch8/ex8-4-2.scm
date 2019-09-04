(define for-all
    (lambda (pred)
        (letrec
            ((test (lambda (s)
                (let
                    ((elem (pick s)))

                    (and
                        (pred elem)
                        (test ((residue elem) s))
                    )
                )
            )))

            test
        )
    )
)

(define none
    (lambda (pred)
        (for-all (compose not pred))
    )
)

(define there-exists
    (lambda (pred)
        (lambda (s)
            (if ((for-all (compose not pred)) s)
                #f ; all pass the opposite of pred
                #t ; some fail the opposite of pred
            )
        )
    )
)
