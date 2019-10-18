(load "util.scm")
(load "ch12/gauge.scm")

(define stack-maker
    (lambda ()
        (let
            ((c (circular-list-maker)))
            (lambda msg
                (case (1st msg)
                    ((type) "stack")
                    ((size) (send c 'size))
                    ((push!) (send c 'insert! (2nd msg)))
                    ((pop!) (send c 'delete!))
                    ((top) (send c 'head))
                    ((print) (display "TOP: ") (send c 'print))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define queue-maker
    (lambda ()
        (let
            ((c (circular-list-maker)))
            (lambda msg
                (case (1st msg)
                    ((type) "queue")
                    ((enqueue!) (send c 'insert! (2nd msg)) (send 'move!))
                    ((dequeue!) (send c 'delete!))
                    ((front) (send c 'head))
                    ((print) (display "FRONT: ") (send c 'print))
                    ((size) (send c 'size))
                    (else (delegate base-object msg))
                )
            )
        )
    )
)
