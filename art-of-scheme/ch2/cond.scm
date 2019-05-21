(define type-of
    (lambda (item) 
        (cond 
            ((pair? item) 'pair)
            ((null? item) 'empty-list)
            ((number? item) 'number)
            ((symbol? item) 'symbol)
            (else 'some-other-type)
        )
    )
)

(define car-if-pair
    (lambda (item)
        (if (pair? item)
            (car item)
            item
        )
    )
)

(define type-of
    (lambda (item)
        (if (pair? item)
            'pair
            (if (null? item)
                'empty-list
                (if (number? item)
                    'number
                    (if (symbol? item)
                        'symbol
                        'some-other-type
                    )
                )
            )
        )
    )
)   

(define s-and-n-list?
    (lambda (ls)
        (and 
            (pair? ls)
            (symbol? (car ls))
            (pair? (cdr ls))
            (number? (cadr ls))
        )
    )
)

(define s-or-n-list?
    (lambda (ls)
        (and 
            (pair? ls)
            (or
                (symbol? (car ls))
                (number? (car ls))
            )
        )
    )
)

(define singleton-list?
    (lambda (ls)
        (and
            (pair? ls)
            (null? (cdr ls))
        )
    )
)