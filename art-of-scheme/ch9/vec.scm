; (load "../util.scm")

(define view
    (lambda (vec)
        (let
            ((highest-index (1- (vector-length vec))))

            (letrec
                ((loop (lambda (i)
                    (display (vector-ref vec i))
                    (if (< i highest-index)
                        (begin
                            (display " ")
                            (loop (1+ i))
                        )
                    )
                )))

                (display "#(")
                (loop 0)
                (display ")")
            )
        )
    )
)

(define make-vector
    (lambda args
        (let
            ((fill-value (if (singleton-list? args)
                '()
                (cadr args)
            )))

            ((vector-generator (lambda (i) fill-value)) (car args))
        )
    )
)

(define list->vector
    (lambda (ls)
        ((vector-generator (lambda (i) (list-ref ls i))) (length ls))
    )
)

(define vector
    (lambda args
        (list->vector args)
    )
)

(define vector-stretch
    (lambda (vec new-size)
        (let
            ((size (vector-length vec)))

            (let
                ((gen-proc (lambda (i)
                    (if (< i size)
                        (vector-ref vec i)
                        '()
                    )
                )))

                ((vector-generator gen-proc) new-size)
            )
        )
    )
)

(define vector-copy
    (lambda (vec)
        (vector-stretch vec (vector-length vec))
    )
)

(define vector-update
    (lambda (vec k val)
        (let
            ((gen-proc (lambda (i)
                (if (= i k)
                    val
                    (vector-ref vec i)
                )
            )))

            ((vector-generator gen-proc) (vector-length vec))
        )
    )
)

(define list->vector
    (lambda (ls)
        (let
            ((vec (make-vector (length ls))))

            (letrec
                ((convert (lambda (ls* v i)
                    (if (null? ls*)
                        v
                        (let
                            ((new-v (vector-update v i (car ls*))))

                            (convert (cdr ls*) new-v (1+ i))
                        )
                    )
                )))

                (convert ls vec 0)
            )
        )
    )
)

(define vector-map
    (lambda (proc vec)
        ((vector-generator (lambda (i) (proc (vector-ref vec i))))
            (vector-length vec)
        )
    )
)

(define multiply-by-scalar
    (lambda (c vec)
        (vector-map (lambda (elem) (* c elem)) vec)
    )
)

(define vector-apply-elementwise-to-both
    (lambda (proc)
        (lambda (vec1 vec2)
            (let
                ((gen-proc (lambda (i)
                    (proc (vector-ref vec1 i) (vector-ref vec2 i))
                )))

                ((vector-generator gen-proc) (vector-length vec1))
            )
        )
    )
)

(define vec+ (vector-apply-elementwise-to-both +))

(define vec* (vector-apply-elementwise-to-both *))

; (define vector-sum
;     (lambda (vec)
;         (let
;             ((size (vector-length vec)))
;             (letrec
;                 ((helper (lambda (i)
;                     (if (= i size)
;                         0
;                         (+ (vector-ref vec i)  (helper (1+ i)))
;                     )
;                 )))
;
;                 (helper 0)
;             )
;         )
;     )
; )

; (define vector-product
;     (lambda (vec)
;         (let
;             ((size (vector-length vec)))
;             (letrec
;                 ((helper (lambda (i)
;                     (if (= i size)
;                         1
;                         (* (vector-ref vec i) (helper (1+ i)))
;                     )
;                 )))
;
;                 (helper 0)
;             )
;         )
;     )
; )

(define vector-accumulate
    (lambda (proc seed)
        (lambda (vec)
            (let
                ((size (vector-length vec)))

                (letrec
                    ((helper (lambda (i)
                        (if (= i size)
                            seed
                            (proc (vector-ref vec i) (helper (1+ i)))
                        )
                    )))

                    (helper 0)
                )
            )
        )
    )
)

(define vector-sum (vector-accumulate + 0))

(define vector-product (vector-accumulate * 1))

(define vector->list  (vector-accumulate cons '()))

(define compose
    (lambda (f g)
        (lambda args
            (f (apply g args))
        )
    )
)

(define dot-product (compose vector-sum vec*))

(define dot-product
    (lambda (vec1 vec2)
        (let
            ((size (vector-length vec1)))
            (letrec
                ((loop (lambda (i)
                    (cond
                        ((= i size) 0)
                        (else
                            (+
                                (*
                                    (vector-ref vec1 i)
                                    (vector-ref vec2 i)
                                )
                                (loop (1+ i))
                            )
                        )
                    )
                )))

                (loop 0)
            )
        )
    )
)
