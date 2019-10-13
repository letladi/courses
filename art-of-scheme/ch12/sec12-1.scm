(load "ch12/acc.scm")

(define acc-max (accumulator-maker 0 max))

; ex 12.1
; (send acc-max 'update! 3)
; (send acc-max 'update! 7)
; (send acc-max 'update! 2)
; (send acc-max 'update! 4)
; (send acc-max 'update! 10)
; (send acc-max 'update! 1)
; (send acc-max 'update! 5)
; (display (send acc-max 'show))
; 3, 7, 2, 4, 10, 1, 5

(define double-box-maker
    (lambda (init-left init-right)
        (let*
            (
                (left-box (box-maker init-left))
                (right-box (box-maker init-right))
                (getbox-msg (lambda (db-msg)
                    (case db-msg
                        ((show-left "show-left" show-right "show-right") 'show)
                        ((update-left! "update-left!" update-right! "update-right!") 'update!)
                        ((reset! "reset!") 'reset!)
                        (else db-msg)
                    )
                ))
                (get-box (lambda (db-msg)
                    (case db-msg
                        ((show-left "show-left" update-left! "update-left!") left-box)
                        ((show-right "show-right" update-right! "update-right!") right-box)
                        (else #f)
                    )
                ))
            )
            (lambda msg
                (let*
                    (
                        (mthd (1st msg))
                        (box-to-use (get-box mthd))
                        (method-to-call (getbox-msg mthd))
                        (call-args (cons box-to-use (cons method-to-call (cdr msg))))
                    )
                    (case mthd
                        ((reset!)
                            (apply send left-box (list 'reset!))
                            (apply send right-box (list 'reset!))
                        )
                        (else
                            (if box-to-use
                                (apply send call-args)
                                (apply delegate (cons base-object msg))
                            )
                        )
                    )
                )
           )
        )
    )
)

(define accumulator-maker
    (lambda (init-value binary-proc)
        (let
            ((total (box-maker init-value)))

            (lambda msg
                (case (1st msg)
                    ((type) "accumulator")
                    ((update!) (send total 'update! (binary-proc (send total 'show) (2nd msg))))
                    ((show) (send total 'show))
                    ((reset!) (send total 'reset!))
                    (else (delegate total msg))
                )
            )
        )
    )
)

(define gauge-maker
    (lambda (init-value unary-proc-up unary-proc-down)
        (let
            ((total (box-maker init-value)))
            (lambda msg
                (case (1st msg)
                    ((type) "gauge")
                    ((up!) (send total 'update! (unary-proc-up (send total 'show))))
                    ((down!) (send total 'update! (unary-proc-down (send total 'show))))
                    ((show) (send total 'show))
                    ((reset!) (send total 'reset!))
                    (else (delegate total msg))
                )
            )
        )
    )
)
