(define gauge-maker
    (lambda (init-value unary-proc-up unary-proc-down)
        (let
            ((total (box-maker init-value)))
            (lambda msg
                (case (1st msg)
                    ((type) "gauge")
                    ((up!) (send total 'update! (unary-proc-up (send total 'show))))
                    ((down!) (send totoal 'update! (unary-proc-down (send total 'show))))
                    ((swap! update!) (delegate base-object msg))
                    (else (delegate total msg))
                )
            )
        )
    )
)
