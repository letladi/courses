(load "newton.scm")

(define num-prompt
    (lambda ()
        (display "Enter any number: ")
        (let ((n (read)))
            (cond
                ((eq? n 'stop)
                    (display "Dueces.")
                    (newline)
                )
                (else
                    (display "You entered ")
                    (display n)
                    (display " (whose square root is ")
                    (display (round-n-places 3 (square-root n)))
                    (display ", and square is ")
                    (display (expt n 2))
                    (display ")")
                    (newline)
                    (num-prompt)
                )
            )
        )
    )
)

(define change
    (lambda ()
        (letrec*
            (
                (display-change (lambda (count msg)
                    (display (round count))
                    (display " ")
                    (display msg)
                    (if (> count 1) (display "s"))
                    (newline)
                ))
                (compute-small-change (lambda (amt)
                    (cond
                        ((>= amt 25)
                            (display-change (quotient amt 25) "quarter")
                            (compute-small-change (remainder amt 25))
                        )
                        ((>= amt 10)
                            (display-change (quotient amt 10) "dime")
                            (compute-small-change (remainder amt 10))
                        )
                        ((>= amt 5)
                            (display-change (quotient amt 5) "nickel")
                            (compute-small-change (remainder amt 5))
                        )
                        ((>= amt 1)
                            (display-change amt (if (> amt 1) "pennie" "penny"))
                            (newline)
                        )
                        (else
                            (newline)
                        )
                    )
                ))
                (compute-change (lambda (amt small-change)
                    (cond
                        ((>= amt 100)
                            (display-change (quotient amt 100) "100-dollar bill")
                            (compute-change (remainder amt 100) small-change)
                        )
                        ((>= amt 20)
                            (display-change (quotient amt 20) "20-dollar bill")
                            (compute-change (remainder amt 20) small-change)
                        )
                        ((>= amt 10)
                            (display-change (quotient amt 10) "10-dollar bill")
                            (compute-change (remainder amt 10) small-change)
                        )
                        ((>= amt 5)
                            (display-change (quotient amt 5) "5-dollar bill")
                            (compute-change (remainder amt 5) small-change)
                        )
                        ((>= amt 1)
                            (display-change amt "1-dollar bill")
                            (compute-small-change small-change)
                        )
                        (else
                            (compute-small-change small-change)
                        )
                    )
                ))
                (make-change (lambda (inv-count)
                    (display (if (zero? inv-count)
                        "For what amount of money do you want change? $"
                        "Do you want to enter another amount? (enter 'no' to exit) $"
                    ))
                    (let
                        ((amount (read)))

                        (cond
                            ((eq? amount 'no) (newline))
                            (else
                                (letrec*
                                    (
                                        (rounded-amt (exact (floor amount)))
                                        (small-change (exact (round (* 100 (- amount rounded-amt)))))
                                    )

                                    (compute-change rounded-amt small-change)
                                    (make-change (1+ inv-count))
                                )
                            )
                        )
                    )
                ))
            )
            (make-change 0)
        )
    )
)



(define day-of-week-program (lambda ()
    (letrec*
        (
            (days-of-the-week '(Sunday Monday Tuesday Wednesday Thursday Friday Saturday))
            (month-to-month-table '(11 12 1 2 3 4 5 6 7 8 9 10))
            (get-input (lambda (msg)
                (newline)
                (display msg)
                (let
                    ((input (read)))
                    input
                )
            ))
            (get-c (lambda (year)
                (floor (/ year 100))
            ))
            (get-y (lambda (year)
                (remainder year 100)
            ))
            (get-m (lambda (month)
                (list-ref month-to-month-table (1- month))
            ))
            (format-date (lambda (month day year)
                (let
                    (
                        (yr (number->string year))
                        (m (number->string month))
                        (d (number->string day))
                    )
                    (string-append m "/" d "/" yr)
                )
            ))
            (show (lambda (num msg)
                (display msg)
                (display ": ")
                (display num)
                (newline)
            ))
            (compute-day (lambda (month day year)
                (let*
                    (
                        (m (get-m month))
                        (y (get-y year))
                        (c (get-c year))
                        (d day)
                        (a (floor (/ (- (* 13 m) 1) 5)))
                        (b (floor (/ y 4)))
                        (e (floor (/ c 4)))
                        (f (- (+ a b e d y) (* 2 c)))
                        (r (remainder f 7))
                    )
                    (show m "m")
                    (show d "d")
                    (show y "y")
                    (show c "c")
                    (show f "f")
                    (show r "r")
                    (list-ref days-of-the-week r)
                )
            ))
            (prompt-user (lambda (inv-count)
                (display (if (zero? inv-count)
                    "Welcome: "
                    "Enter another date? (Enter 'no' to exit, 'yes' key to continue): "
                ))
                (let
                    (
                        (response (if (zero? inv-count)
                            "yes"
                            (read)
                        ))
                    )

                    (cond
                        ((eq? response 'no)
                            (display "Goodbye.")
                            (newline)
                        )
                        (else
                            (let
                                (
                                    (month (get-input "Please enter the month: "))
                                    (day (get-input "Please enter the day: "))
                                    (year (get-input "Please enter the year: "))
                                )
                                (newline)
                                (display (format-date month day year))
                                (display " is a ")
                                (display (compute-day month day year))
                                (display ".")
                                (newline)
                                (prompt-user (1+ inv-count))
                            )
                        )
                    )
                )
            ))
        )

        (prompt-user 0)

    )
))
