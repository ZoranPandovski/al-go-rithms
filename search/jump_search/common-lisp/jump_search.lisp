(defpackage :jump_search
  (:use :cl))
(in-package :jump_search)

(defun jump-search (seq key)
  (let* ((n (length seq)) (step (floor (sqrt n))))
    (labels ((inch (b)
	       (dotimes (i step)
		 (when (= key (elt seq (+ b i))) (return (+ b i)))))
	     (jump (prev &aux (curr (+ step prev)))
	       (let ((val (when (< curr (1- n)) (elt seq curr))))
		 (cond ((null val) (inch prev))
		       ((= key val) curr)
		       ((< key val) (inch prev))
		       ((> key val) (jump curr))))))
      (jump 0))))

(defparameter testvec #(1 1 2 3 5 8 13 21 34 55 89 144))
;;note that the second 1 is never found

(unless (progn
	  (assert (= 0 (jump-search testvec 1)))
	  (assert (= 11 (jump-search testvec 144)))
	  (assert (= 5 (jump-search testvec 8)))
	  (assert (= 6 (jump-search testvec 13))))
  T)
