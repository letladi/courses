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
    (lambda (helper-seed-getter combination-predicate)
        (letrec*
            ((fn (lambda args
                (cond
                    ((null? args) the-empty-set)
                    ((= (length args) 1) args)
                    (else
                        (letrec*
                            (
                                (s1 (car args))
                                (s2 (cadr args))
                                (rest (cddr args))
                                (helper (lambda (s1)
                                    (if (empty-set? s1)
                                        (helper-seed-getter s1 s2)
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

(define power-set
    (lambda (s)
        (letrec*
            (
                (one-el-subsets (lambda (s)
                    (if (empty-set? s)
                        the-empty-set
                        (let
                            (
                                (elem (pick s))
                            )

                            (adjoin
                                (make-set elem)
                                (power-set ((residue elem) s))
                            )
                        )
                    )
                ))
                (subsets (one-el-subsets s))
            )

            subsets
        )
    )
)

(define select-by-cardinal
    (lambda (n)
        (lambda (s)
            (letrec
                ((helper (lambda (set)
                    (let
                        (
                            (elem (pick set))
                            (rest ((residue elem) set))
                            (len (1- (length elem)))
                        )

                        (cond
                            ((empty-set? set) the-empty-set)
                            ((= n len)
                                (adjoin
                                    elem
                                    (helper rest)
                                )
                            )
                            (else
                                (helper rest)
                            )
                        )
                    )
                )))

                (helper s)
            )
        )
    )
)
