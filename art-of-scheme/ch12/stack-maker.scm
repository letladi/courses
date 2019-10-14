(load "ch12/box.scm")

(define stack-maker
    (lambda ()
        (let
            ((stk '()))

            (lambda msg
                (case (1st msg)
                    ((type) "stack")
                    ((empty?) (null? stk))
                    ((push!) (for-effect-only
                        (set! stk (cons (2nd msg) stk))
                    ))
                    ((top) (if (null? stk)
                        (throw "top: the stack is empty.")
                            (car stk)
                    ))
                    ((pop!) (for-effect-only
                        (if (null? stk)
                            (throw "pop!: The stack is empty.")
                            (set! stk (cdr stk))
                        )
                    ))
                    ((size) (length stk))
                    ((print) (display "TOP: ")
                        (for-each
                            (lambda (x)
                                (display x)
                                (display " ")
                            )
                            stk
                        )
                        (newline)
                    )
                    (else (delegate base-object msg))
                )
            )
        )
    )
)

(define is-valid-exp?
    (lambda (ls)
        (letrec
            (
                (is-left-parens? (lambda (c)
                    (case c
                        (("(" "{" "[") #t)
                        (else #f)
                    )
                ))
                (is-right-parens? (lambda (c)
                    (case c
                        ((")" "}" "]") #t)
                        (else #f)
                    )
                ))
                (match-helper (lambda (c1 c2 l-c r-c)
                    (or
                        (and (string=? c1 l-c) (string=? c2 r-c))
                        (and (string=? c1 r-c) (string=? c2 l-c))
                    )
                ))
                (parens-match? (lambda (c1 c2)
                    (or
                        (match-helper c1 c2 "(" ")")
                        (match-helper c1 c2 "{" "}")
                        (match-helper c1 c2 "[" "]")
                    )
                ))
                (stk (stack-maker))
                (evaluate (lambda (ls)
                    (cond
                        ((null? ls) #t)
                        (else
                            (let
                                ((item (1st ls)))
                                (cond
                                    ((is-left-parens? item)
                                        (send stk 'push! item)
                                        (evaluate (cdr ls))
                                    )
                                    ((is-right-parens? item)
                                        (let*
                                            (
                                                (matching-item (send stk 'top))
                                                (items-match? (parens-match? item matching-item))
                                            )
                                            (if items-match?
                                                (begin
                                                    (send stk 'pop!)
                                                    (evaluate (cdr ls))
                                                )
                                                #f
                                            )
                                        )
                                    )
                                    (else (evaluate (cdr ls)))
                                )
                            )
                        )
                    )
                ))
            )
            (evaluate ls)
        )
    )
)
