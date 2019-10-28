(load "ch13/station.scm")
(load "ch13/service.scm")
(load "ch13/random.scm")
(load "ch13/customer.scm")

(define simulation-setup&run
    (lambda (close-time %-self-service av-arr-time profit-self profit-full extra-time@self-pump extra-time@full-pump pump-rate)
        (let
            (
                (self-service (service-maker "Self" profit-self))
                (full-service (service-maker "Full" profit-full))
            )
            (simulation
                (station-maker
                    %-self-service
                    self-service
                    full-service
                    extra-time@self-pump
                    extra-time@full-pump
                    pump-rate
                )
                (counter-maker 0 1+)
                av-arr-time
                (* 60 close-time)
            )
        )
    )
)

(define simulation
    (lambda (station clock av-arr-time close-time)
        (let
            ((arrival (box-maker (+ (send clock 'show)
                (arrival-time-generator av-arr-time)
            ))))
            (letrec
                (
                    (loop (lambda ()
                        (if (= (send clock 'show) close-time)
                            (prepare-for-closing)
                            (begin
                                (if (= (send clock 'show) (send arrival 'show))
                                    (begin
                                        (send station 'which-serve
                                            (customer-maker (send arrival 'show) clock)
                                        )
                                        (send station 'serve)
                                        (send arrival 'update!
                                            (+ (send clock 'show) (arrival-time-generator av-arr-time)))
                                        (send clock  'update!)
                                    )
                                    (begin
                                        (send station 'serve)
                                        (send clock 'update!)
                                    )
                                )
                                (loop)
                            )
                        )
                    ))
                    (prepare-for-closing (lambda ()
                        (if (send station 'all-empty?)
                            (send station 'report)
                            (begin
                                (send station 'serve)
                                (send clock 'update!)
                                (prepare-for-closing)
                            )
                        )
                    ))
                )

                (loop)
            )
        )
    )
)
