(define fib
  (lambda (n)
    (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2)))
    )
  )
)

(define calls-fib
  (lambda (n)
    (cond
      ((or (zero? n) (= n 1)) 1)
      (else
        (1+ (+ (calls-fib (1- n)) (calls-fib (- n 2))))
      )
    )
  )
)

(define adds-fib
  (lambda (n)
    (cond
      ((or (zero? n) (= n 1)) 0)
      (else
        (1+ (+ (adds-fib (- n 1)) (adds-fib (- n 2))))
      )
    )
  )
)

(define fib-it
  (lambda (n acc1 acc2)
    (if (= n 1)
      acc2
      (fib-it (1- n) acc2 (+ acc1 acc2))
    )
  )
)
