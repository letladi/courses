(load "set-definition.scm")
(load "set-definition-2.scm")
(load "quant.scm")
(load "set.scm")

(define pick
    (lambda (s)
        (car (cdr s))
    )
)

(define set-fn-builder
    (lambda (seed-getter combination-predicate)
        (letrec*
            ((fn (lambda args
                (cond
                    ((null? args) the-empty-set)
                    ((= (length args) 1) (car args))
                    (else
                        (letrec*
                            (
                                (s1 (car args))
                                (s2 (cadr args))
                                (rest (cddr args))
                                (helper (lambda (s1)
                                    (if (empty-set? s1)
                                        (seed-getter s1 s2)
                                        (let ((elem (pick s1)))
                                            (if (combination-predicate s2 elem)
                                                (adjoin elem (helper ((residue elem) s1)))
                                                (helper ((residue elem) s1))
                                            )
                                        )
                                    )
                                ))
                                (combo-two (helper s1))
                            )

                            (apply
                                fn
                                (cons combo-two rest)
                            )
                        )
                    )
                )
            )))

            fn
        )
    )
)

(define intersection (set-fn-builder
    (lambda (set1 set2)
        the-empty-set
    )
    (lambda (set2 elem-of-first-set)
        ((contains set2) elem-of-first-set)
    )
))

(define union (set-fn-builder
    (lambda (set1 set2)
        set2
    )
    (lambda (set2 elem-of-first-set)
        (not ((contains set2) elem-of-first-set))
    )
))

(define symmetric-difference
    (lambda (s1 s2)
        (if (empty-set? s1)
            s2
            (let*
                (
                    (elem (pick s1))
                    (residue-elem (residue elem))
                )
                (if ((contains s2) elem)
                    (symmetric-difference
                        (residue-elem s1)
                        (residue-elem s2)
                    )
                    (adjoin
                        elem
                        (symmetric-difference
                            (residue-elem s1)
                            s2
                        )
                    )
                )
            )
        )
    )
)

(define set-map
    (lambda (s proc)
        (cond
            ((empty-set? s) the-empty-set)
            (else
                (let
                    ((elem (pick s)))
                    (adjoin
                        (proc elem)
                        (set-map
                            ((residue elem) s)
                            proc
                        )
                    )
                )
            )
        )
    )
)

(define power-set
    (lambda (s)

        (cond
            ((empty-set? s) (make-set the-empty-set))
            (else
                (letrec*
                    (
                        (elem (pick s))
                        (rest ((residue elem) s))
                        (subset (power-set rest))
                    )

                    (union
                        subset
                        (set-map subset (lambda (set)
                            (adjoin elem set)
                        ))
                    )
                )
            )
        )
    )
)

(define cardinality
    (lambda (s)
        (1- (length s))
    )
)

(define filter-set
    (lambda (s filter-proc)
        (cond
            ((empty-set? s) the-empty-set)
            (else
                (letrec*
                    (
                        (elem (pick s))
                        (rest ((residue elem) s))
                    )
                    (if (filter-proc elem)
                        (adjoin
                            elem
                            (filter-set rest filter-proc)
                        )
                        (filter-set rest filter-proc)
                    )
                )
            )
        )
    )
)

(define select-by-cardinal
    (lambda (n)
        (lambda (s)
            (filter-set
                s
                (lambda (subset)
                    (= (cardinality subset) n)
                )
            )
        )
    )
)
