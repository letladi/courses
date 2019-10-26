(load "util.scm")
(load "ch12/gauge.scm")

(define circular-list-maker
    (lambda ()
        (letrec
            (
                (marker '())
                (size-gauge (gauge-maker 0 1+ 1-))
                (reverse-help (lambda (ls res)
                    (cond
                        ((null? ls) res)
                        (else
                            (reverse-help
                                (cdr ls)
                                (cons (car ls) res)
                            )
                        )
                    )
                ))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "circular list")
                    ((empty?) (null? marker))
                    ((insert!)
                        (send size-gauge 'up!)
                        (for-effect-only
                            (if (null? marker)
                                (begin
                                    (set! marker (cons (2nd msg) '()))
                                    (set-cdr! marker marker)
                                )
                                (set-cdr! marker (cons (2nd msg) (cdr marker)))
                            )
                        )
                    )
                    ((head) (if (null? marker)
                        (throw "head: the list is empty.")
                        (car (cdr marker))
                    ))
                    ((delete!) (for-effect-only
                        (if (null? marker)
                            (throw "delete: The circular list is empty.")
                            (begin
                                (send size-gauge 'down!)
                                (if (eq? marker (cdr marker))
                                    (set! marker '())
                                    (set-cdr! marker (cdr (cdr marker)))
                                )
                            )
                        )
                    ))
                    ((move!) (for-effect-only
                        (if (null? marker)
                            (throw "move!: The circular list is empty.")
                            (set! marker (cdr marker))
                        )
                    ))
                    ((size) (send size-gauge 'show))
                    ((print)
                        (if (not (null? marker))
                            (let ((next (cdr marker)))
                                (set-cdr! marker '())
                                (for-each
                                    (lambda (x) (display x) (display " "))
                                    next
                                )
                                (set-cdr! marker next)
                            )
                        )
                        (newline)
                    )
                    ((reverse)
                        (if (not (null? marker))
                            (for-effect-only
                                (let ((next (cdr marker)))
                                    (set-cdr! marker '())
                                    (set-cdr! marker (reverse-help next '()))
                                )
                            )
                        )
                    )
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define stack-maker
    (lambda ()
        (let
            ((c (circular-list-maker)))
            (lambda msg
                (case (1st msg)
                    ((type) "stack")
                    ((push!) (send c 'insert! (2nd msg)))
                    ((pop!) (send c 'delete!))
                    ((top) (send c 'head))
                    ((print) (display "TOP: ") (send c 'print))
                    ((insert! head delete! move!) (delegate base-object msg))
                    (else (delegate c msg))
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
                    ((enqueue!) (send c 'insert! (2nd msg)) (send c 'move!))
                    ((dequeue!) (send c 'delete!))
                    ((front) (send c 'head))
                    ((print) (display "FRONT: ") (send c 'print))
                    ((insert! head delete! move!) (delegate base-object msg))
                    (else (delegate c msg))
                )
            )
        )
    )
)