(load "relational-calculus.scm")
(load "ex10-7.scm")

(define age<50&salary>50000?
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (and (< age 50) (> salary 50000))
        )
    )
)

(define meets-ex10-8-condition?
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (and
                (> age 40)
                (< yr-emp 1975)
                (> salary 43000)
            )
        )
    )
)

(define ex10-8-row
    (unlist
        (lambda (name id age yr-emp supervisor salary)
            (list name id)
        )
    )
)

(display ((set-builder-map meets-ex10-8-condition? ex10-8-row the-empty-set) set10-17))
