(define curried+
    (lambda (m)
        (lambda (n)
            (+ m n)
        )
    )
)

(define member?-c
    (lambda (item)
        (letrec
            ((helper (lambda (ls)
                (if (null? ls)
                    #f
                    (or
                        (equal? (car ls) item)
                        (helper (cdr ls))
                    )
                )
            )))
            helper
        )
    )
)

(define member?
    (lambda (a ls)
        ((member?-c a) ls)
    )
)

(define apply-to-all
    (lambda (proc)
        (letrec
            ((helper (lambda (ls)
                (if (null? ls)
                    '()
                    (cons (proc (car ls)) (helper (cdr ls)))
                )
            )))

            helper
        )
    )
)

(define map
    (lambda (proc ls)
        ((apply-to-all proc) ls)
    )
)

(define sum
    (letrec
        ((helper (lambda (ls)
            (if (null? ls)
                0
                (+ (car ls) (helper (cdr ls)))
            )
        )))
        helper
    )
)

(define product
    (letrec
        ((helper (lambda (ls)
            (if (null? ls)
                1
                (* (car ls) (helper (cdr ls)))
            )
        )))
        helper
    )
)

(define swapper
    (lambda (x y ls)
        (cond
            ((null? ls) '())
            ((equal? (car ls) x) (cons y (swapper x y (cdr ls))))
            ((equal? (car ls) y) (cons x (swapper x y (cdr ls))))
            (else (cons (car ls) (swapper x y (cdr ls))))
        )
    )
)

(define swapper-m
    (lambda (x y)
        (letrec
            ((helper (lambda (ls)
                (cond
                    ((null? ls) '())
                    ((equal? (car ls) x) (cons y (helper (cdr ls))))
                    ((equal? (car ls) y) (cons x (helper (cdr ls))))
                    (else (cons (car ls) (helper (cdr ls))))
                )
            )))

            helper
        )
    )
)

(define curried*
    (lambda (x)
        (lambda (y) (* x y))
    )
)

(define swapper-c
    (lambda (x)
        (lambda (y)
            (swapper-m x y)
        )
    )
)
