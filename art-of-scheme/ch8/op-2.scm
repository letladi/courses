(define make-op
    (lambda (x y)
        (list x y)
    )
)

(define op?
    (lambda (ls)
        (and
            (pair? ls)
            (pair? (cdr ls))
            (null? (cddr ls))
        )
    )
)

(define op-1st car)

(define op-2nd cadr)
