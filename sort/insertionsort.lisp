(defun insertionsort (lst)
	(cond ((null lst) ())
				(t (insert-in-place (car lst) (insertionsort (cdr lst))))))

(defun insert-in-place (ele lst)
	(cond ((null lst) (list ele))
	      (t (if (< (car lst) ele) (cons (car lst) (insert-in-place ele (cdr lst)))
					(cons ele lst)))))
