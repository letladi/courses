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
                (get-mid (lambda (first last)
                    (let
                        ((diff (- last first)))
                        (+
                            first
                            (quotient diff 2)
                        )
                    )
                ))
                (merge! (vector-merge! store vec))
            )
            (letrec
                ((sort (lambda (first last inv-count)
                    (if (< first last)
                        (let
                            (
                                (mid (get-mid first last))
                                (adjust (lambda (k) (min k max-index)))
                            )
                            (display (string-append "\nTHE FIRST PART (" (number->string inv-count) ")\n"))
                            (display
                                (string-append
                                    "first: "
                                    (number->string first)
                                    ", middle: "
                                    (number->string mid)
                                    ", last: "
                                    (number->string last)
                                    "\n"
                                )
                            )
                            (sort first mid (1+ inv-count))

                            ; (display "store: ")
                            ; (display store)
                            ; (newline)
                            (display (string-append "\nTHE SECOND PART (" (number->string inv-count) ")\n"))
                            (display
                                (string-append
                                    "first: "
                                    (number->string first)
                                    ", middle: "
                                    (number->string mid)
                                    ", last: "
                                    (number->string last)
                                    "\n"
                                )
                            )
                            (sort (1+ mid) last (1+ inv-count))

                            (if (and (< first mid) (< mid last))
                                (begin
                                    (merge! first mid mid last)
                                    ; (vector-change! vec first mid store)
                                    (vector-change! vec first (adjust last) store)
                                    (display "\nstore: ")
                                    (display store)
                                    (newline)
                                )
                            )

                            ; (if (and (< first mid) (< mid last))
                            ;     (begin
                            ;         (merge! first mid mid last)
                            ;         (vector-change! vec first mid store)
                            ;         (vector-change! vec (1+ mid) last store)
                            ;         (display "store: ")
                            ;         (display store)
                            ;         (newline)
                            ;     )
                            ; )


                        )
                    )
                )))

                (sort 0 size 0)
            )
        )
    )
)

(define v1 (vector 2 1 4 7 6 5 22 16 12))
(define v2 (make-vector (vector-length v1)))
(define merge! (vector-merge! v2 v1))
