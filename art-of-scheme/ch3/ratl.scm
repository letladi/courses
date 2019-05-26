(define numr
  (lambda (rtl)
    (car rtl)
  )
)

(define denr
  (lambda (rtl)
    (cdr rtl)
  )
)

(define rzero?
  (lambda (rtl)
    (zero? (numr rtl))
  )
)

(define r+
  (lambda (x y)
    (make-ratl
      (+ (* (numr x) (denr y)) (* (numr y) (denr x)))
      (* (denr x) (denr y))
    )
  )
)

(define r*
  (lambda (x y)
    (make-ratl
      (* (numr x) (numr y))
      (* (denr x) (denr y))
    )
  )
)

(define r-
  (lambda (x y)
    (make-ratl
      (- (* (numr x) (denr y)) (* (numr y) (denr x)))
      (* (denr x) (denr y))
    )
  )
)

(define rinvert
  (lambda (rtl)
    (if (rzero? rtl)
      (begin
        (display "rinvert: Cannot invert ")
        (display rtl)
      )
      (make-ratl (denr rtl) (numr rtl))

    )
  )
)

(define r=
  (lambda (x y)
    (= (* (numr x) (denr y)) (* (numr y) (denr x)))
  )
)

(define rpositive?
  (lambda (rtl)
    (same-sign? (numr rtl) (denr rtl))
  )
)

(define r>
  (lambda (x y)
    (rpositive? (r- x y))
  )
)

(define r<
  (lambda (x y)
    (not (r> x y))
  )
)

(define max
  (lambda (x y)
    (extreme-value > x y)
  )
)

(define min
  (lambda (x y)
    (extreme-value < x y)
  )
)

(define rmax
  (lambda (x y)
    (extreme-value r> x y)
  )
)

(define rmin
  (lambda (x y)
    (extreme-value r< x y)
  )
)

(define extreme-value
  (lambda (pred x y)
    (if (pred x y)
      x
      y
    )
  )
)

(define rprint
  (lambda (rtl)
    (display (numr rtl))
    (display "/")
    (display (denr rtl))
  )
)

(define rminus
  (lambda (rtl)
    (make-ratl (- (denr rtl)) (numr rtl))
  )
)

(define same-sign?
  (lambda (x y)
    (or
      (and (positive? x) (positive? y))
      (and (negative? x) (negative? y))
    )
  )
)

(define rabs
  (lambda (rtl)
    (if (rpositive? rtl)
      rtl
      (rminus rtl)
    )
  )
)

(define make-ratl
  (lambda (int1 int2)
    (if (zero? int2)
      (display "make-ratl: The denominator cannot be zero.")

      (cons int1 int2)
    )
    (cond
      ((zero? int2) (display "make-ratl: The denominator cannot be zero."))
      ((= (gcd int1 int2) 1) (cons int1 int2))
      (else
          (cons (/ int1 (gcd int1 int2)) (/ int2 (gcd int1 int2)))    
      )
    )
  )
)
