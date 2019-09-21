(define vector-generator
    (lambda (gen-proc)
        (lambda (size)
            (let
                ((vec (make-vector size)))
                (letrec
                    ((loop (lambda (i)
                        (if (< i size)
                            (begin
                                (vector-set! vec i (gen-proc i))
                                (loop (1+ i))
                            )
                        )
                    )))
                    (loop 0)
                )
                vec
            )
        )
    )
)

(define vector-update!
    (lambda (vec i c)
        (vector-set! vec i c)
        vec
    )
)

(define list->vector
    (lambda (ls)
        (let
            ((vec (make-vector (length ls))))
            (letrec
                ((convert (lambda (ls i)
                    (if (not (null? ls))
                        (begin
                            (vector-set! vec i (car ls))
                            (convert (cdr ls) (1+ i))
                        )
                    )
                )))
                (convert ls 0)
            )
            vec
        )
    )
)

(define vector-reverse!
    (lambda (vec)
        (let
            ((swapv! (swap-maker vec)))
            (letrec
                ((switch (lambda (i j)
                    (if (< i j)
                        (begin
                            (swapv! i j)
                            (switch (1+ i) (1- j))
                        )
                    )
                )))
                (switch 0 (1- (vector-length vec)))
            )
            vec
        )
    )
)

(define swap-maker
    (lambda (vec)
        (lambda (i1 i2)
            (let
                ((temp (vector-ref vec i1)))
                (vector-update!
                    (vector-update! vec i1 (vector-ref vec i2))
                    i2
                    temp
                )
            )
        )
    )
)

(define dot-product
    (lambda (vec1 vec2)
        (let
            ((size (vector-length vec1)))
            (letrec
                ((loop (lambda (i acc)
                    (if (= i size)
                        acc
                        (let
                            (
                                (v1 (vector-ref vec1 i))
                                (v2 (vector-ref vec2 i))
                            )
                            (+ acc (* v1 v2))
                        )
                    )
                )))
                (loop 0 0)
            )
        )
    )
)
