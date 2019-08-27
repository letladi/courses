(define flat-recur
    (lambda (seed list-proc)
        (letrec
            ((helper (lambda (ls)
                (if (null? ls)
                    seed
                    (list-proc (car ls) (helper (cdr ls)))
                )
            )))
            helper
        )
    )
)

(define member?-c
    (lambda (item)
        (flat-recur #f (lambda (x y) (or (equal? x item) y)))
    )
)

(define apply-to-all
    (lambda (proc)
        (flat-recur '() (lambda (x y) (cons (proc x) y)))
    )
)

(define sum (flat-recur 0 +))

(define product (flat-recur 1 *))

(define filter-in-c
    (lambda (pred)
        (flat-recur
            '()
            (lambda (x y)
                (if (pred x)
                    (cons x y)
                    y
                )
            )
        )
    )
)

(define filter-in
    (lambda (pred ls)
        ((filter-in-c pred) ls)
    )
)
