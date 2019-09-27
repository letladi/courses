(define make-groups
    (lambda (ls)
        (cond
            ((null? ls) '())
            ((null? (cdr ls)) (list ls))
            (else
                (let
                    ((a (car ls)))
                    (gps (make-groups (cdr ls)))
                )
            )
        )
    )
)

(define pair-merge
    (lambda (sublists)
        (cond
            ((null? sublists) '())
            ((null? (cdr sublists)) sublists)
            (else (cons (merge (car sublists) (cadr sublists)) (pair-merge (cddr sublists))))
        )
    )
)

(define nat-mergesort
    (lambda (ls)
        (if (null? ls)
            '()
            (letrec
                ((sort (lambda (gps)
                    (if (null? (cdr gps))
                        (car gps)
                        (sort (pair-merge gps))
                    )
                )))
                (sort (make-groups ls))
            )
        )
    )
)

(define vector-merge!
    (lambda (newvec vec)
        (lambda (left top-left right top-right)
            (letrec
                ((mergeloop (lambda (left right i)
                    (cond
                        ((and (< left top-left) (< right top-right))
                            (if (< (vector-ref vec left) (vector-ref vec right))
                                (begin
                                    (vector-set! newvec i (vector-ref vec left))
                                    (mergeloop (1+ left) right (1+ i))
                                )
                                (begin
                                    (vector-set! newvec i (vector-ref vec right))
                                    (mergeloop left (1+ right) (1+ i))
                                )
                            )
                        )
                        ((< left top-left)
                            (vector-set! newvec i (vector-ref vec left))
                            (mergeloop (1+ left) right (1+ i))
                        )
                        ((< right top-right)
                            (vector-set! newvec i (vector-ref vec right))
                            (mergeloop left (1+ right) (1+ i))
                        )
                    )
                )))

                (mergeloop left right left)
            )
        )
    )
)

; (define vector-mergesort!
;     (lambda (vec1)
;         (let
;             ((vec-size (vector-length vec1)))
;             (let
;                 (
;                     (adjust (lambda (k) (min k vec-size)))
;                     (vec2 (make-vector vec-size))
;                     (max-index (1- vec-size))
;                 )
;                 (letrec
;                     ((merge-pass (lambda (group-size count)
;                         (if (> group-size max-index)
;                             (if (even? count) (vector-change! vec1 0 max-index vec2))
;                             (let
;                                 (
;                                     (newvec (if (odd? count) vec2 vec1))
;                                     (vec (if (odd? count) vec1 vec2))
;                                 )
;                                 (let
;                                     ((merge! (vector-merge! newvec vec)))
;                                     (letrec
;                                         ((group-ends (lambda (left top-left right top-right)
;                                             (if (<= left max-index)
;                                                 (begin
;                                                     (merge! left top-left right top-right)
;                                                     (let
;                                                         ((new-right (+ top-right group-size)))
;                                                         (group-ends
;                                                             top-right
;                                                             (adjust new-right)
;                                                             new-right
;                                                             (adjust (+ new-right group-size))
;                                                         )
;                                                     )
;                                                 )
;                                             )
;                                         )))
;                                         (group-ends 0 (adjust group-size) group-size (adjust (* 2 group-size)))
;                                     )
;                                 )
;                             )
;                         )
;                     )))
;                     (group-ends 0 (adjust group-size) group-size (adjust (* 2 group-size)))
;                 )
;             )
;             (merge-pass (* group-size 2) (1+ count))
;         )
;     )
; )

(define vector-change!
    (lambda (vec1 j k vec2)
        (letrec
            ((loop (lambda (i)
                (if (<= i k)
                    (begin
                        (vector-set! vec1 i (vector-ref vec2 i))
                        (loop (1+ i))
                    )
                )
            )))
            (loop j)
        )
    )
)
