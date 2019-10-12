(load "ch12/acc.scm")

(define acc-max (accumulator-maker 0 max))

; ex 12.1
; (send acc-max 'update! 3)
; (send acc-max 'update! 7)
; (send acc-max 'update! 2)
; (send acc-max 'update! 4)
; (send acc-max 'update! 10)
; (send acc-max 'update! 1)
; (send acc-max 'update! 5)
; (display (send acc-max 'show))
; 3, 7, 2, 4, 10, 1, 5

(define double-box-maker
    (lambda (init-left init-right)
        (let*
            (
                (left-box (box-maker init-left))
                (right-box (box-maker init-right))
                (getbox-msg (lambda (db-msg)
                    (cond
                        ((or (string=? db-msg "show-left") (string=? db-msg "show-right"))
                            "show"
                        )
                        ((or (string=? db-msg "update-left!") (string=? db-msg "update-right!"))
                            "update!"
                        )
                        ((string=? db-msg "reset!") "reset!")
                        (else db-msg)
                    )
                ))
                (get-box (lambda (db-msg)
                    (cond
                        ((or (string=? db-msg "show-left") (string=? db-msg "update-left!"))
                            left-box
                        )
                        ((or (string=? db-msg "show-right") (string=? db-msg "update-right!"))
                            right-box
                        )
                        (else #f)
                    )
                ))
            )
            (lambda msg
                (let*
                    (
                        (mthd (1st msg))
                        (box-to-use (get-box mthd))
                        (method-to-call (getbox-msg mthd))
                        (call-args (cons box-to-use (cons method-to-call (cdr msg))))
                    )
                    (display "\ninside box maker. call args: ")
                    (display call-args)(newline)

                    (if box-to-use
                        (apply send call-args)
                        (apply delegate (cons base-object msg))
                    )
                )
           )
        )
    )
)
