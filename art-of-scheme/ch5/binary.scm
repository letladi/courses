(load "poly.scm")

(define digits->poly
    (lambda (digit-list)
        (if (null? digit-list)
            (begin
                (newline)
                (display "digits->poly: Not defined for the empty list")
                (newline)
            )
            (letrec
                ((make-poly (lambda (deg ls)
                    (if (null? ls)
                        the-zero-poly
                        (poly-cons deg (car ls)
                            (make-poly (1- deg) (cdr ls))
                        )
                    )
                )))

                (make-poly (1- (length digit-list)) digit-list)
            )
        )
    )
)

(define binary->decimal
    (lambda (digit-list)
        (poly-value (digits->poly digit-list) 2)
    )
)

(define poly->digits
    (lambda (poly)
        (letrec
            ((convert (lambda (p deg)
                (cond
                    ((zero? deg) (list (leading-coef p)))
                    ((= (degree p) deg)
                        (cons (leading-coef p)
                            (convert (rest-of-poly p) (1- deg)))
                    )
                    (else
                        (cons 0 (convert p (1- deg)))
                    )
                )
            )))

            (convert poly (degree poly))
        )
    )
)

(define decimal->binary
    (lambda (num)
        (letrec
            ((dec->bin (lambda (n deg)
                (if (zero? n)
                    the-zero-poly
                    (p+ (make-term deg (remainder n 2))
                        (dec->bin (quotient n 2) (1+ deg))
                    )
                )
            )))

            (poly->digits (dec->bin num 0))
        )
    )
)
