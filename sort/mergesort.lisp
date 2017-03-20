(defun mergesort (lst)
	(cond ((null lst) nil)
	      ((= (length lst) 1) lst)
	      (t (let* ((len1 (/ (length lst) 2))
				          (len2 (- (length lst) len1))
									(list1 (subseq lst 0 len1))
									(list2 (subseq lst len1 (+ len1 len2))))
				     (mergelist (mergesort list1) (mergesort list2))))))

(defun mergelist (l1 l2)
	(cond ((null l1) l2)
	      ((null l2) l1)
				((< (car l1) (car l2)) (cons (car l1) (mergelist (cdr l1) l2)))
				(t (cons (car l2) (mergelist l1 (cdr l2))))))


