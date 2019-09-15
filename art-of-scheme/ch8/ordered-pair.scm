(load "set.scm")
(load "op-3.scm")

(define cartesian-product
    (lambda (s1 s2)
        (if (empty-set? s1)
            the-empty-set
            (let
                ((elem (pick s1)))
                (union
                    (set-map
                        (lambda (x) (make-op elem x))
                        s2
                    )
                    (cartesian-product ((residue elem) s1) s2)
                )
            )
        )
    )
)

(define domain
    (lambda (rel)
        (set-map op-1st rel)
    )
)

(define range
    (lambda (rel)
        (set-map op-2nd rel)
    )
)

(define is-older-than-relation
    (make-set
        (make-op 'tom 'bob)
        (make-op 'tom 'jim)
        (make-op 'bob 'jim)
    )
)

(define is-older-than?
    (lambda (b1 b2)
        ((contains is-older-than-relation) (make-op b1 b2))
    )
)

(define subrelation/1st
    (lambda (rel)
        (lambda (arg)
            ((set-builder
                (lambda (x) ((set-equal (op-1st x)) arg))
                the-empty-set
            ) rel)
        )
    )
)

(define function?
    (lambda (rel)
        (or
            (empty-set? rel)
            (let
                (
                    (subrel ((subrelation/1st rel) (op-1st (pick rel))))
                )
                (and
                    (= (cardinal subrel) 1)
                    (function? (difference rel subrel))
                )
            )
        )
    )
)

(define value
    (lambda (fun)
        (lambda (arg)
            (op-2nd
                (pick
                    ((subrelation/1st fun) arg)
                )
            )
        )
    )
)
