(define random-list
    (lambda (n)
        (letrec
            ((build-list (lambda (k)
                (if (zero? k)
                    '()
                    (cons (random n) (build-list (1- k)))
                )
            )))
            (build-list n)
        )
    )
)

(define timer
    (lambda (proc arg)
        (let*
            (
                (start (time-of-day))
                (val (proc arg))
                (finish (time-of-day))
                (elapsed-time (/ (- finish start) 100))
            )
            (display "Time = ")
            (display elapsed-time)
            (display ", Answer = ")
            (display val)
        )
    )
)

(define rand100 (random-list 100))
(define rand200 (random-list 200))
(define rand400 (random-list 400))
(define v-rand100 (list->vector rand100))
(define v-rand200 (list->vector rand200))
(define v-rand400 (list->vector rand400))
