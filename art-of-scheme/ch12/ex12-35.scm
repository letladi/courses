(load "ch12/ex12-34.scm")

(define manhattan-point-maker
    (lambda (x-coord y-coord)
        (let ((p (cartesian-point-maker x-coord y-coord)))
            (lambda message
                (let ((self (car message)) (msg (cdr message)))
                    (case (1st msg)
                        ((type) "Manhattan point")
                        ((distance) (+ x-coord y-coord))
                        (else (delegate p message))
                    )
                )
            )
        )
    )
)
