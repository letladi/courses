(define quicksort
    (letrec
        ((collect (lambda (pivot ls lgroup rgroup)
            (if (null? ls)
                (append (quicksort lgroup) (cons pivot (quicksort rgroup)))
                (if (< (car ls) pivot)
                    (collect pivot (cdr ls) (cons (car ls) lgroup) rgroup)
                    (collect pivot (cdr ls) lgroup (cons (car ls) rgroup))
                )
            )
        )))

        (lambda (ls)
            (if (or (null? ls) (null? (cdr ls)))
                ls
                (collect (car ls) (cdr ls) '() '())
            )
        )
    )
)
