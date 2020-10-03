# Quicksort implementation in Common Lisp
I recommend to use Emacs with Slime installed on it (google it if you wonder how to install and setup it)
## How to use
- Compile `quicksort.lisp` file in your slime repl
- Call `quicksort` function on list of any numbers
## Examples
```
CL-USER> (quicksort '(2 3 1))
(1 2 3)
CL-USER> (quicksort '(2 3 1 9 123 2.3 88))
(1 2 2.3 3 9 88 123)
CL-USER> (quicksort '(2 3 1 9 123 2.3 88) #'<)
(123 88 9 3 2.3 2 1)
```
