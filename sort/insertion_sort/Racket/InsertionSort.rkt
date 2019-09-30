#lang racket
;;insertion sort implementation
(define (sort lon)
  (cond [(empty? lon) lon]
        [else (insert (first lon) (sort (rest lon)))]))

(define (insert n lon)
  (cond [(empty? lon) (cons n lon)]
        [else
         (if (> n (first lon))
             (cons (first lon) (insert n (rest lon)))
             (cons n lon))]))
