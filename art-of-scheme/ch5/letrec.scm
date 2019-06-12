(define fact
  (lambda (n)
    (letrec (
      (fact-it (lambda (k acc)
        (if (zero? k)
          acc
          (fact-it (1- k) (* k acc))
        )
      )
      )
    )
      (fact-it n 1)
    )
  )
)

(define swapper
  (lambda (x y ls)
    (letrec
      (
        (swap (lambda (ls*)
          (cond
            ((null? ls*) '())
            ((equal? (car ls*) x) (cons y (swap (cdr ls*))))
            ((equal? (car ls*) y) (cons x (swap (cdr ls*))))
            (else (cons (car ls*) (swap (cdr ls*))))
          )
        ))
      )
      (swap ls)
    )
  )
)
