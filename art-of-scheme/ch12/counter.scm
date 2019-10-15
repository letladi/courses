(load "ch12/box.scm")
(load "ch12/acc.scm")

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

; ex 12.8
(define counter-maker
    (lambda (init-value unary-proc)
        (let
            ((total (accumulator-maker init-value (lambda (ac val)
                (unary-proc val)
            ))))
            (lambda msg
                (case (1st msg)
                    ((type) "counter")
                    ((update!)
                        (let
                            ((result (unary-proc)))
                        )
                    )
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

(define modified-restricted-counter-maker
    (lambda (init-value unary-proc pred reset-proc)
        (let
            ((total (box-maker init-value)))

            (lambda msg
                (case (1st msg)
                    ((type) "modified-restricted-counter")
                    ((update!)
                        (let*
                            (
                                (res (unary-proc (send total 'show)))
                                (can-update? (pred res))
                            )
                            (if can-update?
                                (send total 'update! res)
                                (send total 'update! (reset-proc))
                            )
                        )
                    )
                    ((show) (send total 'show))
                    ((reset) (send total))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define clock-maker
    (lambda (hr min)
        (let
            (
                (hr-pred (lambda (h) (and (>= h 1) (<= h 12))))
                (min-pred (lambda (m) (and (>= m 0) (<= m 59))))
            )
            (if (not (hr-pred hr))
                (throw "the hour value may only be between 1 and 12")
            )
            (if (not (min-pred min))
                (throw "the minute value may only be between 0 and 59")
            )

            (letrec*
                (
                    (hr-hand
                        (restricted-counter-maker
                            1
                            (lambda (h) (1+ h))
                            hr-pred
                        )
                    )
                    (min-hand
                        (modified-restricted-counter-maker
                            min
                            (lambda (m) (1+ m))
                            min-pred
                            (lambda ()
                                (send hr-hand 'update!)
                                0
                            )
                        )
                    )
                    (catch-up-clock (lambda (time-obj up-bound)
                        (if (< (send time-obj 'show) up-bound)
                            (begin
                                (send time-obj 'update!)
                                (catch-up-clock time-obj up-bound)
                            )
                        )
                    ))
                )

                (catch-up-clock hr-hand hr)

                (lambda msg
                    (case (1st msg)
                        ((type) "clock-maker")
                        ((update!)
                            (send min-hand 'update!)
                        )
                        ((show)
                            (string-append
                                (number->string (send hr-hand 'show))
                                ":"
                                (number->string (send min-hand 'show))
                            )
                        )
                        ((reset!)
                            (send hr-hand 'reset!)
                            (send min-hand 'reset!)
                        )
                        (else (delegate base-object msg))
                    )
                )
            )
        )
    )
)
