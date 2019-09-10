(load "../ch2/rec.scm")
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
