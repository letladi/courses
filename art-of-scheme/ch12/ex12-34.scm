(load "ch12/ex12-33.scm")

(define cartesian-point-maker
    (lambda (x-coord y-coord)
        (lambda message
            (let ((self (car message)) (msg (cdr message)))
                (case (1st msg)
                    ((type) "Cartesian point")
                    ((distance) (sqrt (+ (square x-coord) (square y-coord))))
                    ((closer?) (< (send self 'distance) (send (2nd msg) 'distance)))
                    (else (delegate base-object message))
                )
            )
        )
    )
)
