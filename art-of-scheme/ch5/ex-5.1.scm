(let ((a 5))
  (let ((fun (lambda (x) (max x a))))
    (let ((a 10) (x 20))
      (fun 1)
    )
  )
)

(let ((a 1) (b 2))
  (let ((b 3) (c (+ a b)))
    (let ((b 5))
      (cons a (cons b (cons c '())))
    )
  )
)

(letrec
  ((loop
    (lambda (n k)
      (cond
        ((zero? k) n)
        ((< n k) (loop k n))
        (else (loop k (remainder n k)))
      )
    )
  ))
  (loop 9 12)
)

(letrec
  ((loop (lambda (n)
    (if (zero? n)
      0
      (+ (remainder n 10) (loop (quotient n 10)))
    )
  )
  ))
  (loop 1234)
)

(letrec (
    (mystery
      (lambda (tuple odds evens)
        (if (null? tuple)
          (append odds evens)
          (let ((next-int (car tuple)))
            (if (odd? next-int)
              (mystery (cdr tuple) (cons next-int odds) evens)
              (mystery (cdr tuple) odds (cons next-int evens))
            )
          )
        )
      )
    )
  )
  (mystery '(3 16 4 7 9 12 24) '() '())
)

(define mystery
  (lambda (n)
    (letrec
      ((mystery-helper
        (lambda (n s)
          (cond
            ((zero? n) (list s))
            (else
              (append
                (mystery-helper (1- n) (cons 0 s))
                (mystery-helper (1- n) (cons 1 s))
              )
            )
          )
        )
      ))
      (mystery-helper n '())
    )
  )
)

(define insert-left-all
  (lambda (new old ls)
    (letrec
      ((insert-left-all-helper
        (lambda (ls)
          (cond
            ((null? ls) '())
            ((equal? (car ls) old) (cons new (cons old (insert-left-all-helper (cdr ls)))))
            ((pair? (car ls)) (cons
              (insert-left-all-helper (car ls))
              (insert-left-all-helper (cdr ls))
            ))
            (else
              (cons (car ls) (insert-left-all-helper (cdr ls)))
            )
          )
        )
      ))
      (insert-left-all-helper ls)
    )
  )
)

(define fib
  (lambda (n)
    (letrec (
      (fib-it
        (lambda (n total)
          (if (zero? n)
            total
            (fib-it (1- n) (* n total))
          )
        )
      )
    )
    (fib-it n 1)
    )
  )
)

(define list-ref
  (lambda (ls n)
    (letrec
      ((list-ref-helper
        (lambda (ls2 count)
          (cond
            ((null? ls2)
              (begin
                (display "list-ref: Index ")
                (display n)
                (display " out of range for list ")
                (display ls)
              )
            )
            ((eq? count n) (car ls2))
            (else
              (list-ref-helper (cdr ls2) (1+ count))
            )
          )
        )
      ))
      (list-ref-helper ls 0)
    )
  )
)
