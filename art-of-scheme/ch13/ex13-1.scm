(load "ch13/simulation.scm")

(define odds-evens
    (lambda (num-tries)
        ; head >= 0.5
        ; tail < 0.5
        (letrec*
            (
                (is-head? (lambda (x)
                    (>= x 0.5)
                ))
                (is-tail? (lambda (x)
                    (not (is-head? x))
                ))
                (is-even? (lambda (c1 c2)
                    (or
                        (and (is-head? c1) (is-tail? c2))
                        (and (is-head? c2) (is-tail? c1))
                    )
                ))
                (loop (lambda (tries evens odds)
                    (let ((coin-1 (unif-rand-var-0-1)) (coin-2 (unif-rand-var-0-1)))
                        (cond
                            ((zero? tries) (list evens odds))
                            ((is-even? coin-1 coin-2) (loop (1- tries) evens (1+ odds)))
                            (else (loop (1- tries  ) (1+ evens) odds))
                        )
                    )
                ))
            )
            (loop num-tries 0 0)
        )
    )
)
