(load "ch12/hash-table.scm")

(define paragraph
    '("this" "hash" "table" "is" "as" "inefficient" "as" "a" "bucket"
    "We" "chose" "the" "vector" "small" "and" "we" "chose" "the" "hash" "function"
    "too" "naively" "of" "course" "this" "would" "never" "be" "done" "in" "practice"
    "most" "systems" "discourage" "the" "user" "from" "worrying" "about" "the" "size"
    "of" "the" "hash" "table" "or" "the" "nature" "of" "the" "hash" "function"
    )
)

(define word-frequency-bucket (word-frequency paragraph))

; ex12.23
(define word-frequency
    (letrec* (
            (vec-size 101)
            (hash-loop (lambda (s i len res)
                (cond
                    ((= i len) (remainder res 26))
                    (else
                        (hash-loop
                            s
                            (1+ i)
                            len
                            (+ res (char->integer (string-ref s i)))
                        )
                    )
                )
            ))
            (hash-function (lambda (s)
                (hash-loop s 0 (string-length s) 0)
            ))
        )
        (let ((h (hash-table-maker 26 hash-function)))
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
