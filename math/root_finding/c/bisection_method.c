#include <stdio.h>
#include <math.h>

float function(float xi){
  return pow (xi,2) + 2*xi - 4;
}

float bisection (float a, float b, int i){
  static float x;
  float f;
  float f_a;

  while (i != 0){
    x = (a+b)/2;
    i--;
    f = function(x);
    f_a = function(a);
    if (f*f_a < 0){
      b = x;
      a = a;
    }else if (f*f_a > 0){
      a = x;
      b = b;
    }
    else
      return x;
  }
  return x;
}

int main() {
  float a = 0; /* Low Interval */
  float b = 5; /* High Interval */
  int i = 50; /* Iterations */
  float res;

  res = bisection(a, b, i);
  printf ("\nRoot of x^2+2*x-4: %5f\n", res);

  return 0;
}
