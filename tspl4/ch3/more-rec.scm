(define fibonacci
    (lambda (n)
        (if (= n 0)
            0
            (let fib ([i n] [a1 1] [a2 0])
                (if (= i 1)
                    a1
                    (fib (1- i) (+ a1 a2) a1)
                )
            )
        )
    )
)

(define factor
    (lambda (n)
        (trace-let f ([n n] [i 2])
            (cond
                [(>= i n) (list n)]
                [(integer? (/ n i))
                    (cons i (f (/ n i) i))
                ]
                [else (f n (1+ i))]
            )
        )
    )
)
