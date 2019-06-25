(define zero-poly '(0))

(define list-of-zeroes
  (lambda (n)
    (cond
      ((zero? n) '())
      (else (cons 0 (list-of-zeroes (1- n))))
    )
  )
)

(define degree
  (lambda (poly)
    (1- (length poly))
  )
)

(define leading-coef
  (lambda (poly)
    (car poly)
  )
)

(define rest-of-poly
  (lambda (poly)
    (cond
      ((zero? (degree poly)) zero-poly)
      ((zero? (leading-coef (cdr poly))) (rest-of-poly (cdr poly)))
      (else (cdr poly))
    )
  )
)

(define poly-cons
  (lambda (deg coef poly)
    (let ((deg-p (degree poly)))
      (cond
        ((and (zero? deg) (equal? poly zero-poly)) (list coef))
        ((>= deg-p deg)
          (begin
            (display "poly-cons: Degree too high in ")
            (display poly)
            (newline)
         )
       )
       ((zero? coef) poly)
       (else
         (cons
           coef
           (append (list-of-zeroes (1- (- deg deg-p))) poly)
         )
       )
      )
    )
  )
)

(define zero-poly?
  (lambda (poly)
    (and
      (zero? (degree poly))
      (zero? (leading-coef poly))
    )
  )
)

(define make-term
  (lambda (def coef)
    (poly-cons deg coef zero-poly)
  )
)

(define leading-term
  (lambda (poly)
    (make-term (degree poly) (leading-coef poly))
  )
)

(define p+
  (lambda (poly1 poly2)
    (cond
      ((zero-poly? poly1) poly2)
      ((zero-poly? poly2) poly1)
      (else
        (let (
               (n1 (degree poly1))
               (n2 (degree poly2))
               (a1 (leading-coef poly1))
               (a2 (leading-coef poly2))
               (rest1 (rest-of-poly poly1))
               (rest2 (rest-of-poly poly2))
            )
            (cond
              ((> n1 n2) (poly-cons n1 a1 (p+ rest1 poly2)))
              ((< n1 n2) (poly-cons n2 a2 (p+ poly1 rest2)))
              (else
                (poly-cons n1 (+ a1 a2) (p+ rest1 rest2))
              )
            )
        )
      )
    )
  )
)

(define p*
  (letrec
    (
      (t* (lambda (trm poly)
        (if (zero-poly? poly)
          zero-poly
          (poly-cons
            (+ (degree trm) (degree poly))
            (* (leading-coef trm) (leading-coef poly))
            (t* trm (rest-of-poly poly))
          )
        )
      ))
    )

    (lambda (poly1 poly2)
        (letrec
          (
            (p*-helper (lambda (p1)
              (if (zero-poly? p1)
                zero-poly
                (p+
                  (t* (leading-term p1) poly2)
                  (p*-helper (rest-of-poly p1))
                )
              )
            ))
          )

          (p*-helper poly1)
        )
    )
  )
)

(define negative-poly
  (lambda (poly)
    (let ((poly-negative-one (make-term 0 -1)))
      (p* poly-negative-one poly)
    )
  )
)

(define p-
  (lambda (poly1 poly2)
    (p+ poly1 (negative-poly poly2))
  )
)

(define poly-value
  (lambda (poly num)
    (letrec
      (
        (pvalue (lambda (p)
          (let ((n (degree p)))
            (if (zero? n)
              (leading-coef p)
              (let ((rest (rest-of-poly p)))
                (if (< (degree rest) (1- n))
                  (pvalue
                    (poly-cons
                      (1- n)
                      (* num (leading-coef p))
                      rest
                    )
                  )
                  (pvalue
                    (poly-cons
                      (1- n)
                      (+
                        (* num (leading-coef p))
                        (leading-coef rest)
                      )
                      (rest-of-poly rest)
                    )
                  )
                )
              )
            )
          )
        ))
      )

      (pvalue poly)
    )
  )
)
