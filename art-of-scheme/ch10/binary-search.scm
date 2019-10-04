(load "../util.scm")

(define binary-search
    (lambda (rel)
        (lambda (vec target)
            (letrec
                ((search (lambda (left right)
                    (if (< right left)
                        (throw "The search failed.")
                        (let
                            ((middle (floor (/ (+ left right) 2))))
                            (let
                                ((mid-val (vector-ref vec middle)))
                                (cond
                                    ((rel target mid-val) (search left (1- middle)))
                                    ((rel mid-val target) (search (1+ middle) right))
                                    (else middle)
                                )
                            )
                        )
                    )
                )))

                (search 0 (1- (vector-length vec)))
            )
        )
    )
)
