## Counting the number of all natural numbers less than N with equal sum and XOR with N ##

Given a natural number N, output the count of all natural numbers X less N such that X+N=X^N. (^ denotes XOR)

Example 1:

>Input: 2

>Output: 2

Example 2:

>Input: 5

>Output: 2

Follow up:

A naive solution (taking the XOR and sum of all numbers from 1 to N-1 with N and checking using a for loop) would result in a time complexity of O(N). 
But can we do better?

Hint: Are you reminded of any identity when you see sum and XOR together (of two numbers)?