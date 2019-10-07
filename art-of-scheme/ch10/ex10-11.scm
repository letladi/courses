(load "test-data.scm")
(load "ex10-3.scm")
(load "../ch7/index.scm")

(define age (lambda (vec) (vector-ref vec (get-field-index "age"))))
(define get-value (lambda (vec name) (vector-ref vec (get-field-index name))))
(define age-test? (lambda (vec) (> (age vec) 25)))

(define list-vector-table10-17 (vector->list vector-table10-17))

; from ch7/curry.scm
(define andmap-c
    (lambda (pred)
        (letrec
            ((and-help (lambda (ls)
                (cond
                    ((null? ls) #t)
                    (else
                        (and
                            (pred (car ls))
                            (and-help (cdr ls))
                        )
                    )
                )
            )))

            and-help
        )
    )
)

(define apply-to-all
    (lambda (proc)
        (letrec
            ((helper (lambda (ls)
                (if (null? ls)
                    '()
                    (cons (proc (car ls)) (helper (cdr ls)))
                )
            )))

            helper
        )
    )
)

(define map
    (lambda (proc ls)
        ((apply-to-all proc) ls)
    )
)

(define age<50&salary>50000?
    (lambda (vec)
        (and
            (< (get-value vec "age") 50)
            (> (get-value vec "salary") 50000)
        )
    )
)

((andmap-c (lambda (vec1)
    (let
        (
            (name1 (get-value vec1 "name"))
            (supervisor1 (get-value vec1 "supervisor"))
        )
        (or
            (string<? name1 supervisor1)
            (ormap (lambda (vec2)
                (let
                    (
                        (name2 (get-value vec2 "name"))
                        (supervisor2 (get-value vec2 "supervisor"))
                    )
                    (and
                        (string<? name2 name1)
                        (string<? supervisor2 supervisor1)
                    )
                )
            ) list-vector-table10-17)
        )
    )

)) list-vector-table10-17)

(define name&age
    (lambda (vec)
        (let
            (
                (name (get-value vec "name"))
                (age (get-value vec "age"))
            )
            (list name age)
        )
    )
)

(define over-45?
    (lambda (vec)
        (> (get-value vec "age") 45)
    )
)

(define over-45-list (filter over-45? list-vector-table10-17))

(map
    (lambda (vec)
        (list
           (get-value vec "id")
           (get-value vec "age")
           (get-value vec "yr. emp")
           (get-value vec "salary")
         )
     )
     over-45-list
)

(define find-supervisor
    (lambda (vec1)
        (lambda (v)
            (if (string=? (get-value vec1 "name") v)
                (get-value vec1 "supervisor")
                #f
            )
        )
    )
)

(define closest-common-supervisor
    (letrec
        ((find-css (lambda (path1 path2)
            (if (null? (cdr path1))
                (car path1)
                (let
                    (
                        (rest1 (cdr path1))
                        (rest2 (cdr path2))
                    )
                    (if (string=? (car rest1) (car rest2))
                        (find-css rest1 rest2)
                        (car path1)
                    )
                )
            )

        )))

        (lambda (test-procedure)
            (lambda (table)
                (letrec
                    ((build-path (lambda (tbl u acc)
                        (if (null? tbl)
                            acc
                            (let
                                ((next (car tbl)))
                                (let
                                    ((v ((test-procedure next) u)))
                                    (if (not v)
                                        (build-path (cdr tbl) u acc)
                                        (build-path table v (cons u acc))
                                    )
                                )
                            )
                        )
                    )))

                    (lambda (x y)
                        (find-css
                            (build-path table x '())
                            (build-path table y '())
                        )
                    )
                )
            )
        )
    )
)

(display (((closest-common-supervisor find-supervisor) list-vector-table10-17) "White, Thomas P." "Blue, Benjamin J."))

; the advantage of the vectors over the set is that the vector methods are more direct and
; thus easier to understand.
