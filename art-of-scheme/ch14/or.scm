(define or-proc
    (lambda (th-list)
        (cond
            ((null? th-list) #f)
            (else
                (let ((v (thaw (car th-list))))
                    (if v v (or proc (cdr th-list)))
                )
            )
        )
    )
)
