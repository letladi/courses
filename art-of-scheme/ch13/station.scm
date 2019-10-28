(load "ch7/curry.scm")
(load "ch13/pump.scm")

(define station-maker
    (let
        (
            (check (lambda (p) (send p 'check)))
            (all-empty? (andmap-c (lambda (p) (send p 'empty?))))
            (shorter (lambda (p1 p2)
                (if (< (send p1 'size) (send p2 'size)) p1 p2)
            ))
        )

        (lambda (%-self self-serv full-serv extra-time-self extra-time-full pump-rate)
            (let
                (
                    (selfs (list
                        (pump-maker extra-time-self pump-rate self-serv)
                        (pump-maker extra-time-self pump-rate self-serv)))
                    (fulls (list
                        (pump-maker extra-time-full pump-rate full-serv)
                        (pump-maker extra-time-full pump-rate full-serv)
                    ))
                )

                (lambda msg
                    (case (1st msg)
                        ((type) "station")
                        ((report) (send self-serv 'report) (send full-serv 'report))
                        ((which-serve)
                            (let ((pump (apply shorter (if (< (random 100) %-self) selfs fulls))))
                                (send pump 'enqueue! (2nd msg))
                            )
                        )
                        ((all-empty?) (and (all-empty? selfs) (all-empty? fulls)))
                        ((serve) (for-each check selfs) (for-each check fulls))
                        (else (delegate base-object msg))
                    )
                )
            )
        )
    )
)
