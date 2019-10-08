(load "ch11/vector-memoize.scm")
(load "ch11/memoize.scm")

(define pascal-triangle
    (lambda (row col)
        (let
            ((out-of-range? (lambda (n k)
                (or
                    (negative? n)
                    (negative? k)
                    (and (zero? n) (not (zero? k)))
                    (> k n)
                )
            )))

            (cond
                ((out-of-range? row col) 0)
                ((or
                    (and (zero? row) (zero? col))
                    (and (zero? row) (zero? col))
                    (and (zero? row) (= col 1))
                ) 1)
                (else
                    (+
                        (pascal-triangle (1- row) (1- col))
                        (pascal-triangle (1- row) col)
                    )
                )
            )
        )
    )
)

(define nano-to-millis
    (lambda (t)
        (/ t 1000000.0)
    )
)

(define time-diff
    (lambda (x y type)
        (let
            ((diff (time-difference x y)))
            (cond
                ((or (string=? type "s"))
                    (time-second diff)
                )
                ((or (string=? type "ns"))
                    (time-nanosecond diff)
                )
                ((or (string=? type "ms"))
                    (/ (time-nanosecond diff) 1000000.0)
                )
            )
        )
    )
)

(define timer2
    (lambda (proc a b)
        (let
            (
                (start (current-time))
                (diff 0)
                (end 0)
            )
            (proc a b)
            (set! end (current-time))
            (set! diff (time-diff end start "s"))

            (display "took ")
            (cond
                ((zero? diff)
                    (display (time-diff end start "ms"))
                    (display " milliseconds\n")
                )
                (else
                    (display diff)
                    (display " seconds\n")
                )
            )
        )
    )
)

(define factorial
    ((vector-memoize 100)
        (lambda (n)
            (if (zero? n)
                1
                (* n (factorial (1- n)))
            )
        )
    )
)

(define combinations
    (lambda (n k)
        (quotient
            (factorial n)
            (*
                (factorial k)
                (factorial(- n k))
            )
        )
    )
)

(define lookup2
    (lambda (obj1 obj2 trilist cb err-cb)
        (if (null? trilist)
            (err-cb)
            (let
                (
                    (first (car trilist))
                    (rest (cdr trilist))
                )
                (cond
                    ((and
                        (equal? obj1 (1st first))
                        (equal? obj2 (2nd first)))
                            (cb first)
                    )
                    (else
                        (lookup2 obj1 obj2 rest cb err-cb)
                    )
                )
            )
        )

    )
)
