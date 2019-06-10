(define reverse-it
  (lambda (ls acc)
    (if (null? ls)
      acc
      (reverse-it (cdr ls) (cons (car ls) acc))
    )
  )
)
