(define set-tag "set")
(define the-empty-set (cons set-tag '()))

(define empty-set?
    (lambda (s)
        (eq? s the-empty-set)
    )
)

(define set?
    (lambda (arg)
        (and
            (pair? arg)
            (eq? (car arg) set-tag)
        )
    )
)

(define pick
    (lambda (s)
        (let
            ((ls (cdr s)))

            (if (null? s)
                (begin
                    (display "pick: the set is empty.")
                    (newline)
                )
                (list-ref ls (random (length ls)))
            )
        )
    )
)

(define residue
    (lambda (elem)
        (lambda (s)
            (let
                ((ls (remove elem (cdr s))))
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
        (cons set-tag (cons elem (cdr s)))
    )
)
