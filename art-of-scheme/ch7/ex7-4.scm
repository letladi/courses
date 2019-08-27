(load "flat-rec.scm")

(define mult-by-scalar
    (lambda (c)
        (flat-recur '() (lambda (x y) (cons (* c x) y)))
    )
)

(define filter-out
    (lambda (pred ls)
        (letrec
            ((filter-out-c (lambda (item)
                (pred item)
            )))

            ((flat-recur '() (lambda (x y) (if (filter-out-c x) y (cons x y)))) ls)
        )
    )
)

(define insert-left-m
    (lambda (new old)
        (flat-recur '() (lambda (x y) (if (equal? x old) (cons new (cons x y)))))
    )
)
