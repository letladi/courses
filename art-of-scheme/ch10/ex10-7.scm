(load "relational-calculus.scm")

(define set-builder-map
    (lambda (pred proc base-set)
        (letrec
            ((helper (lambda (s)
                (if (empty-set? s)
                    base-set
                    (let
                        ((elem (pick s)))

                        (if (pred elem)
                            (adjoin
                                (proc elem)
                                (helper ((residue elem) s))
                            )
                            (helper ((residue elem) s))
                        )
                    )
                )
            )))

            helper
        )
    )
)
