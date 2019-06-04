(define append
  (lambda (ls1 ls2)
    (if (null? ls1)
      ls2
      (cons (car ls1) (append (cdr ls1) ls2))
    )
  )
)

(define reverse
  (lambda (ls)
    (if (null? ls)
      '()
      (append (reverse (cdr ls)) (list (car ls)))
    )
  )
)

(define merge
  (lambda (sorted-ntpl1 sorted-ntpl2)
    (cond
      ((null? sorted-ntpl1) sorted-ntpl2)
      ((null? sorted-ntpl2) sorted-ntpl1)
      ((> (car sorted-ntpl1) (car sorted-ntpl2))
        (cons
          (car sorted-ntpl2)
          (merge sorted-ntpl1 (cdr sorted-ntpl2))
        )
      )
      (else
        (cons
          (car sorted-ntpl1)
          (merge (cdr sorted-ntpl1) sorted-ntpl2)
        )
      )
    )
  )
)

(define even?
  (lambda (int)
    (if (zero? int)
      #t
      (odd? (1- int))
    )
  )
)

(define odd?
  (lambda (int)
    (if (zero? int)
      #f
      (even? (1- int))
    )
  )
)

(define remove
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item) (remove item (cdr ls)))
      (else
        (cons (car ls) (remove item (cdr ls)))
      )
    )
  )
)

(define insert-left
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? old (car ls))
        (cons new (cons old (insert-left new old (cdr ls))))
      )
      (else
        (cons (car ls) (insert-left new old (cdr ls)))
      )
    )
  )
)

(define insert-right
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? old (car ls))
        (cons old (cons new (insert-right new old (cdr ls))))
      )
      (else
        (cons (car ls) (insert-right new old (cdr ls)))
      )
    )
  )
)

(define subst
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old) (cons new (subst new old (cdr ls))))
      (else
        (cons (car ls) (subst new old (cdr ls)))
      )
    )
  )
)

(define deepen-1
  (lambda (ls)
    (cond
      ((null? ls) '())
      (else
        (cons (list (car ls)) (deepen-1 (cdr ls)))
      )
    )
  )
)
