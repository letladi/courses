(load "quant.scm")

(define neither
    (lambda (pred)
        (both (compose not pred))
    )
)

(define at-least-one
    (lambda (pred)
        (lambda (arg1 arg2)
            (not
                ((both (compose not pred)) arg1 arg2)    
            )
        )
    )
)
