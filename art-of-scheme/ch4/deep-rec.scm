(define count-all
  (lambda (ls)
    (cond
      ((null? ls) 0)
      ((pair? (car ls))
        (+ (count-all (car ls)) (count-all (cdr ls)))
      )
      (else
        (1+ (count-all (cdr ls)))
      )
    )
  )
)

(define remove-all
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item) (remove-all item (cdr ls)))
      ((pair? (car ls))
        (cons (remove-all item (car ls)) (remove-all item (cdr ls)))
      )
      (else
        (cons (car ls) (remove-all item (cdr ls)))
      )
    )
  )
)

(define reverse-all
  (lambda (ls)
    (cond
      ((null? ls) '())
      ((pair? (car ls))
        (append (reverse-all (cdr ls))
          (list (reverse-all (car ls)))
        )
      )
      (else
        (append (reverse-all (cdr ls))
          (list (car ls))
        )
      )
    )
  )
)

; alternative definition of reverse-all
; (define reverse-all
;   (lambda (ls)
;     (if (null? ls)
;       '()
;       (append
;         (reverse-all (cdr ls))
;         (list (if (pair? (car ls))
;           (reverse-all (car ls))
;           (car ls)
;         ))
;       )
;     )
;   )
; )

(define subst-all
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old)
        (cons new (subst-all new old (cdr ls)))
      )
      ((pair? (car ls))
        (cons
          (subst-all new old (car ls))
          (subst-all new old (cdr ls))
        )
      )
      (else
        (cons
          (car ls)
          (subst-all new old (cdr ls))
        )
      )
    )
  )
)


(define substq-all
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((eq? (car ls) old)
        (cons new (subst-all new old (cdr ls)))
      )
      ((pair? (car ls))
        (cons
          (subst-all new old (car ls))
          (subst-all new old (cdr ls))
        )
      )
      (else
        (cons
          (car ls)
          (subst-all new old (cdr ls))
        )
      )
    )
  )
)

(define insert-left-all
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? old (car ls))
        (cons new (cons old (insert-left-all new old (cdr ls))))
      )
      ((pair? (car ls))
        (cons
          (insert-left-all new old (car ls))
          (insert-left-all new old (cdr ls))
        )
      )
      (else
        (cons (car ls) (insert-left-all new old (cdr ls)))
      )
    )
  )
)

(define sum-all
  (lambda (ls)
    (cond
      ((null? ls) 0)
      ((pair? (car ls))
        (+
          (sum-all (car ls))
          (sum-all (cdr ls))
        )
      )
      (else
        (+
          (car ls)
          (sum-all (cdr ls))
        )
      )
    )
  )
)

(define count-parens-all
  (lambda (ls)
    (cond
      ((null? ls) 2)
      ((pair? (car ls))
        (+
          (count-parens-all (car ls))
          (count-parens-all (cdr ls))
        )
      )
      ((null? (car ls))
        (+
          (count-parens-all (car ls))
          (count-parens-all (cdr ls))
        )
      )
      (else
        (count-parens-all (cdr ls))
      )
    )
  )
)

(define count-background-all
  (lambda (item ls)
    (cond
      ((null? ls) 0)
      ((pair? (car ls))
        (+
          (count-background-all item (car ls))
          (count-background-all item (cdr ls))
        )
      )
      ((not (eq? (car ls) item))
        (1+ (count-background-all item (cdr ls)))
      )
      (else (count-background-all item (cdr ls)))
    )
  )
)

(define leftmost
  (lambda (ls)
    (cond
      ((pair? (car ls)) (leftmost (car ls)))
      (else (car ls))
    )
  )
)

(define rightmost
  (lambda (ls)
    (cond
      ((null? (cdr ls)
        (if (pair? (car ls)))
      )
    )
  )
)
