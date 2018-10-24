/*
*  Simpson 3/8 Rule Method for performing numerical integration
*/
#include <stdio.h>
#include <math.h>

float function (float xi){
  /* Given function is x^2*sin(x) */
  return (pow(xi,2)*sin(xi));
}

float simpson_3_8(float a, float b, float n){
  float fx, f_a, f_b, xi, res;
  float h = 0; /* Step size */

  f_a = function(a);
  f_b = function(b);

  h = (b-a)/n;
  for (int i = 1; i < n; i++){
    xi = (a + (i*h));

    if (i % 2 == 0)
      fx = fx + 3 * function(xi);
    else
      fx = fx + 2 * function(xi);

  }

  res = ((3*h)/8) * (f_a + fx + f_b);

  return res;

}

int main(void) {
  float a = 0; /* Low border */
  float b = 2; /* High border */
  float n = 500; /* Iterations */
  int i = 0;
  float res = 0;

  res = simpson_3_8(a, b, n);

  printf ("\nResult: %5f\n", res);

  return 0;
}
