(define add
    (letrec
        ((list-add (lambda (ls)
            (if (null? ls)
                0
                (+ (car ls) (list-add (cdr ls)))
            )
        )))
        (lambda args (list-add args))
    )
)

(define list (lambda args args))

(define writeln
    (lambda args
        (for-each display args)
        (newline)
    )
)

(define error
    (lambda args
        (display "Error: ")
        (for-each (lambda (value) (display " ") (display value)) args)
        (newline)
        (reset)
    )
)

(define add
    (lambda args
        (if (null? args)
            0
            (+ (car args) (apply add (cdr args)))
        )
    )
)

(define compose
    (lambda (f g)
        (lambda (x)
            (f (g x))
        )
    )
)

(define plus
    (lambda (x y)
        (if (zero? y)
            x
            (1+ (plus x (1- y)))
        )
    )
)

(define times
    (lambda (x y)
        (if (zero? y)
            0
            (plus x (times x (1- y)))
        )
    )
)

(define exponent
    (lambda (x y)
        (if (zero? y)
            1
            (times x (exponent x (1- y)))
        )
    )
)

(define super
    (lambda (x y)
        (if (zero? y)
            1
            (exponent x (super x (1- y)))
        )
    )
)

(define superduper
    (lambda (x y)
        (if (zero? y)
            1
            (super x (superduper x (1- y)))
        )
    )
)

(define super-order
    (lambda (n)
        (cond
            ((= n 1) plus)
            ((= n 2) times)
            (else (lambda (x y)
                (cond
                    ((zero? y) 1)
                    (else
                        ((super-order (1- n))
                            x
                        ((super-order n) x (1- y))
                        )
                    )
                )
            ))
        )
    )
)

(define ackermann
    (lambda (n)
        ((super-order n) n n)
    )
)

(define compose3
    (lambda (f g h)
        (compose f (compose g h))
    )
)

(define compose-many
    (lambda args
        (if (= 2 (length args))
            (compose (car args) (cadr args))
            (compose (car args) (apply compose-many (cdr args)))
        )
    )
)

(define subtract
    (lambda (x y)
        (if (zero? y)
            x
            (subtract (1- x) (1- y))
        )
    )
)

(define iota
    (lambda (n)
      (letrec ((iota-helper
                 (lambda (k acc)
                   (cond
                     ((zero? k) (cons 0 acc))
                     (else (iota-helper (1- k) (cons k acc)))
                   ))
              ))

        (iota-helper (1- n) '())
    ))
)
; (letrec ((fact
;             (lambda (n)
;                 (if (zero? n)
;                     1
;                     (* n (fact (1- n)))
;                 )
;             )
;         ))
;     (display (map fact (iota 6)))
; )

(define mystery
    (lambda (len base)
        (letrec
            ((mystery-help (lambda (n s)
                (if (zero? n)
                    (list s)
                    (let
                        ((h (lambda (x)
                            (mystery-help (1- n) (cons x s))
                        )))
                        (apply append (map h (iota base)))
                    )
                )
            )))

            (mystery-help len '())
        )
    )
)

(define map-first-two
    (lambda (proc ls)
        (cond
            ((< (length ls) 2) '())
            (else
                (let
                    (
                        (first-arg (car ls))
                        (second-arg (cadr ls))
                    )

                    (cons
                        (proc first-arg second-arg)
                        (map-first-two proc (cdr ls))
                    )
                )
            )
        )
    )
)

(define reduce
    (lambda (proc ls)
        (if (< (length ls) 2)
            (error "List may not be have less than 2 elements")

            (letrec
                (
                    (reduce-helper (lambda (ls)
                        (cond
                            ((= (length ls) 2) (proc (car ls) (cadr ls)))
                            (else
                                (reduce-helper
                                    (cons
                                        (proc (car ls) (cadr ls))
                                        (cddr ls)
                                    )
                                )
                            )
                        )
                    ))
                )

                (reduce-helper ls)
            )
        )
    )
)

(define andmap
    (lambda (pred ls)
        (letrec
            ((helper (lambda (ls result)
                (cond
                    ((null? ls) (and #t result))
                    ((eq? result #f) #f)
                    (else
                        (helper
                            (cdr ls)
                            (and (pred (car ls)) result)
                        )
                    )
                )
            )))

            (helper (cdr ls) (pred (car ls)))
        )
    )
)

(define map2
    (lambda (proc ls1 ls2)
        (cond
            ((not (= (length ls1) (length ls2)))
                (error "The two lists must be equal in length")
            )
            (else
                (letrec
                    ((helper (lambda (ls1 ls2)
                        (cond
                            ((null? ls1) '())
                            (else
                                (cons
                                    (proc (car ls1) (car ls2))
                                    (helper (cdr ls1) (cdr ls2))
                                )
                            )
                        )
                    )))

                    (helper ls1 ls2)
                )
            )
        )
    )
)

(define ormap
    (lambda (pred ls)
        (if (null? ls)
            #f
            (or (pred (car ls)) (ormap pred (cdr ls)))
        )
    )
)

(define any-null?
    (lambda (pred lol)
        (ormap null? lol)
    )
)

(define map
    (lambda args
        (let
            (
                (proc (car args))
            )

            (letrec
                (
                    (map-simple (lambda (proc ls)
                        (if (null? ls)
                            '()
                            (cons (proc (car ls)) (map proc (cdr ls)))
                        )
                    ))
                    (map-helper (lambda (a*)
                        (if (any-null? a*)
                            '()
                            (cons
                                (apply proc (map-simple car a*))
                                (map-helper (map-simple cdr a*))
                            )
                        )
                    ))
                )

                (map-helper (cdr args))
            )
        )
    )
)

(letrec ((a (let ((a (lambda (b c)
    (if (zero? b) c (a (1- b)))
)))
    (lambda (x) (a x x))
)))
    (display (a 3))
)
