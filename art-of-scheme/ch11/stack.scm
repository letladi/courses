(load "../util.scm")

(define stk '())

(define empty?
    (lambda ()
        (null? stk)
    )
)

(define top
    (lambda ()
        (if (empty?)
            (throw "top: The stack is empty.")
            (car stk)
        )
    )
)

(define print-stack
    (lambda ()
        (display "TOP: ")
        (for-each (lambda (x) (display x) (display " ")) stk)
        (newline)
    )
)

(define push!
    (lambda (a)
        (set! stk (cons a stk))
    )
)

(define pop!
    (lambda ()
        (if (empty?)
            (throw "pop!: The stack is empty.")
            (set! stk (cdr stk))
        )
    )
)
