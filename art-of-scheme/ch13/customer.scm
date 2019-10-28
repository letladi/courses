(load "ch13/random.scm")

(define customer-maker
    (lambda (arrival-time clock)
        (let ((gallons-pumped (gallons-generator)))
            (lambda msg
                (case (1st msg)
                    ((type) "customer")
                    ((gallons) gallons-pumped)
                    ((record)
                        (let
                            (
                                (service (2nd msg))
                                (wait (- (send clock 'show) arrival-time))
                            )
                            (send service 'number-of!)
                            (send service 'total-wait! wait)
                            (send service 'max-wait! wait)
                            (send service 'total-profit! gallons-pumped)
                    ))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)
