(load "util.scm")
(load "ch12/box.scm")

(define queue-maker
    (lambda ()
        (let
            ((q '()))
            (lambda msg
                (case (1st msg)
                    ((type) "queue")
                    ((empty?) (null? q))
                    ((enqueue!)
                        (for-effect-only
                            (let
                                ((list-of-item (cons (2nd msg) '())))
                                (if (null? q)
                                    (set! q list-of-item)
                                    (append! q list-of-item)
                                )
                            )
                        )
                    )
                    ((front) (if (null? q)
                        (throw "front: the queue is empty.")
                        (car q)
                    ))
                    ((dequeue!)
                        (for-effect-only
                            (if (null? q)
                                (throw "dequeue!: The queue is empty.")
                                (set! q (cdr q))
                            )
                        )
                    )
                    ((size) (length q))
                    ((print)
                        (display "FRONT: ")
                        (for-each
                            (lambda (x) (display x) (display " "))
                            q
                        )
                        (newline)
                    )
                    (else (delegate base-object msg))
                )
            )
        )
    )
)
