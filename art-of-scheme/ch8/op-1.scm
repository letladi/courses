(load "set-definition.scm")
(load "set-definition-2.scm")
(load "quant.scm")
(load "set.scm")
(load "sec8-3-ex.scm")

(define make-op
    (lambda (x y)
        (make-set (make-set x) (make-set x y))
    )
)

(define op?
    (lambda (set)
        (and
            (set? set)
            ((for-all set?) set)
            (= (cardinal (family-intersection set)) 1)
            (or
                (= (cardinal set) 1)
                ((both (lambda (x) (= (cardinal x) 2)))
                    set
                    (family-union set)
                )
            )
        )
    )
)

(define op-1st
    (lambda (op)
        (pick (family-intersection op))
    )
)

(define op-2nd
    (lambda (op)
        (let
            ((fam-int (family-intersection op)))
            (let
                ((diff (difference (family-union op) fam-int)))

                (pick (if (empty-set? diff) fam-int diff))
            )
        )
    )
)
