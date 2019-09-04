(define for-one
    (lambda (pred found-proc not-found-proc)
        (letrec
            ((test (lambda (s)
                (if (empty-set? s)
                    (not-found-proc)
                    (let
                        ((v (pick s)))

                        (if (pred v)
                            (found-proc v)
                            (test ((residue v) s))
                        )
                    )
                )
            )))

            test
        )
    )
)

(define there-exists
    (lambda (pred)
        (for-one
            pred
            (lambda (v) #t)
            (lambda () #f)
        )
    )
)

(define none
    (lambda (pred)
        (for-one
            pred
            (lambda (v) #f)
            (lambda () #t)
        )
    )
)

(define for-all
    (lambda (pred)
        (for-one
            (compose not pred)
            (lambda (v) #f)
            (lambda () #t)
        )
    )
)
