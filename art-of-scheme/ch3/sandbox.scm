(define harmonic-sum
  (lambda (n)
    (cond
      ((zero? n) 0)
      (else (+ (/ 1 n) (harmonic-sum (1- n))))
    )
  )
)

(define list-of-zeros
  (lambda (n)
    (cond
      ((zero? n) '())
      (else (cons 0 (list-of-zeros (1- n))))
    )
  )
)

(define len
  (lambda (ls)
    (if (null? ls)
      0
      (1+ (len (cdr ls)))
    )
  )
)

(define list-ref
  (lambda (ls n)
    (cond
      ((<= (len ls) n) (error "list-ref: Index" n " out of range for list" ls))
      ((zero? n) (car ls))
      (else (list-ref (cdr ls) (1- n)))
    )
  )
)

(define sum
  (lambda (tup)
    (if (null? tup)
      0
      (+ (car tup) (sum (cdr tup)))
    )
  )
)

(define pairwise-sum
  (lambda (tup1 tup2)
    (cond
      ((null? tup1) '())
      (else (cons (+ (car tup1) (car tup2)) (pairwise-sum (cdr tup1) (cdr tup2)) ))
    )
  )
)

(define pairwise-product
  (lambda (tup1 tup2)
    (cond
      ((null? tup1) '())
      (else
        (cons
          (* (car tup1) (car tup2))
          (pairwise-product (cdr tup1) (cdr tup2))
        )
      )
    )
  )
)

(define dot-product
  (lambda (tup1 tup2)
    (cond
      ((null? tup1) 0)
      (else
        (+
          (* (car tup1) (car tup2))
          (dot-product (cdr tup1) (cdr tup2))
        )
      )
    )
  )
)

(define scale
  (lambda (tup k)
    (cond
      ((null? tup) '())
      (else
        (cons
          (* (car tup) k)
          (scale (cdr tup) k)
        )
      )
    )
  )
)

(define index
  (lambda (a ls)
    (cond
      ((null? ls) -1)
      ((equal? a (car ls)) 0)
      (else
        (1+ (index a (cdr ls)))
      )
    )
  )
)

(define make-list
  (lambda (n item)
    (if (= n 0)
      '()
      (cons item (make-list (1- n) item))
    )
  )
)

(define count-background
  (lambda (a ls)
    (cond
      ((null? ls) 0)
      ((not(equal? (car ls) a)) (1+ (count-background a (cdr ls))))
      (else (count-background a (cdr ls)))
    )
  )
)

(define list-front
  (lambda (ls num)
    (cond
      ((> num (length ls))
        (begin
          (display "Error: length of ")
          (display ls)
          (display " is less than ")
          (display num)
          (display ".")
        )
      )
      (else (list-front-helper ls num))
    )
  )
)

(define list-front-helper
  (lambda (ls num)
    (cond
      ((zero? num) '())
      (else
        (cons (car ls) (list-front-helper (cdr ls) (1- num)))
      )
    )
  )
)

(define wrapa
  (lambda (item num)
    (cond
      ((zero? num) item)
      (else (list (wrapa item (1- num))))
    )
  )
)

(define multiple?
  (lambda (m n)
    (cond
      ((zero? m) #t)
      ((zero? n) #f)
      (else (zero? (mod m n)))
    )
  )
)

(define sum-of-odds
  (lambda (n)
    (sum-of-odds-helper n 0 1)
  )
)

(define sum-of-odds-helper
  (lambda (n count odd-num)
    (cond
      ((= n count) 0)
      (else (+ odd-num (sum-of-odds-helper n (1+ count) (+ odd-num 2))))
    )
  )
)

(define n-tuple->integer
  (lambda (ls)
    (if (null? ls)
      (begin
        (display "Error: bad argument ")
        (display ls)
        (display " to n-tuple->integer")
      )
      (string->number (n-tuple->integer-helper ls))
    )
  )
)

(define n-tuple->integer-helper
  (lambda (ls)
    (cond
      ((null? ls) "")
      (else
        (string-append
          (number->string (car ls))
          (n-tuple->integer-helper (cdr ls))
        )
      )
    )
  )
)
