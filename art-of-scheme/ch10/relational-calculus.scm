(load "../ch8/set.scm")
(load "../ch8/set-definition-2.scm")
(load "test-data.scm")

(define set10-17 (list->set table10-17))

(define unlist
    (lambda (proc)
        (lambda (ls)
            (apply proc ls)
        )
    )
)

(define age-test?
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (> age 25)
        )
    )
)

(define age<50&salary>50000?
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (and (< age 50) (> salary 50000))
        )
    )
)

; ((for-all
;     (unlist
;         (lambda (n i a y s p)
;             (or
;                 (string<? n s)
;                 ((there-exists
;                     (unlist
;                         (lambda (n* i* a* y* s* p*)
;                             (and (string<? n* n) (string<? s* s))
;                         )
;                     )
;                 ) set10-17)
;             )
;         )
;     )
; ) set10-17)

(define name&age
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (list name age)
        )
    )
)

(define over-45?
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (> age 45)
        )
    )
)

(define over45-set
    ((set-builder over-45? the-empty-set) set10-17)
)

(define find-supervisor
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (lambda (v)
                (if (string=? name v) supervisor #f)
            )
        )
    )
)

(define closest-common-supervisor
    (letrec
        ((find-ccs (lambda (path1 path2)
            (let
                (
                    (rest1 (cdr path1))
                    (rest2 (cdr path2))
                )
                (if (string=? (car rest1) (car rest2))
                    (find-ccs rest1 rest2)
                    (car path1)
                )
            )
        )))

        (lambda (test-procedure)
            (lambda (table)
                (letrec
                    ((build-path (lambda (tbl u)
                        (if (empty-set? tbl)
                            (list u)
                            (let
                                ((next (pick tbl)))
                                (let
                                    ((v ((test-procedure next) u)))
                                    (if (not v)
                                        (build-path ((residue next) tbl) u)
                                        (cons u (build-path table v))
                                    )
                                )
                            )
                        )
                    ))
                    (info (lambda (x)
                        (display (string-append "\n" x ": [reversed path "))
                        (display (reverse (build-path table x)))
                        (display "]\n")
                    ))
                    )
                    (lambda (x y)
                        (info x)
                        (info y)
                        (find-ccs
                            (reverse (build-path table x))
                            (reverse (build-path table y))
                        )
                    )
                )
            )
        )
    )
)
