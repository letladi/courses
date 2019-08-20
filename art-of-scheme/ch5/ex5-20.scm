(define binary->decimal
    (lambda (bin)
        (letrec
            (
                (bin-rev (reverse bin))
                (convert (lambda (bin dec power-of-two)
                    (cond
                        ((null? bin) dec)
                        (else
                            (convert
                                (cdr bin)
                                (+
                                    dec
                                    (* (car bin) power-of-two)
                                )
                                (* 2 power-of-two)
                            )
                        )
                    )
                ))
            )

            (convert bin-rev 0 1)
        )
    )
)

(define decimal->binary
    (lambda (dec)
        (letrec
            (
                (convert (lambda (dec bin)
                    (cond
                        ((zero? dec) bin)
                        (else
                            (convert
                                (quotient dec 2)
                                (cons (remainder dec 2) bin)
                            )
                        )
                    )
                ))
            )

            (convert dec '())
        )
    )
)
