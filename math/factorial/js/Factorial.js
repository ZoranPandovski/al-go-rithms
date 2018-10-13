function factorial (n) {
  if (n == 0 || n == 1)
    return 1;
  if (f[n] > 0)
    return f[n];
  return f[n] = factorial(n-1) * n;
} 

//tests
factorial(5)
factorial(3)
factorial(5)
factorial(8)
factorial(10)