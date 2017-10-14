# Perfect Numbers
Taken from Wikipedia:
>In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself (also known as its aliquot sum).

It is fairly trivial to implement an algorithm that will check whether any given number is perfect. Simply find all its divisors, store them in a list, add them up, and check if they're equal to the original number.
To make this more interesting, the Euclid–Euler theorem states that every even perfect number can be formed using *q(q+1)/2* where *q* is a prime number formed from *2^(p-1)*, for all prime *p*. Using this theorem can allow us to generate perfect numbers faster. 

