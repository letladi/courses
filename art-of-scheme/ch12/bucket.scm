(load "util.scm")
(load "ch11/memoize.scm")
(load "ch12/box.scm")

(define bucket-maker
    (lambda ()
        (letrec
            (
                (table '())
                (remove (lambda (ls key)
                    (cond
                        ((null? ls) '())
                        (else
                            (let
                                (
                                    (pr (car ls))
                                    (rest (cdr ls))
                                )
                                (if (eq? (car pr) key)
                                    rest
                                    (cons pr (remove rest key))
                                )
                            )
                        )
                    )
                ))
            )
            (lambda msg
                (case (1st msg)
                    ((type) "bucket")
                    ((lookup)
                        (let
                            ((key (2nd msg)) (succ (3rd msg)) (fail (4th msg)))
                            (lookup key table (lambda (pr) (succ (cdr pr))) fail)
                        )
                    )
                    ((update!)
                        (for-effect-only
                            (let ((key (2nd msg)) (updater (3rd msg)) (initializer (4th msg)))
                                (lookup key table
                                    (lambda (pr) (set-cdr! pr (updater (cdr pr))))
                                    (lambda ()
                                        (let ((pr (cons key (initializer key))))
                                            (set! table (cons pr table))
                                        )
                                    )
                                )
                            )
                        )
                    )
                    ((update!-lookup)
                        (let ((key (2nd msg)) (success-proc (3rd msg)) (initializer (4th msg)))
                            (lookup key table
                                (lambda (pr)
                                    (set-cdr! pr (updater (cdr pr)))
                                    (success-proc (cdr pr))
                                )
                                (lambda ()
                                    (let ((pr (cons key (initializer key))))
                                        (set! table (cons pr table))
                                        (success-proc (cdr pr))
                                    )
                                )
                            )
                        )
                    )
                    ((re-initialize!)
                        (set! table '())
                    )
                    ((remove!)
                        (let ((key (2nd msg)))
                            (set! (remove table key))
                        )    
                    )
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define memoize
    (lambda (proc)
        (let ((bucket (bucket-maker)))
            (lambda (arg)
                (send bucket 'update!-lookup arg (lambda (val) val) proc)
            )
        )
    )
)

(define word-frequency
    (lambda (string-list)
        (let ((b (bucket-maker)))
            (for-each
                (lambda (s) (send b 'update! s 1+ (lambda (s) 1)))
                string-list
            )
            b
        )
    )
)

(define string-list '("four" "score" "and" "seven" "years" "ago" "our" "fathers"))
