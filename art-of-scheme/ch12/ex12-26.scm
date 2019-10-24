(load "ch12/bucket.scm")
(load "ch12/hash-table.scm")

(define store!
    (lambda (col key value)
        (letrec
            (
                (col-type (send col 'type))
                (update-fn (lambda (v) value))
            )
            (cond
                ((or (string=? col-type "bucket") (string=? col-type "hash-table"))
                    (send col  'update! key update-fn update-fn)
                )
            )
        )
    )
)
