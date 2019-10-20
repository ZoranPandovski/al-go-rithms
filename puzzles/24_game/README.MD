# 24® Game

The 24 Game is an arithmetical card game in which the objective is to find a way to manipulate four integers so that the end result is 24. [Wikipedia](https://www.google.com)

## Task 

Write a program that randomly chooses and displays four digits, each from 1 ──► 9 (inclusive) with repetitions allowed.

The program should prompt for the player to enter an arithmetic expression using just those, and all of those four digits, used exactly once each. 
The program should check then evaluate the expression.

The goal is for the player to enter an expression that (numerically) evaluates to 24.

* Only the following operators/functions are allowed: multiplication, division, addition, subtraction
* Division should use floating point or rational arithmetic, etc, to preserve remainders.
* Brackets are allowed, if using an infix expression evaluator.
* Forming multiple digit numbers from the supplied digits is disallowed. (So an answer of 12+12 when given 1, 2, 2, and 1 is wrong).
* The order of the digits when given does not have to be preserved.


Source: [http://rosettacode.org/wiki/24_game](http://rosettacode.org/wiki/24_game)

### Example
For the card with the numbers 4, 7, 8, 8, a possible solution is **( 7 − ( 8 ÷ 8 ) ) × 4 = 24**

### Contributing
Before making a PR follow guidelines [here](/CONTRIBUTING)

