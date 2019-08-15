(define append
  (lambda (ls1 ls2)
    (if (null? ls1)
      ls2
      (cons (car ls1) (append (cdr ls1) ls2))
    )
  )
)
