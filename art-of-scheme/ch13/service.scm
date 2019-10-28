(load "ch12/counter.scm")
(load "ch12/acc.scm")

(define service-maker
    (lambda (full-or-self profit)
        (let
            (
                (number-of (counter-maker 0 1+))
                (total-wait (accumulator-maker 0 +))
                (max-wait (accumulator-maker 0 max))
                (total-profit (accumulator-maker 0 +))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "service")
                    ((number-of!) (send number-of 'update!))
                    ((total-wait!) (send total-wait 'update! (2nd msg)))
                    ((max-wait!) (send max-wait 'update! (2nd msg)))
                    ((total-profit!)
                        (send total-profit 'update! (* profit (2nd msg)))
                    )
                    ((report) (for-effect-only
                        (report full-or-self
                            (send number-of 'show)
                            (send total-wait 'show)
                            (send max-wait 'show)
                            (send total-profit 'show)
                        )
                    ))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define report
    (let
        ((show-line (lambda (a b)
            (display a)
            (display b)
            (newline)
        )))
        (lambda (full-or-self num-cust total-wait max-wait profit)
            (if (zero? num-cust)
                (writeln "There were no " full-or-self "-Service customers.")
                (begin
                    (show-line full-or-self "-Service: ")
                    (show-line "  The number of customers is " num-cust)
                    (show-line "  The average wait is " (round (/ total-wait num-cust)))
                    (show-line "  The maximum wait is " max-wait)
                    (show-line "  The total profit is " profit)
                )
            )
        )
    )
)
