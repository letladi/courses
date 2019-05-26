(define remove-1st-trace
  (lambda (item ls)
    (cond
      ((entering (null? ls) ls 1) (leaving '() 1))
      ((entering (equal? (car ls) item) ls 2) (leaving (cdr ls) 2))
      ((entering 'else ls 3) (leaving (cons (car ls) (remove-1st-trace item (cdr ls))) 3))
    )
  )
)

(define entering
  (lambda (test input cond-clause-number)
    (begin
      (if test
        (begin
          (newline)
          (display "Entering cond-clause-")
          (display cond-clause-number)
          (display ", with input = ")
          (display input)
        )
      )
      test
    )
  )
)

(define leaving
  (lambda (result cond-clause-number)
    (begin
      (newline)
      (display "Leaving cond-clause-")
      (display cond-clause-number)
      (display ", with result = ")
      (display result)
      (newline)
      result
    )
  )
)

(define swapper
  (lambda (x y ls)
    (cond
      ((null? ls) '())
      (else
        (cons
          (swap-tester x y (car ls))
          (swapper x y (cdr ls))
        )
      )
    )
  )
)

(define swap-tester
  (lambda (x y a)
    (cond
      ((equal? a x) y)
      ((equal? a y) x)
      (else a)
    )
  )
)

(define enter-clause
  (lambda (test x y ls clause-num)
    (begin
      (if test
        (begin
          (display "entering clause-")
          (display clause-num)
          (display ", with input: x = ")
          (display x)
          (display "; y = ")
          (display y)
          (display "; ls = ")
          (display ls)
          (newline)
        )
      )
      test
    )
  )
)

(define leave-clause
  (lambda (result cond-num)
    (begin
      (newline)
      (display "leaving cond-")
      (display cond-num)
      (display ", with result = ")
      (display result)
      (newline)
      result
    )
  )
)

(define swapper-trace
  (lambda (x y ls)
    (cond
      ((enter-clause (null? ls) x y ls 1) (leave-clause '() 1))
      ((enter-clause (equal? (car ls) x) x y ls 2) (leave-clause (cons y (swapper-trace x y (cdr ls))) 2))
      ((enter-clause (equal? (car ls) y) x y ls 3) (leave-clause (cons x (swapper-trace x y (cdr ls))) 3))
      ((enter-clause 'else x y ls "else")
       (leave-clause (cons (car ls) (swapper-trace x y (cdr ls)))  "else")
      )
    )
  )
)
