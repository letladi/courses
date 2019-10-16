(load "util.scm")
(load "ch12/case.scm")
(load "ch12/box.scm")

(define queue-maker
    (lambda ()
        (let
            ((q (cons '() '())))
            (let
                ((rear q))
                (lambda msg
                    (case (1st msg)
                        ((type) "queue")
                        ((empty?) (eq? rear q))
                        ((enqueue!) (for-effect-only
                            (let
                                ((list-of-item (cons (2nd msg) '())))
                                (set-cdr! rear list-of-item)
                                (set! rear list-of-item)
                            )
                        ))
                        ((front) (if (eq? rear q)
                            (throw "front: The queue is empty.")
                            (car (cdr q))
                        ))
                        ((dequeue!) (for-effect-only
                            (if (eq? rear q)
                                (throw "dequeue!: The queue is empty.")
                                (let
                                    ((front-cell (cdr q)))
                                    (set-cdr! q (cdr front-cell))
                                    (if (eq? front-cell rear)
                                        (set! rear q)
                                    )
                                )
                            )
                        ))
                        ((size) (length (cdr q)))
                        ((print) (display "FRONT: ")
                            (for-each
                                (lambda (x) (display x) (display " "))
                                (cdr q)
                            )
                            (newline)
                        )
                        ((enqueue-list!)
                            (for-effect-only
                                (for-each
                                    (lambda (item)
                                        (let
                                            ((list-of-item (cons item '())))
                                            (set-cdr! rear list-of-item)
                                            (set! rear list-of-item)
                                        )
                                    )
                                    (2nd msg)
                                )
                            )
                        )
                        (else (delegate base-object msg))
                    )
                )
            )
        )
    )
)

; ex12.10. We don't append in the method 'enqueue-list!'. In addition to breaking current implementation,
; this would also make the queue inefficient.
