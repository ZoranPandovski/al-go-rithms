(defpackage :linear_search
  (:use :cl))
(in-package :linear_search)

(defun lsearch (seq obj)
  (dotimes (i (length seq))
    (if (equalp obj (elt seq i))
	(return i))))

(defparameter testvec #(1 3 5 7 11 13 17 19 23 29 31 37 41))

(unless (progn
	  (assert (= 0 (lsearch testvec 1)))
	  (assert (= 12 (lsearch testvec 41)))
	  (assert (= 4 (lsearch testvec 11)))
	  (assert (= 5 (lsearch testvec 13)))))
