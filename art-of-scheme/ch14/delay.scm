(load "ch14/index.scm")

(define make-promise "procedure")
(define force "procedure")

(let
    ((delayed-tag "delay") (value-tag "-->"))
    (set! make-promise (lambda (thunk) (cons delayed-tag thunk)))
    (set! force (lambda (arg)
        (if (and (pair? arg) (eq? (car arg) delayed-tag))
            (begin
                (set-car! arg value-tag)
                (set-cdr! arg (thaw (cdr arg)))
            )
            (cdr arg)
        )
    ))
)
