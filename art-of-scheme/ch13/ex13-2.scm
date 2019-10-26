(load "ch12/bucket.scm")

(define license-plate-bet
    (lambda (num-tries)
        (letrec
            (
                (b (bucket-maker))
                (loop (lambda (try-count)
                    (cond
                        ((zero? try-count) (send b 'image))
                        (else
                            (let
                                ((plate-num (random 100)))
                                (send b 'update! plate-num 1+ (lambda (s) 1))
                                (loop (1- try-count))
                            )
                        )
                    )
                ))
            )
            (loop num-tries)
        )
    )
)
