(load "vec-2.scm")

(define num-cols
    (lambda (mat)
        (let
            ((size (1- (vector-length mat))))
            (vector-ref mat size)
        )
    )
)

(define num-rows
    (lambda (mat)
        (let
            ((size (1- (vector-length mat))))
            (/ size (vector-ref mat size))
        )
    )
)

(define matrix-ref
    (lambda (mat)
        (letrec*
            (
                (ncols (num-cols mat))
                (index-check-builder (lambda (min-val max-index-proc)
                    (lambda (i)
                        (and (>= i min-val) (< i (max-index-proc mat)))
                    )
                ))
                (row-index-in-range? (index-check-builder 0 (lambda (mat) (num-rows mat))))
                (col-index-in-range? (index-check-builder 0 (lambda (mat) (num-cols mat))))
                (assert-index (lambda (in-range? prop-name)
                    (if (not in-range?)
                        (raise
                            (condition
                                (make-message-condition (string-append "the matrix " prop-name " index is out of range"))
                            )
                        )
                    )
                ))
            )

            (lambda (i j)
                (begin
                    (assert-index (row-index-in-range? i) "row")
                    (assert-index (col-index-in-range? j) "column")
                    (vector-ref mat (+ (* i ncols) j))
                )
            )
        )
    )
)
