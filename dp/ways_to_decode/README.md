Problem Statement :
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
 ...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

Example :
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.



Solution Approach : 
Used a DP approach to solve the problem. Calculated the number of ways to decode string of length 1 to n. 
Derived the solution for string length n from the subproblems i.e. number of ways to decode string length n-1 and number of ways to decode string length n-2
