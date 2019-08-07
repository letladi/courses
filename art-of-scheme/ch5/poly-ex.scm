(load "poly.scm")

(define p1
  (poly-cons 4 5
    (poly-cons 3 -7
      (poly-cons 1 2
        (poly-cons 0 -4 the-zero-poly)
      )
    )
  )
)

(define p2
  (poly-cons 3 1
    (poly-cons 2 6
      (poly-cons 1 -3 the-zero-poly)
    )
  )
)
