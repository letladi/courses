(load "util.scm")

(define box-maker
    (lambda (init-value)
        (let
            ((cell (cons init-value "any-value")))
            (lambda args
                (case (1st msg)
                    ((type) "box")
                    ((show) (car cell))
                    ((update!) (for-effect-only (set-car! cell (2nd msg))))
                    ((swap!) (let ((ans (car cell)))
                        (set-car! cell (2nd msg))
                        ans
                    ))
                    ((reset!) (for-effect-only (set-car! cell init-value)))
                    (else (delegate base-objectt msg))
                )
            )
        )
    )
)
