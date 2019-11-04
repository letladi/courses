; ex3.1.1
; This becomes
; ((lambda (x)
;   (and
;     x
;     (memv 'b x)
;   )
; ) (memv 'a ls))

; ex3.1.2
; This becomes
; (let ([temp (memv x '(a b c))])
;     (if temp
;         temp
;         (list x)
;     )
; )

; ((lambda (temp)
;     (if temp
;         temp
;         (list x)
;     )
; ) (memv x '(a b c)))

; ex3.1.3
(define-syntax let*2
    (syntax-rules ()
        [(_ ([e expr]))  b1 b2 ...]
        [(_ ([e1 expr1] [e2 expr2] [e3 expr3] ...))
            (let*2
                (let ([e1 expr1])
                    (let*2
                        ([e2 expr2] [e3 expr3] ...)
                    )
                )
            )
        ]
    )
)
