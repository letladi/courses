(load "../ch8/set.scm")
(load "../ch8/set-definition-2.scm")

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
            (> age 35)
        )
    )
)

(define age<50&salary>50000
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
                (if (string=? name v) supervisor #f))
        )
    )
)
