const collatzConjecture = (n, count = 0) =>  {
  n = n%2 == 0 ? n/2 : 3*n+1;
  count++;
  return n == 1 ? count : collatz(n, count);
}
