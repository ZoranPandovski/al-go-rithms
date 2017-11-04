(defpackage :toh
  (:use :cl))
(in-package :toh)

(defun solve (n from to aux)
  (when (>= n 1)
    (solve (1- n) from aux to)
    (format t "~&Move: ~d :: ~a => ~a" n from to)
    (solve (1- n) aux to from)))

(solve 5 'a 'c 'b)
