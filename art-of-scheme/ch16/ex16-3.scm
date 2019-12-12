(let
    ([x (call/cc (lambda (k1)
        (call/cc (lambda (k2)
            (lambda (n)
                (display n)
                (k1 k2)
            )
        ))
    ))])

    (x 0)
)
