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
                    (else (delegate ticket-line msg))
                )
            )
    )
)

; 12-29
