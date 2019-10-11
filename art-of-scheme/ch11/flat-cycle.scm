(define has-flat-cycle?
    (lambda (ls)
        (let
            (
                (cycle-found? #f)
                (max-call-count 1000000)
                (end-of-list-reached? #f)
            )

            (letrec
                (
                    (equals-ls? (lambda (el ls count)
                        (if (>= count max-call-count)
                            #f
                            (if cycle-found?
                                #t
                                (cond
                                    ((null? ls)
                                        (set! cycle-found? #f)
                                        (set! end-of-list-reached #t)
                                        #f
                                    )
                                    ((eq? el ls)
                                        (set! cycle-found? #t)
                                        #t
                                    )
                                    (else
                                        (equals-ls? el (cdr ls) (1+ count))
                                    )
                                )
                            )
                        )
                    ))
                    (loop (lambda (ls-search ls)
                        (cond
                            ((null? ls) #f)
                            
                        )
                    ))
                )

                (equals-ls? ls (cdr ls))
                (cond
                    ((end-of-list-reached?) #f)
                    ((cycle-found?) #t)
                    (else #f)
                )
            )
        )
    )
)
