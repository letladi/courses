(define legal?
    (lambda (try legal-pl)
        (letrec
            (
                (good? (lambda (new-pl up down)
                    (cond
                        ((null? new-pl) #t)
                        (else
                            (let
                                ((next-pos (car new-pl)))

                                (and
                                    (not (= next-pos try))
                                    (not (= next-pos up))
                                    (not (= next-pos down))
                                    (good?
                                        (cdr new-pl)
                                        (1+ up)
                                        (1- down)
                                    )
                                )
                            )
                        )
                    )
                ))
            )

            (good? legal-pl (1+ try) (1- try))
        )
    )
)

(define solution?
    (lambda (legal-pl)
        (= (length legal-pl) 8)
    )
)

(define fresh-try 8)

(define build-solution
    (lambda (legal-pl)
        (cond
            ((solution? legal-pl) legal-pl)
            (else (forward fresh-try legal-pl))
        )
    )
)

(define forward
    (lambda (try legal-pl)
        (cond
            ((zero? try) (backtrack legal-pl))
            ((legal? try legal-pl) (build-solution (cons try legal-pl)))
            (else (forward (1- try) legal-pl))
        )
    )
)

(define backtrack
    (lambda (legal-pl)
        (cond
            ((null? legal-pl) '())
            (else (forward (1- (car legal-pl)) (cdr legal-pl)))
        )
    )
)
