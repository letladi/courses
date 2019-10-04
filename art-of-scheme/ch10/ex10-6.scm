(load "binary-search.scm")
(load "../util.scm")
(load "ex10-3.scm")

(define sorted-vector-table10-17 (deep-list->vector ((nat-mergesort "name" #t) table10-17)))

(define search-table
    (lambda (name)
        (let*
            (
                (name-index (get-field-index "name"))
                (rel (lambda (a b)
                    (cond
                        ((vector? a)
                            (string<? (vector-ref a name-index) b)
                        )
                        ((vector? b)
                            (string<? a (vector-ref b name-index))
                        )
                    )
                ))
                (item-index ((binary-search rel) sorted-table10-17 name))
            )
            (display "item-index: ")
            (display item-index)
            (newline)
            (if (>= item-index 0)
                (vector-ref
                    sorted-vector-table10-17
                    item-index
                )
            )
        )
    )
)
