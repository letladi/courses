; ex3.2.1
; 'sum' is not tail recursive
; 'list?' is tail recursive
; the first 'factorial' function is not tail recursive
; the second 'factorial' function is tail recursive
; the first 'fibonacci' function is not tail recursive
; the second 'fibonacci' function is tail recursive
; factor is not tail recursive

; ex3.2.2
; I prefer the letrec version of factor, this is just more intuitive to me
(define factor
    (lambda (n)
        (letrec
            ((f (lambda (n i res)
                (cond
                    [(>= i n) (cons n res)]
                    [(integer? (/ n i)) (f
                        (/ n i)
                        i
                        (cons i res)
                    )]
                    [else (f n (1+ i) res)]
                )
            )))

            (f n 2 '())
        )
    )
)

; ex3.2.3
; No it cannot be written using `letrec` because because in a `let` expressions
; to the right cannot refer to expressions to the left.
; (let even? ([x 20])
;     (or (= x 0)
;         (let odd? ([x (1- x)])
;             (and (not (= x 0))
;                 (even? (1- x))
;             )
;         )
;     )
; )
; => Turns out it is possible. 🤦🏾‍♂️

; ex3.2.4
; (define fibonacci
;     (lambda (n)
;         (if (= n 0)
;             0
;             (trace-let fib ([i n] [a1 1] [a2 0] [count 0])
;                 (if (= i 1)
;                     (list a1 count)
;                     (fib (1- i) (+ a1 a2) a1 (1+ count))
;                 )
;             )
;         )
;     )
; )

; (define fibonacci
;   (lambda (n)
;     (trace-let fib ([i n])
;       (cond
;         [(= i 0) 0]
;         [(= i 1) 1]
;         [else (+ (fib (- i 1)) (fib (- i 2)))]))))


; ex3.2.5
(define let2
    (syntax-rules ()
        [(_ ((x e) ...) b1 b2 ...)
            ((lambda (x ...) b1 b2 ...) e ...)
        ]
        [(_ fn-name ((x expr) ...) b1 b2 ...)
            (letrec
                [(fn-name (lambda (x ...)
                    b1 b2 ...
                ))]
                (fn-name expr ...)
            )
        ]
    )
)

(define fibonacci
    (lambda (n)
        (if (= n 0)
            0
            (let2 fib ([i n] [a1 1] [a2 0] [count 0])
                (if (= i 1)
                    (list a1 count)
                    (fib (1- i) (+ a1 a2) a1 (1+ count))
                )
            )
        )
    )
)

; ex3.2.7 This version of `or` is not correct because it does not properly terminate
; That is to say it does not have a base case for when there is only one expression.
