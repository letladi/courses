(load "natural-mergesort.scm")

(define make-groups
    (lambda (ls rel)
        (cond
            ((null? ls) '())
            ((null? (cdr ls)) (list ls))
            (else
                (cons (list (car ls)) (make-groups (cdr ls) rel))
            )
        )
    )
)
