(load "../util.scm")

(define one?
    (lambda (num)
        (= num 1)
    )
)

(define binary-sum
    (lambda (bin1 bin2)
        (letrec*
            (
            (sum-two (lambda (n1 n2)
                (cond
                    ((and (one? n1) (one? n2)) (list 0 1))
                    ((and (zero? n1) (zero? n2)) (list 0 0))
                    (else (list 1 0))
                )
            ))
            (sum-three (lambda (n1 n2 n3)
                (letrec*
                    (
                        (sum (sum-two n1 n2))
                        (carryover (cadr sum))
                        (added (car sum))
                    )

                    (cond
                        ((one? carryover)  (if (one? n3)
                            (list 1 1)
                            sum
                        ))
                        (else
                            (if (zero? n3)
                                sum
                                (sum-two n3 (car sum))
                            )
                        )
                    )
                ))
            )
            (add (lambda (bin1 bin2 carryover)
                (cond
                    ((null? bin2) (
                        if (one? carryover)
                        (list carryover)
                        '()
                    ))
                    (else
                        (let
                            ((sum (sum-three (car bin1) (car bin2) carryover)))

                            (cons
                                (car sum)
                                (add (cdr bin1) (cdr bin2) (cadr sum))
                            )
                        )
                    )
                )
            )))

            (reverse
                (add
                    (reverse bin1)
                    (reverse bin2)
                    0
                )
            )
        )
    )
)
