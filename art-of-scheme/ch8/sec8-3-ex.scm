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

; (define intersection
;     (lambda args
;         (cond
;             ((null? args) the-empty-set)
;             ((= (length args) 1) args)
;             (else
;                 (letrec*
;
;                     (
;                         (s1 (car args))
;                         (s2 (cadr args))
;                         (rest (cddr args))
;                         (helper (lambda (s1)
;                             (if (empty-set? s1)
;                                 the-empty-set
;                                 (let ((elem (pick s1)))
;                                     (if ((contains s2) elem)
;                                         (adjoin elem (helper ((residue elem) s1)))
;                                         (helper ((residue elem) s1))
;                                     )
;                                 )
;                             )
;                         ))
;                         (intersect-two (helper s1))
;                     )
;
;
;                     (apply
;                         intersection
;                         (cons intersect-two rest)
;                     )
;                 )
;             )
;         )
;     )
; )

(define intersection (set-fn-builder
    (lambda (set1 set2)
        the-empty-set
    )
    (lambda (set2 elem-of-first-set)
        ((contains set2) elem-of-first-set)
    )
))

; (define union
;     (lambda args
;         (cond
;             ((null? args) the-empty-set)
;             ((= (length args) 1) args)
;             (else
;                 (letrec*
;                     (
;                         (s1 (car args))
;                         (s2 (cadr args))
;                         (rest (cddr args))
;                         (helper (lambda (s1)
;                             (if (empty-set? s1)
;                                 s2
;                                 (let ((elem (pick s1)))
;                                     (if (not ((contains s2) elem))
;                                         (adjoin elem (helper ((residue elem) s1)))
;                                         (helper ((residue elem) s1))
;                                     )
;                                 )
;                             )
;                         ))
;                         (union-two (helper s1))
;                     )
;
;                     (apply
;                         union
;                         (cons union-two rest)
;                     )
;                 )
;             )
;         )
;
;     )
; )

(define union (set-fn-builder
    (lambda (set1 set2)
        set2
    )
    (lambda (set2 elem-of-first-set)
        (not ((contains set2) elem-of-first-set))
    )
))
