(load "vec-2.scm")

(define successive-powers
    (lambda (base)
        (lambda (n)
            (letrec*
                (
                    (vec (make-vector n))
                    (loop (lambda (i acc)
                        (if (= i (vector-length vec))
                            vec
                            (begin
                                (vector-update! vec i acc)
                                (loop (1+ i) (* acc base))
                            )
                        )
                    ))
                )
                (loop 0 1)
            )
        )
    )
)

(define view-collection-builder
    (lambda (get-next-el len-fn opening-ch closing-ch separator)
        (lambda (c)
            (display opening-ch)
            (let
                ((len (len-fn c)))

                (if (= len 0)
                    (display closing-ch)

                    (begin
                        (letrec*
                            ((loop (lambda (i sep)
                                (if (< i len)
                                    (begin
                                        (display sep)
                                        (display (get-next-el c i))
                                        (loop (1+ i) separator)
                                    )
                                    c
                                )
                            )))

                            (loop 0 "")
                        )
                    )
                )
            )
            (display closing-ch)
        )
    )
)

(define view
    (view-collection-builder
        (lambda (vec i) (vector-ref vec i))
        (lambda (vec) (vector-length vec))
        "#("
        ")"
        ", "
    )
)

(define vector-view
    (view-collection-builder
        (lambda (vec i) (vector-ref vec i))
        (lambda (vec) (vector-length vec))
        "<"
        ">"
        ", "
    )
)

; 9.5 When vectors are involved, 'eq?' and 'eqv?' return #t only if the two given
; vectors are the same object. 'equal?' returns #t if the two vectors are the same
; object and if they contain the same elements.

(define vector-linear-search
    (lambda (vec obj)
        (letrec
            (
                (len (vector-length vec))
                (searcher (lambda (i)
                    (cond
                        ((= len i) -1)
                        ((equal? obj (vector-ref vec i)) i)
                        (else
                            (searcher (1+ i))
                        )
                    )
                ))
            )

            (searcher 0)
        )
    )
)

(define vector-append
    (lambda (vec obj)
        (letrec*
            (
                (old-len (vector-length vec))
                (new-len (1+ old-len))
                (gen (lambda (i)
                    (if (= i old-len)
                        obj
                        (vector-ref vec i)
                    )
                ))

            )
            ((vector-generator gen) new-len)
        )
    )
)

(define vector-reverse
    (lambda (vec)
        (letrec*
            (
                (len (vector-length vec))
                (last-el-index (1- len))
                (gen (lambda (i)
                    (let
                        (
                            (i-el (vector-ref vec i))
                            (j (- last-el-index i))
                        )
                        (vector-ref vec j)
                    )
                ))
            )

            ((vector-generator gen) len)
        )
    )
)
