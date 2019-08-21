(define read-demo
    (lambda ()
        (display "Enter data (enter done when finished): ")
        (let ((response (read)))
            (cond
                ((eq? response 'done) (display "Thank you. Good-bye."))
                (else
                    (display "You entered: ")
                    (write response)
                    (newline)
                    (read-demo)
                )
            )
        )
    )
)

(define interactive-square-root
    (lambda ()
        (display "Enter the number whose square root you want, or enter done to quit:")
        (newline)
        (let ((n (read)))
            (if (eq? n 'done)
                (begin
                    (display "That's all, folks.")
                    (newline)
                )
                (begin
                    (display "The square root of ")
                    (display n)
                    (display " is ")
                    (display (round-n-places 4 (square-root n)))
                    (newline)
                    (interactive-square-root)
                )
            )
        )
    )
)
