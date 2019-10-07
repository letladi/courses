(define vector-memoize
    (lambda (max-arg)
        (lambda (proc)
            (let
                ((table (make-vector (1+ max-arg) '())))

                (lambda (arg)
                    (if (> arg max-arg)
                        (proc arg)
                        (let
                            ((item-stored (vector-ref table arg)))
                            (if (pair? item-stored)
                                (car item-stored)
                                (let
                                    ((val (proc arg)))
                                    (vector-set! table arg (list val))
                                    val
                                )
                            )
                        )
                    )
                )
            )
        )
    )
)

(define memo-fib
    ((vector-memoize 100)
        (lambda (n)
            (if (< n 2)
                n
                (+ (memo-fib (- n 1)) (memo-fib (- n 2)))
            )
        )
    )
)
