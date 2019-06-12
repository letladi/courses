(define remove-leftmost
  (lambda (item ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) item) (cdr ls))
      ((pair? (car ls))
        (let ((rem-list (remove-leftmost item (car ls))))
          (cons rem-list (if (equal? (car ls) rem-list)
             (remove-leftmost item (cdr ls))
             (cdr ls)
          ))
        )
      )
      (else
        (cons (car ls) (remove-leftmost item (cdr ls)))
      )
    )
  )
)

(letrec ((fact (lambda (n)
  (if (zero? n)
    1
    (* n (fact (1- n)))
  ))
))
  (fact 4)
)

(letrec (
  (even? (lambda (x) (or (zero? x) (odd? (1- x))) ) )
  (odd? (lambda (x) (and (not (zero? x)) (even? (1- x)))))
  )
  (display (odd? 17))
)
