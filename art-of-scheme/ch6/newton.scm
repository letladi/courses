(define tolerance 0.000005)

(define close-enough?
    (lambda (u v)
        (< (abs (- u v)) tolerance)
    )
)

(define square-root
    (lambda (a)
        (letrec
            ((next-estimate (lambda (u)
                (let ((v (/ (+ u (/ a u)) 2.0)))
                    (if (close-enough? u v)
                        v
                        (next-estimate v)
                    )
                )
            )))

            (next-estimate 1)
        )
    )
)

(define square-root-display
    (lambda (a)
        (letrec ((next-estimate (lambda (u)
            (let ((v (/ (+ u (/ a u)) 2.0)))
                (if (close-enough? u v)
                    (begin
                        (newline)
                        v
                    )
                    (begin
                        (display v)
                        (display " ")
                        (next-estimate v)
                    )
                )
            )
        )))
        (next-estimate 1)
        )
    )
)

(define round-n-places
    (lambda (n dec-num)
        (let ((scale-factor (expt 10 n)))
            (/ (round (* dec-num scale-factor)) scale-factor)
        )
    )
)
