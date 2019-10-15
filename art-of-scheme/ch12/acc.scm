(load "ch12/box.scm")
(load "ch12/counter.scm")

(define accumulator-maker
    (lambda (init-value binary-proc)
        (let
            ((total (box-maker init-value)))
            (lambda msg
                (case (1st msg)
                    ((type) "accumulator")
                    ((update!) (send total 'update! (binary-proc (send total 'show) (2nd msg))))
                    ((swap!) (delegate base-object msg))
                    (else (delegate total msg))
                )
            )
        )
    )
)

; (define accumulator-maker
;     (lambda (init-value binary-proc)
;         (let*
;             (
;                 (total (counter-maker init-value (lambda (val)
;
;                 )))
;             )
;             (lambda msg
;                 (case (1st msg)
;                     ((type) "accumulator")
;                     ((update!)
;                         (let ((curr (send total 'show)))
;                         (display "binary proc application: ")
;                         (display (binary-proc curr (2nd msg)))
;                             (send total 'update! (binary-proc curr (2nd msg)))
;                         )
;                     )
;                     ((swap!) (delegate base-object msg))
;                     (else (delegate total msg))
;                 )
;             )
;         )
;     )
; )
; ex12.8. The accumulator cannot be implemented with a counter, this is because we don't have the
; that will later be passed in when we initialize the counter-maker.
