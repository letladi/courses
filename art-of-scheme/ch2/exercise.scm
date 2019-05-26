; ex 2.23
; #t is returned
; 12 is printed
(begin
  (display "(* 3 4) = ")
  (display (* 3 4))
  (= (* 3 4) 12)
)

; (a b c) is returned
; the 3 lines are printed
(begin
  (display "(cons 'a '(b c)) has the value ")
  (display (cons 'a '(b c)))
  (newline)
  (display "(cons 'a '(b c)) has the value ")
  (display '(a b c))
  (newline)
  (display "(cons 'a '(b c)) has the value (a b c)")
  (newline)
  (display (cons 'a '(b c)))
)

; the 3 lines are printed
; "Good-bye. Have a nice day." is returned
(begin
  (display "hello, how are you?")
  (newline)
  (display "Fine, thank you. How are you? Jack")
  (newline)
  (display "Just great! It is good to see you again, Jill")
  (newline)
  "Good-bye. Have a nice day."
)
; if the argument is a symbol, or number, it is returned
; if it is a list, a string showing a copy of the construction of the list
; is returned
(define describe
  (lambda (s)
    (cond
      ((null? s) (quote '()))
      ((number? s) s)
      ((symbol? s) (list 'quote s))
      ((pair? s) (list 'cons (describe (car s)) (describe (cdr s))))
      (else s)
    )
  )
)

; (describe 347) = 347
; (describe 'hello) = hello
; (describe '(1 2 button my shoe)) = (1 2 button my shoe)
; (describe '(a (b c (d e) f g) h)) = (a (b c (d e) f g) h)
