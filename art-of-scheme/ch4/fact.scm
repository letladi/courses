(define fact
  (lambda (n)
    (fact-it n 1)
  )
)

(define fact-it
  (lambda (n acc)
    (if (zero? n)
      acc
      (fact-it (1- n) (* acc n))
    )
  )
)

(define harmonic-sum
  (lambda (n)
    (harmonic-sum-it n 0)
  )
)

(define harmonic-sum-it
  (lambda (n sum)
    (if (zero? n)
      sum
      (harmonic-sum-it (1- n) (+ sum (/ 1 n)))
    )
  )
)
