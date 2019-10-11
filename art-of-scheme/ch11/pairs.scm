(load "util.scm")

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
                (cons (car ls) (remove-cycle (cdr ls)))
            )
            ((pair? (cdr ls))
                (cons (car ls) (remove-cycle (cdr ls)))
            )
            (else
                (cons (car ls) (remove-cycle (cdr ls)))
            )
        )
    )
)

(define mystery
    (lambda (x)
        (let
            ((box (last-pair x)))
            (set-cdr! box x)
            x
        )
    )
)
(define ans (mystery (list 'a 'b 'c 'd)))
; the is x = (a b c d x), a list whose last item (cdr refers to itself)

; (define get-cycles
;     (lambda (ls)
;         (letrec
;             ((get-cycle-indices (lambda (ls-search ls-to-search ls-search-i count)
;                 (if (= ls-search-i count)
;                     (get-cycle-indices ls-search (cdr ls-to-search) ls-search-i (1+ count))
;                     (cond
;                         ((null? ls-to-search) '())
;                         ((and (pair? (car ls-to-search)) (eq? ls-search (car ls-to-search)))
;                             (if (eq? ls-search (cdr ls-to-search))
;                                 (cons
;                                     (list ls-search-i count)
;                                     (cons
;                                         (list ls-search-i (1+ count))
;                                         '()
;                                     )
;                                 )
;                                 (cons
;                                     (list ls-search-i count)
;                                     (get-cycle-indices ls-search (cdr ls-to-search) ls-search-i (1+ count))
;                                 )
;                             )
;                         )
;                         ((eq? ls-search (cdr ls-to-search))
;                             (cons
;                                 (list ls-search-i (1+ count))
;                                 '()
;                             )
;                         )
;                         (else
;                             (get-cycle-indices ls-search (cdr ls-to-search) ls-search-i (1+ count))
;                         )
;                     )
;                 )
;             )))
;
;             (get-cycle-indices ls ls -1 0)
;         )
;     )
; )

; (define cycle?
;     (lambda (ls)
;         (if (null? ls)
;             #f
;             (letrec
;                 ((contains? (lambda (a ls)
;                     (cond
;                         ((null? ls) #f)
;                         (else
;                             (or
;                                 (eq? a (car ls))
;                                 (contains? a (cdr ls))
;                             )
;                         )
;                     )
;                 )))
;                 (or
;                     (contains? ls ls)
;                     (cycle? (cdr ls))
;                 )
;             )
;         )
;     )
; )

(define efface
    (lambda (x ls)
        (cond
            ((null? ls) '())
            ((equal? (car ls) x) (cdr ls))
            (else
                (let
                    ((z (efface x (cdr ls))))
                    (set-cdr! ls z)
                    ls
                )
            )
        )
    )
)

(define test-efface
    (lambda ()
        (let
            ((x (cons 1 '())))
            (let
                ((y (cons 2 x)))
                (let
                    ((z (cons 3 y)))
                    (let
                        ((a (cons 4 z)) (a* (cons 40 z)))
                        (let
                            ((b (cons 5 a)) (b* (cons 50 a)))
                            (let
                                ((c (cons 6 b)) (c* (cons 60 b)))
                                (writeln x y z a a* b b* c c*)
                                (efface 3 c)
                                (writeln x y z a a* b b* c c*)
                            )
                        )
                    )
                )
            )
        )
    )
)
