(load "deep-rec.scm")

(define remove-all-c
    (lambda (item)
        (letrec
            ((helper (lambda (ls)
                (cond
                    ((null? ls) '())
                    (else
                        (let
                            ((a (car ls)))

                            (if (or (pair? a) (null? a))
                                (cons (helper a) (helper (cdr ls)))
                                (if (equal? item a)
                                    (helper (cdr ls))
                                    (cons a (helper (cdr ls)))
                                )
                            )
                        )
                    )
                )
            )))

            helper
        )
    )
)

(define remove-all-c
    (lambda (item)
        (deep-recur
            '()
            (lambda (x y)
                (if (equal? item x)
                    y
                    (cons x y)
                )
            )
            cons
        )
    )
)

(define product-all
    (lambda (ls)
        (letrec
            ((helper (lambda (ls)
                (cond
                    ((null? ls) 1)
                    (else
                        (let
                            ((a (car ls)))
                            (if (or (pair? a) (null? a))
                                (* (helper a) (helper (cdr ls)))
                                (* a (helper (cdr ls)))
                            )
                        )
                    )
                )
            )))

            (helper ls)
        )
    )
)

(define product-all (deep-recur 1 * *))

(define filter-out-all-c
    (lambda (pred)
        (deep-recur
            '()
            (lambda (x y)
                (if (pred x)
                    y
                    (cons x y)
                )
            )
            cons
        )
    )
)

(define filter-out-all
    (lambda (pred ls)
        ((filter-out-all-c pred) ls)
    )
)

(define subst-all-m
    (lambda (new old)
        (deep-recur
            '()
            (lambda (x y)
                (if (equal? x old)
                    (cons new y)
                    (cons x y)
                )
            )
            cons
        )
    )
)

(define reverse-all
    (letrec
        ((proc (lambda (x y)
            (append y (list x))
        )))

        (deep-recur '() proc proc)
    )
)

(define flat-recur
    (lambda (seed list-proc)
        (deep-recur seed list-proc list-proc)
    )
)

(load "flat-rec.scm")

(define deep-recur
    (lambda (seed item-proc list-proc)
        (letrec
            (flat-rec (flat-recur seed item-proc))
            ((helper (lambda (ls)
                (let
                    ((a (car ls)))

                    (if (or (pair? a) (null? a))
                        (list-proc (helper item) (helper (cdr ls)))
                        (flat-rec (cdr ls))
                    )
                )
            )))

            (flat-recur seed helper)
        )
    )
)
