(define unif-rand-var-0-1
    (let ((big 1000000.0))
        (lambda ()
            (/ (+ 1 (random big)) big)
        )
    )
)

(define exponential-random-variable
    (lambda (mean)
        (* mean (- (log (unif-rand-var-0-1))))
    )
)

(define arrival-time-generator
    (lambda (av-arr-time)
        (+ 1 (round (exponential-random-variable (- av-arr-time 1))))
    )
)

(define normal-random-variable
    (lambda (mean std-dev)
        (letrec
            ((compute (lambda (i)
                (if (zero? i)
                    0
                    (+ (- (unif-rand-var-0-1) 0.5)
                        (compute (1- i))
                    )
                )
            )))
            (+ mean (* std-dev (compute 12)))
        )
    )
)

(define gallons-generator
    (lambda ()
        (max 1 (round (normal-random-variable 12 4)))
    )
)
