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
            )
        )
    )
)

; this program is not correct, it loops infinitely inside one of the functions (whichever one is called first)
; (lwp (lambda () (let f () (pause) (display "h") (f))))
; (lwp (lambda () (let f () (pause) (display "e") (f))))
; (lwp (lambda () (let f () (pause) (display "y") (f))))
; (lwp (lambda () (let f () (pause) (display "!") (f))))
; (lwp (lambda () (let f () (pause) (newline) (f))))
