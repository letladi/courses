(load "stack.scm")

(define member?
    (lambda (item ls)
        (let
            ((goto (lambda (label) (label))))
            (letrec
                (
                    (start (lambda ()
                        (cond
                            ((null? ls) #f)
                            ((equal? (car ls) item ) #t)
                            (else (goto reduce))
                        )
                    ))
                    (reduce (lambda ()
                        (set! ls (cdr ls))
                        (goto start)
                    ))
                )
                (goto start)
            )
        )
    )
)

(define while-proc
    (lambda (pred-th body-th)
        (letrec
            ((loop (lambda ()
                (if (pred-th)
                    (begin
                        (body-th)
                        (loop)
                    )
                )
            )))

            (loop)
        )
    )
)

(define member?
    (lambda (item ls)
        (let
            ((ans #f))
            (while-proc
                (lambda () (not (or (null? ls) ans)))
                (lambda ()
                    (if (equal? (car ls) item)
                        (set! ans #t)
                        (set! ls (cdr ls))
                    )
                )
            )
            ans
        )
    )
)

(define swapper
    (lambda (a b ls)
        (letrec
            ((loop (lambda (ls*)
                (cond
                    ((null? ls*) '())
                    ((equal? (car ls*) a) (cons b (loop (cdr ls*))))
                    ((equal? (car ls*) b) (cons a (loop (cdr ls*))))
                    (else
                        (cons (car ls*) (loop (cdr ls*)))
                    )
                )
            )))

            (loop ls)
        )
    )
)

(define swapper
    (lambda (a b ls)
        (let
            ((ls* ls) (ans '()))
            (while-proc
                (lambda () (not (null? ls*)))
                (lambda ()
                    (cond
                        ((equal? (car ls*) a) (push! b))
                        ((equal (car ls*) b) (push! a))
                        (else (push! (car ls*)))
                    )
                    (print-stack)
                    (set! ls* (cdr ls*))
                )
            )
            (while-proc
                (lambda () (not (empty?)))
                (lambda ()
                    (set! ans (cons (top) ans))
                    (display "Answer = ")
                    (display ans)
                    (pop!)
                    (print-stack)
                )
            )
            ans
        )
    )
)
