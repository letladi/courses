(define reverse-it
  (lambda (ls acc)
    (if (null? ls)
      acc
      (reverse-it (cdr ls) (cons (car ls) acc))
    )
  )
)

(define len-it
  (lambda (ls count)
    (if (null? ls)
      count
      (len-it (cdr ls) (1+ count))
    )
  )
)

(define len
  (lambda (ls)
    (len-it ls 0)
  )
)

(define mk-asc-list-of-ints
  (lambda (n)
    (mk-asc-helper n '())
  )
)

(define mk-asc-helper
  (lambda (n ls)
    (if (zero? n)
      ls
      (mk-asc-helper (1- n) (cons n ls))
    )
  )
)

(define mk-desc-list-of-ints
  (lambda (n)
    (mk-desc-helper n 1 '())
  )
)

(define mk-desc-helper
  (lambda (n count ls)
    (if (zero? n)
      ls
      (mk-desc-helper (1- n) (1+ count) (cons count ls))
    )
  )
)

(define occurs
  (lambda (item ls)
    (cond
      ((null? ls) 0)
      ((equal? item (car ls)) (1+ (occurs item (cdr ls))))
      (else (occurs item (cdr ls)))
    )
  )
)

(define occurs-it
  (lambda (item ls count)
    (if (null? ls)
      count
      (occurs-it item (cdr ls)
        (+
          (if (equal? item (car ls))
            1
            0
          )
          count
        )
      )
    )
  )
)
