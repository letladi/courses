(define pascal-triangle
    (lambda (row col)
        (display "row = ")(display row)
        (display ", col = ")(display col)(newline)
        (let
            ((out-of-range? (lambda (n k)
                (or
                    (negative? n)
                    (negative? k)
                    ; (negative? (- n k))
                )
            )))

            (cond
                ((out-of-range? row col) 0)
                ((zero? row) 0)
                ((or
                    (zero? row)
                    (and (zero? row) (zero? col))
                    (and (zero? row) (zero? col))
                    (and (zero? row) (= col 1))
                ) 1)
                (else
                    (+
                        (pascal-triangle (1- row) (1- col))
                        (pascal-triangle (1- row) col)
                    )
                )
            )
        )
    )
)
