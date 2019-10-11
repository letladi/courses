(load "ch12/box.scm")

(define counter-maker
    (lambda (init-value unary-proc)
        (let
            ((total (box-maker init-value)))
            (lambda msg
                (case (1st msg)
                    ((type) "counter")
                    ((update!)
                        (let
                            ((result (unary-proc (send total 'show))))
                            (send total 'update! result)
                        )
                    )
                    ((swap!) (delegate base-object msg))
                    (else (delegate total msg))
                )
            )
        )
    )
)
