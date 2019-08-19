(load "../util.scm")
(load "zeros.scm")

(define one?
    (lambda (num)
        (= num 1)
    )
)

(define binary-sum
    (lambda (bin1 bin2)
        (letrec*
            (
            (len1 (length bin1))
            (len2 (length bin2))
            (final-bin1 (cond
                    ((> len2 len1) (append (list-of-zeros (- len2 len1)) bin1))
                    (else bin1)
            ))
            (final-bin2 (cond
                ((> len1 len2) (append (list-of-zeros (- len1 len2)) bin2))
                (else bin2)
            ))
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
                    (reverse final-bin1)
                    (reverse final-bin2)
                    0
                )
            )
        )
    )
)

(define binary-product
    (lambda (bin1 bin2)
        (letrec*
            (
                (bin1-rev (reverse bin1))
                (bin2-rev (reverse bin2))
                (bin1-len (length bin1))
                (zero-bin '(0-0))
                (multiply-by-term (lambda (bin bin-term pad-length)
                    (if (one? bin-term)
                        (append (list-of-zeros pad-length) bin)
                        zero-bin
                    )
                ))
                (multiply (lambda (bin bin-sum pad-length)
                    (cond
                        ((null? bin) bin-sum)
                        (else
                            (let
                                (
                                    (term-product (multiply-by-term bin1-rev (car bin) pad-length))
                                )

                                (cond
                                    ((equal? term-product zero-bin)
                                        (multiply (cdr bin) bin-sum (1+ pad-length))
                                    )
                                    (else
                                        (multiply (cdr bin) (binary-sum bin-sum term-product) (1+ pad-length))
                                    )
                                )
                            )
                        )
                    )
                ))
            )

            (multiply bin2-rev (list-of-zeros bin1-len) 0)
        )
    )
)
