(load "index.scm")

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

(define round-n-places
    (lambda (n)
        (lambda (dec-num)
            (let
                ((scale-factor (expt 10 n)))

                (/ (round (* dec-num scale-factor)) scale-factor)
            )
        )
    )
)

(define subst-all-m
    (lambda (new old)
        (letrec
            ((subst-all (lambda (ls)
                (cond
                    ((null? ls) '())
                    ((equal? (car ls) old)
                        (cons new (subst-all (cdr ls)))
                    )
                    ((pair? (car ls))
                        (cons
                            (subst-all (car ls))
                            (subst-all (cdr ls))
                        )
                    )
                    (else
                        (cons
                            (car ls)
                            (subst-all (cdr ls))
                        )
                    )
                )
            )))

            subst-all
        )
    )
)

(load "../ch3/ratl.scm")

(define extreme-value-c
    (lambda (pred)
        (lambda args
            (cond
                ((null? args) (error "At least one argument is required"))
                (else
                    (letrec
                        ((helper (lambda (a*)
                            (cond
                                ((= (length a*) 1) (car a*))
                                (pred
                                    (car a*)
                                    (helper (cdr a*))
                                )
                            )
                        )))

                        (helper args)
                    )
                )
            )
        )
    )
)

(define rmax
    (lambda (x y)
        ((extreme-value-c r>) x y)
    )
)

(define rmin
    (lambda (x y)
        ((extreme-value-c r<) x y)
    )
)

(define between?
    (lambda (x y z)
        (and
            (> y x)
            (< y z)
        )
    )
)

(define between?-c
    (lambda (x)
        (lambda (y)
            (lambda (z)
                (between? x y z)
            )
        )
    )
)

(define andmap-c
    (lambda (pred)
        (letrec
            ((and-help (lambda (ls)
                (cond
                    ((null? ls) #t)
                    (else
                        (and
                            (pred (car ls))
                            (and-help (cdr ls))
                        )
                    )
                )
            )))

            and-help
        )
    )
)

(define is-divisible-by?
    (lambda (n)
        (lambda (k)
            (zero? (remainder n k))
        )
    )
)

(define prime?
    (lambda (n)
        (cond
            ((or (= n 2) (= n 3)) #t)
            ((or (even? n) (< n 2)) #f)
            (else
                (letrec*
                    (
                        (square-root (exact (floor (sqrt n))))
                        (x (if (even? square-root) (1- square-root) square-root))
                        (is-divisible-by-n? (is-divisible-by? n))
                        (helper (lambda (x)
                            (cond
                                ((= x 1) #t)
                                ((is-divisible-by-n? x) #t)
                                (else (helper (- x 2)))
                            )
                        ))
                    )

                    (helper x)
                )
            )
        )
    )
)
