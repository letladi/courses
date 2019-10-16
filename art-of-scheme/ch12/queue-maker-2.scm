(load "util.scm")
(load "ch12/case.scm")
(load "ch12/box.scm")

(define queue-maker
    (lambda ()
        (let
            ((q (cons '() '())))
            (letrec*
                (
                    (rear q)
                    (add-items-to-queue (lambda (ls)
                        (if (not (null? ls))
                            (let
                                ((list-of-item (cons (1st ls) '())))
                                (set-cdr! rear list-of-item)
                                (set! rear list-of-item)
                                (add-items-to-queue (cdr ls))
                            )
                        )
                    ))
                )
                (lambda msg
                    (case (1st msg)
                        ((type) "queue")
                        ((empty?) (eq? rear q))
                        ((enqueue!) (for-effect-only
                            (add-items-to-queue (list (2nd msg)))
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
                                (add-items-to-queue (2nd msg))
                            )
                        )
                        ((enqueue-many!)
                            (for-effect-only
                                (add-items-to-queue (cdr msg))
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

; ex12.12
(define queue->list
    (lambda (q)
        (letrec*
            (
                (sentinel (list "sentinel" (random 100)))
                (loop (lambda (que)
                    (let
                        ((front (send que 'front)))
                        (cond
                            ((eq? front sentinel)
                                (send que 'dequeue!)
                                '()
                            )
                            (else
                                (send que 'enqueue! front)
                                (send que 'dequeue!)
                                (cons
                                    front
                                    (loop que)
                                )
                            )
                        )
                    )
                ))
            )
            (send q 'enqueue! sentinel)
            (loop q)
        )
    )
)

(define queue->list!
    (lambda (q)
        (if (zero? (send q 'size))
            '()
            (let
                ((front (send q 'front)))
                (send q 'dequeue!)
                (cons front (queue->list! q))
            )
        )
    )
)

; ex12.14 if the code is replaced with '(append q list-of-item)', then the code becomes
; more inefficient because we have to create a new list to append to instead of modifying our
; existing list.
; If, on the other hand, we use '(set! q (append q list-of-item))' the efficiency is the same, the only
; difference being that we know re-assign our 'q' variable.
