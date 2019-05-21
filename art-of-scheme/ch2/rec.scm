; (define last-item
;   (lambda (ls)
;     (cond
;       ((null? (cdr ls)) (car ls))
;       (else (last-item (cdr ls)))
;     )
;   )
; )

(define last-item
  (lambda (ls)
    (if (null? (cdr ls))
      (car ls)
      (last-item (cdr ls))
    )
  )
)

; (define member?
;   (lambda (item ls)
;     (cond
;       ((null? ls) #f)
;       (else
;         (or (equal? (car ls) item) (member? item (cdr ls)))
;       )
;     )
;   )
; )

(define member?
  (lambda (item ls)
    (if (null? ls)
      #f
      (or (equal? (car ls) item) (member? item (cdr ls)))
    )
  )
)

; (define remove-1st
;   (lambda (item ls)
;     (cond
;       ((null? ls) '())
;       ((equal? item (car ls)) (cdr ls))
;       (else (cons (car ls) (remove-1st item (cdr ls))))
;     )
;   )
; )

(define remove-1st
  (lambda (item ls)
    (if (null? ls)
      '()
      (if (equal? item (car ls))
        (cdr ls)
        (cons (car ls) (remove-1st item (cdr ls)))
      )
    )
  )
)

(define remove-last
  (lambda (ls)
    (if (null? (cddr ls))
      (cons (car ls) '())
      (cons (car ls) (mystery (cdr ls)))
    )
  )
)

(define subst-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old) (cons new (cdr ls)))
      (else
        (cons (car ls) (subst-1st new old (cdr ls)))
      )
    )
  )
)

(define substq-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((eq? (car ls) old) (cons new (cdr ls)))
      (else
        (cons (car ls) (subst-1st new old (cdr ls)))
      )
    )
  )
)

(define substv-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((eqv? (car ls) old) (cons new (cdr ls)))
      (else
        (cons (car ls) (subst-1st new old (cdr ls)))
      )
    )
  )
)

(define insert-left-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old) (cons new ls))
      (else
        (cons (car ls) (insert-left-1st new old (cdr ls)))
      )
    )
  )
)

(define list-of-first-items
  (lambda (ls)
    (cond
      ((null? ls) '())
      (else (cons (caar ls) (list-of-first-items (cdr ls))))
    )
  )
)

(define replace
  (lambda (new-item ls)
    (cond
      ((null? ls) '())
      (else
        (cons new-item (replace new-item (cdr ls)))
      )
    )
  )
)

(define remove-2nd
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item) (cons (car ls) (remove-1st item (cdr ls))))
      (else
        (cons (car ls) (remove-2nd item (cdr ls)))
      )
    )
  )
)

(define remove-last
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item)
        (cond
          ((member? item (cdr ls)) (cons (car ls) (remove-last item (cdr ls))))
          (else (cdr ls))
        )
      )
      (else (cons (car ls) (remove-last item (cdr ls))))
    )
  )
)

(define sandwich-1st
  (lambda (a b ls)
    (cond
      ((null? ls) '())
      ((null? (cdr ls)) ls)
      ((and (equal? b (car ls)) (equal? b (cadr ls))) (cons b (cons a (cdr ls))))
      (else (cons (car ls) (sandwich-1st a b (cdr ls))))
    )
  )
)

; cond list-of-symbols?
; (define list-of-symbols?
;   (lambda (ls)
;       (cond
;         ((null? ls) #t)
;         ((not (symbol? (car ls))) #f)
;         (else (list-of-symbols? (cdr ls)))
;       )
;   )
; )

; if list-of-symbols?
; (define list-of-symbols?
;   (lambda (ls)
;     (if (null? ls)
;       #t
;       (if (not (symbol? (car ls)))
;         #f
;         (list-of-symbols? (cdr ls))
;       )
;     )
;   )
; )

; "and"/"or" list-of-symbols?
(define list-of-symbols?
  (lambda (ls)
    (or
      (null? ls)
      (and
        (symbol? (car ls))
        (list-of-symbols? (cdr ls))
      )
    )
  )
)

(define all-same?
  (lambda (ls)
    (cond
      ((or (null? ls) (null? (cdr ls))) #t)
      (else
        (and
          (equal? (car ls) (cadr ls))
          (all-same? (cdr ls))
        )

      )
    )
  )
)
