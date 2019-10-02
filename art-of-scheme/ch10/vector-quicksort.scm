(define vector-quicksort!
    (lambda (v)
        (letrec
            ((qsort (lambda (low high)
                (if (< low high)
                    (let
                        ((middle (partition v low high)))
                        (qsort low (1- middle))
                        (qsort (1+ middle) high)
                    )
                )
            )))

            (qsort 0 (1- vector-length v))
        )
    )
)

(define vector-swap!
    (lambda (vec i j)
        (let
            ((temp (vector-ref vec i)))
            (vector-set! vec i (vector-ref vec j))
            (vector-set! vec j temp)
        )
    )
)

(define partition
    (lambda (v low high)
        (let
            ((pivot (vector-ref v low)))
            (letrec
                ((search (lambda (left right)
                    (letrec
                        (
                            (search-up (lambda (i)
                                (cond
                                    ((= i (1+ right)) (1- i))
                                    ((> (vector-ref v i) pivot) i)
                                    (else (search-up (1+ i)))
                                )
                            ))
                            (search-down (lambda (i)
                                (cond
                                    ((or (= i (1- left)) (< (vector-ref v i) pivot)) i)
                                    (else (search-down (1- i)))
                                )
                            ))
                        )
                        (let
                            (
                                (new-left (search-up left))
                                (new-right (search-down right))
                            )
                            (if (< new-left new-right)
                                (begin
                                    (vector-swap! v new-left new-right)
                                    (search (1+ new-left) (1- new-right))
                                )
                                (begin
                                    (vector-swap! v low new-right)
                                    new-right
                                )
                            )
                        )
                    )
                )))

                (search (1+ low) high)
            )
        )
    )
)
