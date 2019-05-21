(define make-list-of-one
    (lambda (item)
        (cons item '())
    )
)

(define make-list-of-two                        ; this procedure creates
    (lambda (item1 item2)                       ; a list of two items.
        (cons item1 (make-list-of-one item2))
    )
)

(define regroup
    (lambda (list-of-4)
        (make-list-of-two
            (first-group list-of-4)
            (second-group list-of-4)
        )
    )
)

(define first-group
    (lambda (ls)
        (make-list-of-two (car ls) (cadr ls))
    )
)

(define second-group
    (lambda (ls)
        (cddr ls)
    )
)

(define (second ls)
    (cadr ls)
)

(define (third ls)
    (caddr ls)
)   

(define (firsts-of-both ls1 ls2)
    (make-list-of-two (car ls1) (car ls2))
)

(define (juggle ls)
    (cons (third ls) (cons (second ls) (make-list-of-one (car ls))))
)

(define (switch ls)
    (cons
        (third ls)
        (cons 
            (second ls)
            (make-list-of-one (car ls))
        )
    )
)