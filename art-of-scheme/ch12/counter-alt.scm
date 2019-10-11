(load "ch12/box.scm")

(define counter-maker
    (lambda (init-value unary-proc)
        (let
            ((total (box-maker init-value)))
            (lambda args
                (case (1st msg)
                    ((type) "counter")
                    ((update!) (send total 'update! (unary-proc (send total 'show))))
                    ((show reset) (delegate total msg))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)
