(load "util.scm")

(define lookup
    (lambda (obj table success-proc failure-proc)
        (letrec
            ((lookup (lambda (table)
                (if (null? table)
                    (failure-proc)
                    (let
                        ((pr (car table)))
                        (if (equal? (car pr) obj)
                            (success-proc pr)
                            (lookup (cdr table))
                        )
                    )
                )
            )))

            (lookup table)
        )
    )
)

(define assoc
    (lambda (obj table)
        (lookup obj table (lambda (pr) pr) (lambda () #f))
    )
)

(define memoize
    (lambda (proc)
        (let
            (
                (table '())
            )
            (lambda (arg)
                (lookup arg table
                    (lambda (pr) (cdr pr))
                    (lambda ()
                        (let
                            ((val (proc arg)))
                            (set! table (cons (cons arg val) table))
                            val
                        )
                    )
                )
            )
        )
    )
)

(define fib
    (lambda (n)
        (if (< n 2)
            n
            (+
                (fib (- n 1))
                (fib (- n 2))
            )
        )
    )
)

(define fib-m (memoize fib))

(define memo-fib
    (memoize (lambda (n)
        (if (< n 2)
            n
            (+
                (memo-fib (- n 1))
                (memo-fib (- n 2))
            )
        )
    ))
)
