The binomial coefficient is a function that allows you to solve basic problems
in combinatorics. The coefficient indicates in how many different ways you can
select `k` distinct elements from a set of `n` elements. 

The binomial coefficient is determined by the two different numbers `n` and `k`
and is usually given by 

    Binomial(n, k) = n! / (k! * (n-k)!),

where exclamation mark stands for the mathematical factorial.
Alternatively, the binomial coefficient can be calculated using Pascal's
triangle: By constructing a triangle of the form
       
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
       ...

where each number is given by the sum of the two numbers above it (the edges
are filled with 1's), the binomial coefficient of `n` over `k` is simply given
by the `k`'th entry of the `n`'th row.
