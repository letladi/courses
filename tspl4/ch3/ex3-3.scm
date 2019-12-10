; ex3.3.1
(define inf-print

)

; ex3.3.2
(define product
    (lambda (ls)
        (let f ([ls ls] [res 1])
            (cond
                ((or (null? ls)) res)
                ((= (car ls) 0) 0)
                (else
                    (f
                        (cdr ls)
                        (* (car ls) res)
                    )
                )
            )
        )
    )
)
