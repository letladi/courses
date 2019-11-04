(define prompt-read
    (lambda (prompt)
        (display prompt)
        (display " ")
        (read)
    )
)

(define station-prompts
    '("Enterh")
)


(define station-prompts
'(
    "Enter the number of hours the station is open:"
    "Enter the percentage of self-service customers:"
    "Enter the average time in minutes between arrivals:"
    "Enter the profit per gallon from self-service customers:"
    "Enter the profit per gallon from full-service ciistomers:"
    "Enter the extra time at the pump for self-service customers:"
    "Enter the extra time at the pump for full-service customers:"
    "Enter the delivery rate of the pumps in gallons per minute:"
))
