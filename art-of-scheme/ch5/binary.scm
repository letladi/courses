(load "poly.scm")
(load "../util.scm")

(define digits->poly
    (lambda (digit-list)
        (if (null? digit-list)
            (console-error "digits->poly: Not defined for the empty list")
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

(define dec->hex-digit-list
    (lambda (dec-ls)
        (cond
            ((null? dec-ls) '())
            (else
                (cons
                    (list-ref hex-digits (car dec-ls))
                    (dec->hex-digit-list (cdr dec-ls))
                )
            )
        )
    )
)

(define hex-digits '(0 1 2 3 4 5 6 7 8 9 A B C D E F))

(define hex-digit-list
    (lambda (hex-ls)
        (cond
            ((null? hex-ls) '())
            (else
                (cons
                    (index hex-digits (car hex-ls))
                    (hex-digit-list (cdr hex-ls))
                )
            )
        )
    )
)

(define base->decimal
    (lambda (digit-list base)
        (poly-value (digits->poly digit-list) base)
    )
)

(define binary->decimal
    (lambda (digit-list)
        (base->decimal digit-list 2)
    )
)

(define octal->decimal
    (lambda (digit-list)
        (base->decimal digit-list 8)
    )
)

(define hex->decimal
    (lambda (digit-list)
        (base->decimal
            (hex-digit-list digit-list)
            16
        )
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

(define decimal->base
    (lambda (num base)
        (letrec
            ((dec->base (lambda (n deg)
                (if (zero? n)
                    the-zero-poly
                    (p+ (make-term deg (remainder n base))
                        (dec->base (quotient n base) (1+ deg))
                    )
                )
            )))

            (poly->digits (dec->base num 0))
        )
    )
)

(define decimal->binary
    (lambda (num)
        (decimal->base num 2)
    )
)

(define decimal->octal
    (lambda (num)
        (decimal->base num 8)
    )
)

(define decimal->hexadecimal
    (lambda (num)
        (dec->hex-digit-list (decimal->base num 16))
    )
)

(define change-base
    (lambda (ls b1 b2)
        (decimal->base
            (base->decimal ls b1)
            b2
        )
    )
)
