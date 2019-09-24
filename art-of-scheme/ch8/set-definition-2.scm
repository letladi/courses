(load "../ch2/rec.scm")
(load "quant.scm")
(load "set-definition.scm")

(define residue
    (lambda (elem)
        (lambda (s)
            (let
                ((ls (remove-1st elem (cdr s))))
                (cond
                    ((null? ls) the-empty-set)
                    (else (cons set-tag ls))
                )
            )
        )
    )
)

(define adjoin
    (lambda (elem s)
        (cond
            ((member? elem (cdr s)) s)
            (else
                (cons set-tag (cons elem (cdr s)))
            )
        )
    )
)

(define view-set
    (lambda (s)
        (let
            ((loop (lambda (s)
                    (if (not (empty-set? s))
                        (let
                            (
                                (elem (pick s))
                                (rest ((residue elem) s))
                            )
                            (display elem)
                            (if (not (empty-set? rest))
                                (display ", ")
                            )
                            (loop rest)
                        )
                    )
            )))
            (newline)
            (display "{")
            (loop s)
            (display "}")
            (newline)
        )
    )
)
