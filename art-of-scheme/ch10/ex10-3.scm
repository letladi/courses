(load "test-data.scm")
(load "natural-mergesort.scm")
(load "../util.scm")

(define get-field-index
    (lambda (field-name)
        (cond
            ((string-ci=? field-name "name") 0)
            ((string-ci=? field-name "id") 1)
            ((string-ci=? field-name "age") 2)
            ((or
                (string-ci=? field-name "yr. emp")
                (string-ci=? field-name "year employed")
            ) 3)
            ((string-ci=? field-name "supervisor") 4)
            ((string-ci=? field-name "salary") 5)
        )
    )
)

(define assert-field-name-exists (lambda (field-name col-name)
    (or
        (string-ci=? field-name "name")
        (string-ci=? field-name "id")
        (string-ci=? field-name "age")
        (string-ci=? field-name "yr. emp")
        (string-ci=? field-name "year employed")
        (string-ci=? field-name "supervisor")
        (string-ci=? field-name "salary")
        (throw (string-append "field-name '" field-name "' does not exist in the " col-name))
    )
))

(define get-rel (lambda (field-name asc?)
    (cond
        ((or
            (string-ci=? field-name "name")
            (string-ci=? field-name "supervisor"))
                (if asc? string<? string>?)
        )
        ((or
            (string-ci=? field-name "age")
            (string-ci=? field-name "id")
            (string-ci=? field-name "yr. emp")
            (string-ci=? field-name "year employed")
            (string-ci=? field-name "salary"))
                (if asc? < >)
        )
    )
))

(define get-table-rel (lambda (field-name asc?)
    (let
        (
            (rel (get-rel field-name asc?))
            (index (get-field-index field-name))
        )
        (lambda (a b)
            (rel (list-ref a index) (list-ref b index))
        )
    )
))



(define nat-mergesort
    (lambda (field-name asc?)
        (assert-field-name-exists field-name "list")
        (lambda (ls)
            (let
                ((compare (get-table-rel field-name asc?)))
                (if (null? ls)
                    '()
                    (letrec
                        ((sort (lambda (gps)
                            (if (null? (cdr gps))
                                (car gps)
                                (sort (pair-merge gps compare))
                            )
                        )))

                        (sort (make-groups ls compare))
                    )
                )
            )
        )
    )
)
