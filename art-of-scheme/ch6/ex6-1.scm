(define substring?
    (lambda (str1 str2)
        (if (= 0 (string-length str1))
            #t
            (letrec*
                (
                    (str1-len (string-length str1))
                    (determine (lambda (str result)
                        (cond
                            ((< (string-length str) str1-len) #f)
                            ((string=?
                                str1
                                (substring str 0 str1-len)
                            ) result)
                            (else
                                (determine (substring str 1 (string-length str)) #t)
                            )
                        )
                    ))
                )

                (determine str2 #t)
            )
        )
    )
)

(define substring-ref
    (lambda (strng n)
        (substring strng n (1+ n))
    )
)

(define string-reverse
    (lambda (strng)
        (letrec
            (
                (str-len (string-length strng))
                (rev-helper (lambda (result i res-len)
                    (cond
                        ((= str-len res-len) result)
                        (else
                            (rev-helper
                                (string-append result (substring-ref strng i))
                                (1- i)
                                (1+ res-len)
                            )
                        )
                    )
                ))
            )

            (rev-helper "" (1- str-len) 0)
        )
    )
)

(define palindrome?
    (lambda (strng)
        (string=? strng (string-reverse strng))
    )
)
