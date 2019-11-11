(define lwp-list '())

(define lwp
    (lambda (thunk)
        (set! lwp-list (append lwp-list (list thunk)))
    )
)

(define start
    (lambda ()
        (let ([p (car lwp-list)])
            (set! lwp-list (cdr lwp-list))
            (p)
        )
    )
)

(define pause
    (lambda ()
        (call/cc
            (lambda (k)
                (lwp (lambda () (k #f)))
                (start)
            )
        )
    )
)
