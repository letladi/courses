(define zero-poly?
  (lambda (poly)
    (and
      (zero? (degree poly))
      (zero? (leading-coef poly))
    )
  )
)

(define make-term
  (lambda (deg coef)
    (poly-cons deg coef the-zero-poly)
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
      (else (let (
          (n1 (degree poly1))
          (n2 (degree poly2))
      )
        (cond
          ((> n1 n2)
            (let (
              (a1 (leading-coef poly1))
              (rest1 (rest-of-poly poly1))
              )
              (poly-cons n1 a1 (p+ rest1 poly2))
            )
          )

          ((< n1 n2)
            (let (
                (rest2 (rest-of-poly poly2))
                (a2 (leading-coef poly2))
              )
              (poly-cons n2 a2 (p+ poly1 rest2))
            )
          )

          (else
            (let (
                (a1 (leading-coef poly1))
                (a2 (leading-coef poly2))
                (rest1 (rest-of-poly poly1))
                (rest2 (rest-of-poly poly2))
              )
              (poly-cons n1 (+ a1 a2) (p+ rest1 rest2))
            )
          )
        )
      )
    )
    )
  )
)

(define p*
  (let
    (
      (t* (lambda (trm poly)
            (let
              (
                (deg (degree trm))
                (lc (leading-coef trm))
              )

              (letrec
                (
                  (t*-helper (lambda (poly)
                    (if (zero-poly? poly)
                      the-zero-poly
                      (poly-cons
                        (+ deg (degree poly))
                        (* lc (leading-coef poly))
                        (t*-helper (rest-of-poly poly))
                      )
                    )
                  ))
                )

                (t*-helper poly)
              )
            )
          )
      )
    )

    (lambda (poly1 poly2)
      (letrec
        ((p*-helper (lambda (p1)
          (if (zero-poly? p1)
            the-zero-poly
            (p+
              (t* (leading-term p1) poly2)
              (p*-helper (rest-of-poly p1))
            )
          )
        )))

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

(define pvalue
  (lambda (poly num)
    (letrec
      ((pvalue (lambda (p)
        (let ((n (degree p)))
          (if (zero? n)
            (leading-coef p)
            (let ((rest (rest-of-poly p)))
              (if (< (degree rest) (1- n))
                (pvalue (poly-cons (1- n) (* num (leading-coef p)) rest))
                (pvalue (poly-cons (1- n) (+ (* num (leading-coef p)) (leading-coef rest)) (rest-of-poly rest)))
              )
            )
          )
        )
      )))

      (pvalue poly)

    )
  )
)

(define the-zero-poly '((0 0)))

(define degree
  (lambda (poly)
    (caar poly)
  )
)

(define leading-coef
  (lambda (poly)
    (cadar poly)
  )
)

(define rest-of-poly
  (lambda (poly)
    (if (null? (cdr poly))
      the-zero-poly
      (cdr poly)
    )
  )
)

(define poly-cons
  (lambda (deg coef poly)
    (let ((deg-p (degree poly)))
      (cond
        ((and (zero? deg) (equal? poly the-zero-poly)) (list (list 0 coef)))
        ((>= deg-p deg) (begin
          (newline)
          (display "poly-cons: degree to high in ")
          (display poly)
          (newline)
          ))
        ((zero? coef) poly)
        (else
          (cons (list deg coef) poly)
        )
      )
    )
  )
)

(define divide-term
  (lambda (num den)
    (if (zero? (leading-coef den))
      (begin
        (newline)
        (display "You cannot divide a polynomial term by zero")
        (newline)
      )

      (let (
          (num-coef (leading-coef num))
          (num-deg (degree num))
          (den-coef (leading-coef den))
          (den-deg (degree den))
        )
        (make-term (- num-deg den-deg) (/ num-coef den-coef))
      )
    )
  )
)

(define poly-long-division
  (lambda (num den)
    (letrec
      (
        (den-leading-term (leading-term den))
        (den-degree (degree den))
        (helper (lambda (num quot)
            (cond
              ((< (degree num) den-degree) (list quot num))
              (else
                (letrec* (
                    (num-leading-term (leading-term num))
                    (first-terms-quot (divide-term num-leading-term den-leading-term))
                    (product-of-first-terms-quot-and-den (p* first-terms-quot den))
                    (new-quot (p+ quot first-terms-quot))
                  )
                  (helper (p- num product-of-first-terms-quot-and-den) new-quot)
                )
              )
            )
        ))
      )

      (helper num the-zero-poly)
    )
  )
)

(define poly-quotient
  (lambda (num den)
    (car (poly-long-division num den))
  )
)

(define poly-remainder
  (lambda (num den)
    (cadr (poly-long-division num den))
  )
)
