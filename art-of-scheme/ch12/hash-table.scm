(load "ch12/box.scm")
(load "ch9/vec-2.scm")
(load "ch12/bucket.scm")

(define hash-table-maker
    (lambda (size hash-fn)
        (let
            (
                (v ((vector-generator (lambda (i) (bucket-maker))) size))
                (append-pair (lambda (ls key bucket)
                    (cond
                        ((send bucket 'empty?) ls)
                        (else
                            (append!
                                ls
                                (make-pair key (send bucket 'image))
                            )
                        )
                    )
                ))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "hash-table")
                    ((image)
                        (let ((res '()) (count 0))
                            (vector-for-each
                                (lambda (bucket)
                                    (set! res (append-pair res count bucket))
                                    (set! count (1+ count))
                                )
                                v
                            )
                            res
                        )
                    )
                    (else
                        (delegate (vector-ref v (hash-fn (2nd msg))) msg)
                    )
                )
            )
        )
    )
)

(define memoize
    (let ((hashfn (lambda (x) (remainder x 1000))))
        (let ((h (hash-table-maker 1000 hashfn)))
            (lambda (proc)
                (lambda (arg)
                    (send h 'update! arg (lambda (v) v) proc)
                    (send h 'lookup arg (lambda (v) v) (lambda () #f))
                )
            )
        )
    )
)

(define word-frequency
    (let (
            (naive-hash-function (lambda (s)
                (remainder (char->integer (string-ref s 0)) 26)
            ))
        )
        (let ((h (hash-table-maker 26 naive-hash-function)))
            (lambda (string-list)
                (for-each
                    (lambda (s) (send h 'update! s 1+ (lambda (s) 1)))
                    string-list
                )
                h
            )
        )
    )
)
