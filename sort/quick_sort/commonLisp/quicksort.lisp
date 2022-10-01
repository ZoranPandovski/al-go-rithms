;; Simple yet effective quicksort implementation
(defun quicksort (lst &optional (pred #'>))
  (labels ((%helper (lst)
             (when lst
               (destructuring-bind (x . xs) lst
                 (nconc (%helper (remove-if (lambda (a) (funcall pred a x)) xs))
                        (list x)
                        (%helper (remove-if-not (lambda (a) (funcall pred a x)) xs)))))))
    (%helper lst)))
