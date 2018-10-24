#include <stdio.h>
#include <math.h>

float function (float xi){
  /* Given function is x^2*sin(x) */
  return (pow(xi,2)*sin(xi));
}

float trapezoidal_rule(float a, float b, int n){
  float fa, fx, fb;
  float dx = (b-a)/n;

  fa = function(a);
  fb = function(b);

  for(int i = a; i < n; i++){
    fx = fx + (function((a+i*dx)));
  }

  return  ((dx/2) * (fa + (2*fx) + fb));
}

int main(void) {
  float a = 0; /* Low Border */
  float b = 2; /* Top Border */
  int n = 500; /* Iterations */
  float res = 0;

  res = trapezoidal_rule(a,b,n);

  printf ("\nResult: %5f\n", res);

  return 0;
}
