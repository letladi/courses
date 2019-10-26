(load "ch12/box.scm")

(define send
    (lambda args
        (let ((try (apply (car args) args)))
            (if (eq? invalid-method-name-indicator try)
                (let ((object (car args)) (message (cdr args)))
                    (throw
                        (string-append
                            "Bad method name: "
                            (car message)
                            " sent to object of "
                            (object object 'type)
                            " type."
                        )
                     )
                )
                try
            )
        )
    )
)

(define counter-maker
    (lambda (init-val unary-proc)
        (let ((total (box-maker init-val)))
            (lambda message
                (let ((self (car message)) (msg (cdr message)))
                    (case (1st msg)
                        ((type) "counter")
                        ((update!) (let ((result (unary-proc (send total 'show))))
                            (send total 'update! result)
                        ))
                        ((swap!) (delegate base-object message))
                        (else (delegate total message))
                    )
                )
            )
        )
    )
)

(define box-maker
    (lambda (init-val)
        (let
            ((contents init-val))
            (lambda message
                (let ((self (car message)) (msg (cdr message)))
                    (case (1st msg)
                        ((type) "box")
                        ((show) contents)
                        ((update!) (for-effect-only (set! contents (2nd msg))))
                        ((swap!) (let ((ans contents))
                            (set! contents (2nd msg))
                            ans
                        ))
                        ((reset!) (for-effect-only (set! contents init-val)))
                        (else (delegate base-object message))
                    )
                )
            )
        )
    )
)

(define base-object
    (lambda msg
        (case (2nd msg)
            ((type) "base-object")
            (else invalid-method-name-indicator)
        )
    )
)
