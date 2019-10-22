(load "util.scm")
(load "ch12/box.scm")

; redefining with local variable, that is not a gauge
(define circular-list-maker
    (lambda ()
        (let
            (
                (marker '())
                (count 0)
            )
            (lambda msg
                (case (1st msg)
                    ((type) "circular list")
                    ((empty?) (null? marker))
                    ((insert!)
                        (set! count (1+ count))
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
                            (throw "delete: the circular list is empty.")
                            (begin
                                (set! count (1- count))
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
                    ((size) count)
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
                    (else (delegate base-object msg))
                )
            )
        )

    )
)

; redefining with no local variables
(define circular-list-maker
    (lambda ()
        (let
            (
                (marker '())
            )
            (lambda msg
                (case (1st msg)
                    ((type) "circular list")
                    ((empty?) (null? marker))
                    ((insert!)
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
                            (throw "delete: the circular list is empty.")
                            (begin
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
                    ((size)
                        (if (null? marker)
                            0
                            (let
                                (
                                    (next (cdr marker))
                                    (len 0)
                                )
                                (set-cdr! marker '())
                                (set! len (length next))
                                (set-cdr! marker next)
                                len
                            )
                        )
                    )
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
                    (else (delegate base-object msg))
                )
            )
        )

    )
)
