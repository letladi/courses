(define vowel-or-consonant
    (lambda (letter)
        (cond
            ((or
                (eq? letter 'a)
                (eq? letter 'e)
                (eq? letter 'i)
                (eq? letter 'o)
                (eq? letter 'u)
            ) 'vowel)
            (else
                'consonant
            )
        )
    )
)

(define vowel-or-consonant
    (lambda (letter)
        (case letter
            ((a e i o u) 'vowel)
            (else 'consonant)
        )
    )
)

(define for-effect-only
    (lambda (item-ignored)
        "unspecified value"
    )
)
