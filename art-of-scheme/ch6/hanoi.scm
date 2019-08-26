(define tower-of-hanoi
    (lambda (n)
        (letrec
            (
                (move (lambda (n source destination helper)
                    (if (= n 1)
                        (list (list source destination))
                        (append
                            (move (1- n) source helper destination)
                            (cons
                                (list source destination)
                                (move (1- n) helper destination source)
                            )
                        )
                    )
                ))
            )

            (move n 'L 'R 'C)
        )
    )
)

(define display-tower-of-hanoi
    (let
        (
            (show-move (lambda (s d)
                (display s)
                (display " --> ")
                (display d)
            ))
        )

        (lambda (n)
            (letrec
                (
                    (move (lambda (n source destination helper)
                        (if (= n 1)
                            (begin
                                (show-move source destination)
                                (newline)
                            )
                            (begin
                                (move (1- n) source helper destination)
                                (show-move source destination)
                                (display ", ")
                                (move (1- n) helper destination source)
                            )
                        )
                    ))
                )

                (move n 'L 'R 'C)
            )
        )
    )
)
