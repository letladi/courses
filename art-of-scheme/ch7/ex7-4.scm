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
        (flat-recur '() (lambda (x y)
            (if (equal? x old)
                (cons new (cons x y))
                (cons x y)
            )
        ))
    )
)

(define insert-left
    (lambda (new old ls)
        ((insert-left-m new old) ls)
    )
)

(define partial
    (lambda (seed next-proc)
        (lambda (proc start end)
            (letrec
                (
                    (helper (lambda (i result)
                        (cond
                            ((> i end) result)
                            (else
                                (helper
                                    (1+ i)
                                    (next-proc
                                        (proc i)
                                        result
                                    )
                                )
                            )
                        )
                    ))
                )
                (helper start seed)
            )
        )
    )
)

(define partial-sum (partial 0 +))

(define partial-product (partial 1 *))
