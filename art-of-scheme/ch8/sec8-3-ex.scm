(load "set-definition.scm")
(load "set-definition-2.scm")
(load "quant.scm")
; (load "set.scm")

(define pick
    (lambda (s)
        (car (cdr s))
    )
)

(define intersection
    (lambda args
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
                                the-empty-set
                                (let ((elem (pick s1)))
                                    (if ((contains s2) elem)
                                        (adjoin elem (helper ((residue elem) s1)))
                                        (helper ((residue elem) s1))
                                    )
                                )
                            )
                        ))
                        (intersect-two (helper s1))
                    )


                    (apply
                        intersection
                        (cons intersect-two rest)
                    )
                )
            )
        )
    )
)

(define union
    (lambda args
        (cond
            ((null? args) the-empty-set)
            ((= (length args) 1) args)
        )

    )
)
