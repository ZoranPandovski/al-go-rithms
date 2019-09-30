(defpackage :ternary_search
  (:use :cl))
(in-package :ternary_search)

(defun ternary-search (vec key)
  (labels ((recur (lower upper)
	     (let ((left (ceiling (+ lower (/ (- upper lower) 3))))
		   (right (floor (- upper (/ (- upper lower) 3)))))
	       (cond ((= key (elt vec left))
		      left)
		     ((= key (elt vec right))
		      right)
		     ((>= lower upper)
		      nil)
		     ((< key (elt vec left))
		      (recur lower (1- left)))
		     ((> key (elt vec right))
		      (recur (1+ right) upper))
		     (T
		      (recur (1+ left) (1- right)))))))
    (recur 0 (1- (length vec)))))


(defparameter testvec #(2 4 8 16 32 64 128 256 512 1024 2048))
