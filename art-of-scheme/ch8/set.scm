(load "set-definition-2.scm")

(define make-set
    (lambda args
        (letrec
            ((list-make-set (lambda (args-list)
                (if (null? args-list)
                    the-empty-set
                    (adjoin
                        (car args-list)
                        (list-make-set (cdr args-list))
                    )
                )
            )))

            (list-make-set args)
        )
    )
)

(define none
    (lambda (pred)
        (letrec
            ((test (lambda (s)
                (or (empty-set? s)
                    (let ((elem (pick s)))
                        (and (not (pred elem))
                            (test ((residue elem) s))
                        )
                    )
                )
            )))
            test
        )
    )
)

(define there-exists
    (lambda (pred)
        (compose not (none pred))
    )
)

(define for-all
    (lambda (pred)
        (none (compose not pred))
    )
)

(define set-equal
    (lambda (obj1)
        (lambda (obj2)
            (or (and
                    ((neither set?) obj1 obj2)
                    (equal? obj1 obj2)
                )
                (and
                    ((both set?) obj1 obj2)
                    ((subset obj1) obj2)
                    ((subset obj2) obj1)
                )
            )
        )
    )
)

(define element (compose there-exists set-equal))

(define contains
    (lambda (set)
        (lambda (obj)
            ((element obj) set)
        )
    )
)

(define superset
    (lambda (s1)
        (lambda (s2)
            ((for-all (contains s1)) s2)
        )
    )
)

(define subset
    (lambda (s1)
        (lambda (s2)
            ((superset s2) s1)
        )
    )
)

(define cardinal
    (lambda (s)
        (if (empty-set? s)
            0
            (let ((elem (pick s)))
                (1+ (cardinal ((residue elem) s)))
            )
        )
    )
)

(define intersection
    (lambda (s1 s2)
        (letrec
            ((helper (lambda (s1)
                (if (empty-set? s1)
                    the-empty-set
                    (let ((elem (pick s1)))
                        (if ((contains s2) elem)
                            (adjoin elem (helper ((residue elem) s1)))
                            (helper ((residue elem) s1))
                        )
                    )
                )
            )))

            (helper s1)
        )
    )
)

(define union
    (lambda (s1 s2)
        (letrec
            ((helper (lambda (s1)
                (if (empty-set? s1)
                    s2
                    (let
                        ((elem (pick s1)))
                        (if (not ((contains s2) elem))
                            (adjoin elem (helper ((residue elem) s1)))
                            (helper ((residue elem) s1))
                        )
                    )
                )
            )))

            (helper s1)
        )
    )
)

(define difference
    (lambda (s1 s2)
        (letrec
            ((helper (lambda (s1)
                (if (empty-set? s1)
                    the-empty-set
                    (let
                        ((elem (pick s1)))
                        (if (not ((contains s2) elem))
                            (adjoin elem (helper ((residue elem) s1)))
                            (helper ((residue elem) s1))
                        )
                    )
                )
            )))

            (helper s1)
        )
    )
)

(define set-builder
    (lambda (pred base-set)
        (letrec
            ((helper (lambda (s)
                (if (empty-set? s)
                    base-set
                    (let
                        ((elem (pick s)))

                        (if (pred elem)
                            (adjoin elem (helper ((residue elem) s)))
                            (helper ((residue elem) s))
                        )
                    )
                )
            )))

            helper
        )
    )
)

(define intersection
    (lambda (s1 s2)
        ((set-builder (contains s2) the-empty-set) s1)
    )
)

(define union
    (lambda (s1 s2)
        ((set-builder (compose not (contains s2)) s2) s1)
    )
)

(define difference
    (lambda (s1 s2)
        ((set-builder (compose not (contains s2)) the-empty-set) s1)
    )
)

(define family-union
    (lambda (s)
        (if (empty-set? s)
            the-empty-set
            (let
                ((elem (pick s)))
                (union elem (family-union ((residue elem) s)))
            )
        )
    )
)

(define family-intersection
    (lambda (s)
        (if (empty-set? s)
            the-empty-set
            (letrec
                ((fam-int (lambda (s)
                    (let
                        ((elem (pick s)))

                        (let
                            ((rest ((residue elem) s)))

                            (if (empty-set? rest)
                                elem
                                (intersection elem (fam-int rest))
                            )
                        )
                    )
                )))

                (fam-int s)
            )
        )
    )
)

(define set-map
    (lambda (proc s)
        (if (empty-set? s)
            the-empty-set
            (let
                ((elem (pick s)))
                (adjoin
                    (proc elem)
                    (set-map proc ((residue elem) s))
                )
            )
        )
    )
)

(define list->set
    (lambda (ls)
        (apply make-set ls)
    )
)

(define set->list
    (lambda (s)
        (if (empty-set? s)
            '()
            (let
                ((elem (pick s)))
                (cons elem (set->list ((residue elem) s)))
            )
        )
    )
)
