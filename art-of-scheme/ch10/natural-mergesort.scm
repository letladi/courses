(define make-groups
    (lambda (ls rel)
        (cond
            ((null? ls) '())
            ((null? (cdr ls)) (list ls))
            (else
                (let
                    (
                        (a (car ls))
                        (gps (make-groups (cdr ls) rel))
                    )
                    (if (rel (cadr ls) a)
                        (cons (list a) gps)
                        (cons (cons a (car gps)) (cdr gps))
                    )
                )
            )
        )
    )
)

(define merge
    (lambda (ls1 ls2 rel)
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
                    (if (rel a b)
                        (cons a (merge (cdr ls1) ls2 rel))
                        (cons b (merge ls1 (cdr ls2) rel))
                    )
                )
            )
        )
    )
)

(define pair-merge
    (lambda (sublists rel)
        (cond
            ((null? sublists) '())
            ((null? (cdr sublists)) sublists)
            (else
                (cons
                    (merge (car sublists) (cadr sublists) rel)
                    (pair-merge (cddr sublists) rel)
                )
            )
        )
    )
)

(define nat-mergesort
    (lambda (rel)
        (lambda (ls)
            (if (null? ls)
                '()
                (letrec
                    ((sort (lambda (gps)
                        (if (null? (cdr gps))
                            (car gps)
                            (sort (pair-merge gps rel))
                        )
                    )))

                    (sort (make-groups ls rel))
                )
            )
        )
    )
)
