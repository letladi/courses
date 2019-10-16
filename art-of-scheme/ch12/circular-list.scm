(define circular-list-marker
    (lambda ()
        (let
            (
                (marker '())
                (size-gauge (gauge-maker 0 1+ 1-))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "circular list")
                    ((empty?) (null? marker))
                    ((insert!) (send size-gauge 'up!))
                )
            )
        )
    )
)
