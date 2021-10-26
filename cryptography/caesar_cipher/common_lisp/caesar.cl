; replace the '13' to change the key
(defvar key (mod 13 26) )

; main function
(defun caesar (n)
  (loop for c across n do
    (setq caes
    (if(is-lower-case c)
      (cipher-lower-case c)
      (if(is-upper-case c)
        (cipher-upper-case c)
        (code-char (char-code c)))))
  collect caes))

; tests if 'c' is lower case letter
(defun is-lower-case (c)
  (and (>= (char-code c) (char-code #\a)) (<= (char-code c) (char-code #\z))))

; tests if 'c' is upper case letter
(defun is-upper-case (c)
  (and (>= (char-code c) (char-code #\A)) (<= (char-code c) (char-code #\Z))))

; applies the caesar cipher to a lower case letter
(defun cipher-lower-case (c)
  (if(> (+ (char-code c) key) (char-code #\z))
    (code-char (- (+ (char-code c) key) 26))
    (code-char (+ (char-code c) key))))

; applies the caesar cipher to an upper case letter
(defun cipher-upper-case (c)
  (if(> (+ (char-code c) key) (char-code #\Z))
    (code-char (- (+ (char-code c) key) 26))
    (code-char (+ (char-code c) key))))

; input line to cipher
(setq line (read-line *query-io*))

; applies cipher to the given line
(pprint (coerce (caesar line) 'string))
