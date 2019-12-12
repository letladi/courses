(letrec
    (
        [f (lambda (x k) (k (cons 'a x)))]
        [g (lambda (x k) (f x (lambda (v) (k (cons 'b v)))))]
        [h (lambda (x k) (g (cons 'c x) k))]
    )
    (h '() (lambda (v) (cons 'd v)))
)

(define integer-divide
    (lambda (x y success failure)
        (if (= y 0)
            (failure "divide by zero")
            (let ([q (quotient x y)])
                (success q (- x (* q y)))
            )
        )
    )
)
