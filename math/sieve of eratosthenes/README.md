# Sieve of Erastothenes
An algorithm used for finding all prime integers less than some positive number n. First create a list of all positive integers from 2 to n. Then, letting p be the first number in the list, repeatedly count up in increments of p and mark each number on that index excluding p itself (2p, 3p, 4p, and so on). p will then take the value of the next unmarked number. After iterating through the whole list, all the numbers that are not marked at the end will be prime.  

Illustration: 
![Image not available.](https://en.wikipedia.org/wiki/File:Sieve_of_Eratosthenes_animation.gif)
