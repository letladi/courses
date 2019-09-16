(load "ordered-pair.scm")
(load "sec8-3-ex.scm")

(define relation?
    (lambda (rel)
        (cond
            ((empty-set? rel) #t)
            (else
                (letrec*
                    (
                        (rel-len (cardinality rel))
                        (subsets-with-2-elements ((select-by-cardinality 2) rel))
                        (num-subsets-with-2-elements (cardinality subsets-with-2-elements))
                    )
                    (=
                        rel-len
                        num-subsets-with-2-elements
                    )
                )
            )
        )
    )
)

(define inverse-relation
    (lambda (rel)
        (set-map
            rel
            (lambda (op)
                (let
                    (
                        (x (op-1st op))
                        (y (op-2nd op))
                    )
                    (make-op y x)
                )
            )
        )
    )
)

(define one-to-one?
    (lambda (rel)
        (and
            (function? rel)
            (function? (inverse-relation rel))
        )
    )
)

(define make-relation
    (lambda args
        (cond
            ((null? args) the-empty-set)
            ((= (length args) 1)
                (make-set
                    (apply make-op (car args))
                )
            )
            (else
                (letrec*

                    (
                        (arg-1 (car args))
                        (op (apply make-op arg-1))
                    )
                    (adjoin
                        op
                        (apply make-relation (cdr args))
                    )
                )
            )
        )
    )
)

(define reflexive?
    (lambda (rel)
        (letrec*
            (
                (dom (domain rel))
                (rel-contains? (contains rel))
                (helper (lambda (rel-domain)
                    (cond
                        ((empty-set? rel-domain) #t)
                        (else
                            (letrec*
                                (
                                    (elem (pick rel-domain))
                                    (rest-domain ((residue elem) rel-domain))
                                    (elem-op (make-op elem elem))
                                )
                                (and
                                    (rel-contains? elem-op)
                                    (helper rest-domain)
                                )
                            )
                        )
                    )
                ))
            )
            (helper dom)
        )
    )
)
