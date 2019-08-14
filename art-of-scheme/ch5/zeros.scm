(define list-of-zeros
  (lambda (n)
    (cond
      ((zero? n) '())
      (else (cons 0 (list-of-zeros (1- n))))
    )
  )
)
