(load "ch12/acc.scm")

(define acc-max (accumulator-maker 0 max))

(send acc-max 'update! 3)
(send acc-max 'update! 7)
(send acc-max 'update! 2)
(send acc-max 'update! 4)
(send acc-max 'update! 10)
(send acc-max 'update! 1)
(send acc-max 'update! 5)
(display (send acc-max 'show))
; 3, 7, 2, 4, 10, 1, 5
