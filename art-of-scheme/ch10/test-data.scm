(define table10-17
    '(
        ("Smith, Harold W." 2324 43 1974 "Fox, Charles Q." 49325)
        ("Jones, Mary Ann" 1888 54 1965 "none" 65230)
        ("White, Thomas P." 3403 34 1982 "Smith, Harold W." 27300)
        ("Williams, John" 2451 46 1970 "Jones, John Paul" 41050)
        ("Brown, Susan E." 3620 28 1984 "Williams, John" 18500)
        ("August, Elizabeth" 2221 45 1971 "Jones, John Paul" 44100)
        ("Jones, John Paul" 1990 55 1965 "Jones, Maury Ann" 63700)
        ("Wilson, William W." 2455 46 1970 "August, Elizabeth" 41050)
        ("Black, Burton P." 3195 38 1978 "Smith, Harold W." 31420)
        ("Fox, Charles Q." 2400 41 1981 "Jones, John Paul" 52200)
        ("Blue, Benjamin J." 3630 26 1984  "Williams, John" 18500)
    )
)

(define deep-list->vector
    (lambda (ls)
        (letrec
            (
                (len (length ls))
                (convert (lambda (ls vec i)
                    (if (null? ls)
                        vec
                        (let*
                            (
                                (first (car ls))
                                (rest (cdr ls))
                            )
                            (cond
                                ((list? first)
                                    (let
                                        ((first-vec (make-vector (length first))))
                                        (vector-set! vec i first-vec)
                                        (convert first first-vec 0)
                                        (convert rest vec (1+ i))
                                    )
                                )
                                (else
                                    (vector-set! vec i first)
                                    (convert rest vec (1+ i))
                                )
                            )
                        )
                    )
                ))
            )
            (convert ls (make-vector len) 0)
        )
    )
)

(define vector-table10-17 (deep-list->vector table10-17))
