(load "ch12/circular-list.scm")

(define theater-maker
    (lambda (capacity)
        (let
            (
                (ticket-line (queue-maker))
                (vacancies (gauge-maker capacity 1+ 1-))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "theater")
                    ((enter!) (if (zero? (send vacancies 'show))
                        (display "doors closed")
                        (begin
                            (send ticket-line 'dequeue!)
                            (send vacancies 'down!)
                        )
                    ))
                    ((leave!) (if (< (send vacancies 'show) capacity)
                        (send vacancies 'up!)
                        (throw "leave!: The theater is empty.")
                    ))
                    (else (delegate (combine ticket-line vacancies) msg))
                )
            )
    )
)

; 12-29
; The advantage of using 'delegate' inside theater-maker is we sidestep the need to redefine messages
; already defined on the queue, which we use to store the incoming patrons
; The disadvantage is that the user of the 'theater-maker' gets to use the 'queue' directly, which
; to use some jargon; breaks encapsulation.

; 12-30
; We must include the extra message because our delegation goes to the queue instead
; of the gauge (from which we need the data)

(define combine
    (lambda (f g)
        (lambda msg
            (let ((f-try (delegate f msg)))
                (if (eq? invalid-method-name-indicator f-try)
                    (delegate g msg)
                    f-try
                )
            )
        )
    )
)

(define combine
    (lambda funcs
        (letrec
            ((loop (lambda (func-ls current-invocation-result msg)
                (cond
                    ((null? func-ls) current-invocation-result)
                    (else
                        (let
                            ((f (car func-ls)) (func-rest (cdr func-ls)))
                            (if (eq? invalid-method-name-indicator current-invocation-result)
                                (loop (cdr func-ls) (delegate f msg) msg)
                                current-invocation-result
                            )
                        )
                    )
                )
            )))

            (lambda msg
                (loop (cdr funcs) (delegate (car funcs) msg) msg)
            )
        )
    )
)

; ex12-31
