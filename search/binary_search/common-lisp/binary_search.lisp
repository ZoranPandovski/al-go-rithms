(defpackage :binary_search
  (:use :cl))

(defun bsearch (vec n)
  (labels ((rec (low high mid) 
	     (cond ((= (elt vec mid) n)
		    mid)
		   ((>= low high)
		    nil)
		   ((< n (elt vec mid))
		    (rec low (1- mid) (floor (+ low mid) 2)))
		   ((> n (elt vec mid))
		    (rec (1+ mid) high (ceiling (+ mid high) 2))))))
    (rec 0 (1- (length vec)) (floor (length vec) 2))))

(defparameter testvec #(1 3 5 7 11 13 17 19 23 29 31 37 41 43))

(unless (progn
	  (assert (= 0 (bsearch testvec 1)))
	  (assert (= 13 (bsearch testvec 43)))
	  (assert (= 6 (bsearch testvec 17)))
	  (assert (= 7 (bsearch testvec 19))))
  T)
