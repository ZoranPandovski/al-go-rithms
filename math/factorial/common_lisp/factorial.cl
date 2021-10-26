(defun factorial(n)
    "Returns n!"
    (if (equal n 0)
        1
        (* n (factorial (- n 1)))))

(format t "5! = ~d~&" (factorial 5))
(format t "10! = ~d~&" (factorial 10))
(format t "50! = ~d~&" (factorial 50))
