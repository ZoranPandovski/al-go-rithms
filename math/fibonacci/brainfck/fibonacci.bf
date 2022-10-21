[
  Fibonacci Program in Brainfuck
  Written by Sam Coppini
  Outputs arbitrarily many Fibonacci numbers. Never terminates.
  The program stores the result of the last two calculated Fibonacci numbers,
  always outputting the smaller one before it moves the larger fib number over
  it and replaces the larger number with the sum of the two numbers.
  The digits for the last two Fibonacci numbers are represented like so:
  b  a  1  b  a  1  b  a  1  0  0  0
  ^  ^  ^
  |  |  |
  |  |  +--- A boolean flag indicating whether the current Fibonacci numbers
  |  |       extend this far into the tape
  |  |
  |  +--- Digits for the second to last Fibonacci number
  |
  +--- Digits for the latest Fibonacci number
]
Sets up the tape and enters the main loop
++++++++++>>+>>+[
Goes through the tape and outputs each digit of the second to last calculated
Fibonacci number
[+++++[<++++++++>-]<.>++++++[<-------->-]+<<<]
Outputs a newline and moves to the last digits of the numbers and enters the
loop to add our current Fibonacci numbers
<.>>>>[
Moves the value of the smaller fib number to the flag cell
-<[>+<-]
Copies the larger fib number to the newly emptied cell while adding it to the
value stored in the flag cell
<[>+>+<<-]>>
Moves the value in the flag cell to where the larger fib number and while it's
moving the value it also checks to see if it's greater than nine
[<<+>>-[<<+>>-[<<+>>-[<<+>>-[<<+>>-[<<+>>-[<<+>>-[<<+>>-[<<+>>-[
If the value is greater than nine we move the remainder of the value in the flag
cell to the larger fib cell and carry the one and also make sure that the flag
bit of the next digit is set and then move back to where we were
-<<[-]>>[<<+>>-]>>>[-]+<+<<
Set the flag bit back to one and move to the next digit over
]]]]]]]]]]+>>>]
Move to the first digit in preparation of printing the number but also make sure
to move over a digit if the first digit would be a zero
<<<<[>>>]<<]