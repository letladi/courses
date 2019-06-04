(define depth
  (lambda (item)
    (if (pair? item)
      (max
        (1+ (depth (car item)))
        (depth (cdr item))
      )
      0
    )
  )
)

(define flatten
  (lambda (ls)
    (cond
      ((null? ls) '())
      ((pair? (car ls))
        (append (flatten (car ls)) (flatten (cdr ls)))
      )
      (else
        (cons (car ls) (flatten (cdr ls)))
      )
    )
  )
)

(define remove-leftmost
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item) (cdr ls))
      ((not (pair? (car ls)))
        (cons (car ls) (remove-leftmost item (cdr ls)))
      )
      ((member-all? item (car ls))
        (cons (remove-leftmost item (car ls)) (cdr ls))
      )
      (else
        (cons (car ls) (remove-leftmost item (cdr ls)))
      )
    )
  )
)

(define member-all?
  (lambda (item ls)
    (if (null? ls)
      #f
      (or
        (equal? (car ls) item)
        (and
          (not (pair? (car ls)))
          (member-all? item (cdr ls))
        )
        (and
          (pair? (car ls))
          (or
            (member-all? item (car ls))
            (member-all? item (cdr ls))
          )
        )
      )
    )
  )
)
