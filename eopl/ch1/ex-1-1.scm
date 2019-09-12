(define in-1?
    (lambda (n)
        (if (= n 2)
            #t
            (if (>= (- n 3) 2)
                (in-1? (- n 3))
                #f
            )
        )
    )
)
