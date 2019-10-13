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

(define restricted-counter-maker
    (lambda (init-value unary-proc pred)
        (let
            ((total (box-maker init-value)))

            (lambda msg
                (case (1st msg)
                    ((type) "restricted-counter")
                    ((update!)
                        (let*
                            (
                                (res (unary-proc (send total 'show)))
                                (can-update? (pred res))
                            )
                            (if can-update?
                                (send total 'update! res)
                                (send total 'reset!)
                            )
                        )
                    )
                    ((show) (send total 'show))
                    ((reset!) (send total 'reset!))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define clock
    (restricted-counter-maker
        1
        (lambda (n) (1+ n))
        (lambda (n) (and (>= n 1) (<= n 12)))
    )
)
