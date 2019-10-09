(define last-pair
    (lambda (x)
        (if (pair? (cdr x))
            (last-pair (cdr x))
            x
        )
    )
)

(define append!
    (lambda (ls1 ls2)
        (if (pair? ls1)
            (begin
                (set-cdr! (last-pair ls1) ls2)
                ls1
            )
            ls2
        )
    )
)

; ex11-24
(let
    ((x (cons 1 2)))
    (let
        ((y (cons 3 x)))
        (let
            ((w (cons y x)))
            (let
                ((y (cons 1 w)))
                (set-car! y x)
            )
        )
    )
)

; ex11.13b
(define has-cycle?
    (lambda (ls)
        (or
            (eq? (car ls) ls)
            (eq? (cdr ls) ls)
        )
    )
)

; ex11-13c
(define remove-cycle
    (lambda (ls)
        (cond
            ((null? ls) ls)
            ((eq? (car ls) ls)
                (set-car! ls '())
                (remove-cycle (cdr ls))
            )
            ((eq? (cdr ls) ls)
                (set-cdr! ls '())
                ls
            )
            ((pair? (car ls))
                (set-car! ls (remove-cycle (car ls)))
                ; (set-cdr! ls (remove-cycle (cdr ls)))
                (cons (car ls) (remove-cycle (cdr ls)))
            )
            ((pair? (cdr ls))
                ; (set-cdr! ls (remove-cycle (cdr ls)))
                (cons (car ls) (remove-cycle (cdr ls)))
            )
            (else
                (cons (car ls) (remove-cycle (cdr ls)))
            )
        )
    )
)
