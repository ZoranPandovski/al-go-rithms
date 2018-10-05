read n (leave some free space to stop the final loop)
>>,>++++++++[-<------>]
generate all integers from n to 0 separated by 0
<[[->+>+<<]>[-<+>]>-]
set result to 1 and move to integer '1'
<+<
While current integer is not null
[
  multiply result by current integer
  [->[->+>+<<]>[-<+>]<<]
  store result at its new location (and reset temporary cells)
  >>>[-<<<<+>>>>]<<[-]<
  go to previous integer in the stack
<<]
