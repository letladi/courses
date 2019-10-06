(load "test-data.scm")
(load "ex10-3.scm")
(load "relational-calculus.scm")

(define table10-27
    '(
        (1888 22300 33000)
        (1990 61080 49320)
        (2221 41000 52200)
        (2324 25550 31500)
        (2400 31010 25250)
        (2451 28800 16500)
        (2455 72050 50010)
        (3195 60500 40220)
        (3403 31100 22500)
        (3620 31100 22500)
        (3630 26300 19400)
    )
)

(define table10-17-sorted-by-id ((nat-mergesort "id" #t) table10-17))

(define joined-unlist
    (lambda (proc)
        (lambda (ls1 ls2)
            (apply proc (append ls1 ls2))
        )
    )
)

(define name&jan-sales
    (joined-unlist
        (lambda (name id age yr-emp supervisor salary id* jan-sales feb-sales)
            (list name jan-sales)
        )
    )
)

(define set-builder-join-and-map
    (lambda (proc)
        (letrec
            ((helper (lambda (ls1 ls2)
                (if (null? ls1)
                    '()
                    (let
                        (
                            (a (car ls1))
                            (b (car ls2))
                        )
                        (cons
                            (proc a b)
                            (helper (cdr ls1) (cdr ls2))
                        )
                    )
                )
            )))
            helper
        )
    )
)

(define names&jan-sales-table
    ((set-builder-join-and-map name&jan-sales) table10-17-sorted-by-id table10-27)
)

(define names&jan-sales-sorted-table
    ((nat-mergesort "name" #t) names&jan-sales-table)
)
