### Ternary Search
A ternary search algorithm is a technique in computer science for finding the minimum or maximum of a unimodal function. A ternary search determines either that the minimum or maximum cannot be in the first third of the domain or that it cannot be in the last third of the domain, then repeats on the remaining third. A ternary search is an example of a divide and conquer algorithm.
#### Run time analysis
T(n) = T(2n/3) + Θ(1) = Θ(log<sub>3</sub>n)
#### Formulation of the problem

Let an unimodal function *f(x)* is given on interval *[l:r]*. Unimodality means one of two options:
- *f(x)* is a strictly increasing function firstly, then reaches a maximum (at one point or a whole segment), then strictly decreases.
- *f(x)* decreases firstly, reaches a minimum and than increases.

Required to ***find the maximum/minimum*** of the function *f(x)* on the interval *[l:r]*

