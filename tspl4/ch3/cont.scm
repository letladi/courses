(define product
    (lambda (ls)
        (call/cc
            (lambda (break)
                (let f ([ls ls])
                    (cond
                        [(null? ls) 1]
                        [(= (car ls) 0) (break 0)]
                        [else (* (car ls) (f (cdr ls)))]
                    )
                )
            )
        )
    )
)

(define retry #f)

(define factorial
    (lambda (x)
        (if (= x 0)
            (call/cc (lambda (k) (set! retry k) 1))
            (* x (factorial (1- x)))
        )
    )
)
