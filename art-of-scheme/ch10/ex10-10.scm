(load "relational-calculus.scm")

(define closest-common-supervisor
    (letrec
        ((find-ccs (lambda (path1 path2)
            (let
                (
                    (rest1 (cdr path1))
                    (rest2 (cdr path2))
                )
                (if (string=? (car rest1) (car rest2))
                    (find-ccs rest1 rest2)
                    (car path1)
                )
            )
        )))

        (lambda (test-procedure)
            (lambda (table)
                (letrec
                    ((build-path (lambda (tbl u acc)
                        (if (empty-set? tbl)
                            acc
                            (let
                                ((next (pick tbl)))
                                (let
                                    ((v ((test-procedure next) u)))
                                    (if (not v)
                                        (build-path ((residue next) tbl) u acc)
                                        (build-path table v (cons u acc))
                                    )
                                )
                            )
                        )
                    )))
                    (lambda (x y)
                        (find-ccs
                            (build-path table x '())
                            (build-path table y '())
                        )
                    )
                )
            )
        )
    )
)
