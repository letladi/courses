(load "ch12/bucket.scm")

(define memoize
    (lambda (proc)
        (let ((bucket (bucket-maker)))
            (lambda (arg)
                (send bucket 'update!' arg (lambda (val) val) proc)
                (send bucket 'lookup arg (lambda (val) val) (lambda () #f))
            )
        )
    )
)
