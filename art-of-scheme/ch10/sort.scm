(load "../ch2/cond.scm")

(define insertsort
    (lambda (ls)
        (if (singleton-list? ls)
            ls
            (insert (car ls) (insertsort (cdr ls)))
        )
    )
)

(define insert
    (lambda (a ls)
        (cond
            ((null? ls) (cons a '()))
            ((< a (car ls)) (cons a ls))
            (else (cons (car ls) (insert a (cdr ls))))
        )
    )
)
(define vector-insertsort
    (lambda (vec)
        (let
            ((v (vector-copy vec)))
            (vector-insertsort! v)
            v
        )
    )
)

(define vector-insertsort!
    (lambda (v)
        (let
            ((size (vector-length v)))
            (letrec
                ((sortloop (lambda (k)
                    (if (< k size)
                        (begin
                            (vector-insert! k v)
                            (sortloop (1+ k))
                        )
                    )
                )))
                (sortloop 1)
            )
        )
    )
)

(define vector-insert!
    (lambda (k vec)
        (let
            ((val (vector-ref vec k)))
            (letrec
                ((insert-h (lambda (m)
                    (if (zero? m)
                        (vector-set! vec 0 val)
                        (let
                            ((comp (vector-ref vec (1- m))))
                            (if (< val comp)
                                (begin
                                    (vector-set! vec m comp)
                                    (insert-h (1- m))
                                )
                                (vector-set! vec m val)
                            )
                        )
                    )
                )))
                (insert-h k)
            )
        )
    )
)
