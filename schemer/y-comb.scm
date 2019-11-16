(((lambda (proc)
    (lambda (n)
        (if (zero? n)
            1
            (* n ((proc proc) (1- n)))
        )
    )
) (lambda (proc)
    (lambda (n)
        (if (zero? n)
            1
            (* n ((proc proc) (1- n)))
        )
    )
)) 5)

(define fact
    ((lambda (proc)
        ((lambda (fn-arg)
            (lambda (n)
                (if (zero? n)
                    1
                    (* n (fn-arg (1- n)))
                )
            )
        ) (lambda (arg) ((proc proc) arg)))
    ) (lambda (proc)
        ((lambda (fn-arg)
            (lambda (n)
                (if (zero? n)
                    1
                    (* n (fn-arg (1- n)))
                )
            )
        ) (lambda (arg) ((proc proc) arg)))
    ))
)

(define F*
    (lambda (fn-arg)
        (lambda (n)
            (if (zero? n)
                1
                (* n (fn-arg (1- n)))
            )
        )
    )
)
