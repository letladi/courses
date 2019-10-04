(load "mergesort.scm")


(define get-mid-index
    (lambda (first last)
        (let
            ((diff (- last first)))
            (+
                first
                (quotient diff 2)
            )
        )
    )
)

(define vector-mergesort!
    (lambda (vec)
        (let*
            (
                (size (vector-length vec))
                (store (make-vector size))
                (max-index (1- size))
                (merge! (vector-merge! store vec))
            )
            (letrec
                ((sort (lambda (first last inv-count)
                    (if (< first last)
                        (let
                            (
                                (mid (floor (/ (+ left right) 2)))
                                (adjust (lambda (k) (min k max-index)))
                            )

                            (if (and (< first mid) (< mid last))
                                (begin
                                    (merge! first mid mid last)
                                    (vector-change! vec first last store)
                                    (sort first mid (1+ inv-count))
                                    (sort (1+ mid) last (1+ inv-count))
                                    (if (= inv-count 0)
                                        (begin
                                            (display "\nlast index: ")
                                            (display last)
                                            (display ", mid index: ")
                                            (display mid)
                                        )
                                    )
                                    (display "\nstore: ")
                                    (display store)
                                    (newline)
                                )
                            )
                        )
                    )
                )))

                (sort 0 max-index 0)
            )
        )
    )
)

(define v1 (vector 2 1 4 7 6 5 22 16 12 17))
(define v2 (make-vector (vector-length v1)))
(define merge! (vector-merge! v2 v1))
