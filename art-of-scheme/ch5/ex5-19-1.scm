(load "binary.scm")

(define binary-operator
    (lambda (bin1 bin2 operator)
        (decimal->binary
            (operator
                (binary->decimal bin1)
                (binary->decimal bin2)
            )
        )
    )
)

(define binary-sum
    (lambda (bin1 bin2)
        (binary-operator bin1 bin2 +)
    )
)

(define binary-product
    (lambda (bin1 bin2)
        (binary-operator bin1 bin2 *)
    )
)
