(defun sieve (max)
  "Prime numbers sieve for odd numbers. 
  Returns a list with all the primes that are less than or equal to maximum."
  (let ((bit-vector (make-array max :initial-element 1 :element-type 'bit)))
  (loop for i from 2 upto (isqrt max) do
    (loop for j from i
      for index = (* i j)
      until (>= index max) do
      (setf (sbit bit-vector index) 0)))
  (loop for i from 2 below (length bit-vector)
    unless (zerop (sbit bit-vector i)) collect i)))
