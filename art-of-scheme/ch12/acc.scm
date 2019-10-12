(load "ch12/box.scm")

(define accumulator-maker
    (lambda (init-value binary-proc)
        (let
            ((total (box-maker init-value)))
            (lambda msg
                (case (1st msg)
                    ((type) "accumulator")
                    ((update!) (send total 'update! (binary-proc (send total 'show) (2nd msg))))
                    ((swap!) (delegate base-object msg))
                    (else (delegate total msg))
                )
            )
        )
    )
)
