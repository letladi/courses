(load "set.scm")

(define there-exists
    (lambda (pred)
        (letrec
            ((test (lambda (s)
                (if (empty-set? s)
                    #f
                    (let
                        ((elem (pick s)))

                        (or
                            (pred elem)
                            (test ((residue elem) s))
                        )
                    )
                )
            )))

            test
        )
    )
)

(define none
    (lambda (pred)
        (lambda (s)
            (if ((there-exists pred) s)
                #f ; some pass pred,
                #t ; none pass pred
            )
        )
    )
)

(define for-all
    (lambda (pred)
        (lambda (s)
            (if ((there-exists (compose not pred)) s)
                #f ; some pass opposite of pred
                #t ; none pass opposite of pred -> all pass pred
            )
        )
    )
)
