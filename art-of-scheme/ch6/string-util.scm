(define string-insert
    (lambda (insrt strng n)
        (string-append
            (substring strng 0 n)
            insrt
            (substring strng n (string-length strng))
        )
    )
)
