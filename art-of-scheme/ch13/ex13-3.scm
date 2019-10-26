(load "ch12/bucket.scm")

(define random-number
    (lambda (m a seed)
        (lambda (n)
            (let ((u (/ seed m)))
                (set! seed (modulo (* a seed) m))
                (floor (* n u))
            )
        )
    )
)

(define random-time (lambda () (time-nanosecond (current-time))))

(define random (random-number (- (expt 2 31) 1) (expt 7 5) (random-time)))

(define range-counter
    (lambda (num-to-gen divisions)
        (letrec*
            (
                (part-len (/ 100 divisions))
                (get-range-string (lambda (n)
                    (letrec
                        ((get-range-min (lambda (x)
                            (cond
                                ((zero? (remainder x part-len)) x)
                                (else (get-range-min (1- x)))
                            )
                        )))
                        (cond
                            ((zero? (remainder n part-len))
                                (if (zero? n)
                                    (string-append "0 - " (number->string part-len))
                                    (string-append
                                        (number->string n) " - " (number->string (+ n part-len))
                                    )
                                )
                            )
                            (else
                                (let ((range-min (get-range-min n)))
                                    (string-append
                                        (number->string range-min) " - "
                                        (number->string (+ range-min part-len))
                                    )
                                )
                            )
                        )
                    )
                ))
                (generate-numbers (lambda (gen-count numbers-bucket)
                    (cond
                        ((zero? gen-count) numbers-bucket)
                        (else
                            (let ((num (random 100)))
                                (send numbers-bucket 'update!
                                    (get-range-string num)
                                    1+
                                    (lambda (s) 1)
                                )
                                (generate-numbers (1- gen-count) numbers-bucket)
                            )
                        )
                    )
                ))
            )
            (cond
                ((zero? (remainder part-len 5))
                    (let
                        ((nums (generate-numbers num-to-gen (bucket-maker))))
                        (send nums 'image)
                    )
                )
                (else
                    (throw
                        (string-append
                            (number->string divisions)
                            " does not divide 100 into equal integer parts."
                            " Please choose another number."
                        )
                    )
                )
            )
        )
    )
)
