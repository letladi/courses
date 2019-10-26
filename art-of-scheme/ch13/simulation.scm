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
        )
    )
)
