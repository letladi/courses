(define make-groups
    (lambda (ls)
        (cond
            ((null? ls) '())
            ((null? (cdr ls)) (list ls))
            (else
                (let
                    (
                        (a (car ls))
                        (gps (make-groups (cdr ls)))
                    )
                    (if (< (cadr ls) a)
                        (cons (list a) gps)
                        (cons (cons a (car gps)) (cdr gps))
                    )
                )
            )
        )
    )
)

(define merge
    (lambda (ls1 ls2)
        (cond
            ((and (null? ls1) (null? ls2)) '())
            ((null? ls1) ls2)
            ((null? ls2) ls1)
            (else
                (let
                    (
                        (a (car ls1))
                        (b (car ls2))
                    )
                    (if (< a b)
                        (cons a (merge (cdr ls1) ls2))
                        (cons b (merge ls1 (cdr ls2)))
                    )
                )
            )
        )
    )
)

(define pair-merge
    (lambda (sublists)
        (cond
            ((null? sublists) '())
            ((null? (cdr sublists)) sublists)
            (else
                (cons
                    (merge (car sublists) (cadr sublists))
                    (pair-merge (cddr sublists))
                )
            )
        )
    )
)

(define nat-mergesort
    (lambda (ls)
        (if (null? ls)
            '()
            (letrec
                ((sort (lambda (gps)
                    (if (null? (cdr gps))
                        (car gps)
                        (sort (pair-merge gps))
                    )
                )))

                (sort (make-groups ls))
            )
        )
    )
)
