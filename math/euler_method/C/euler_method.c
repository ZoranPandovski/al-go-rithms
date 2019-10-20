/*
*  Euler Method for resolving differential equtions
*/
#include <stdio.h>

float function(float xi, float yi){

  /* Given function is x+2y*/
  return (xi+(2*yi));
}
float euler_method(float xi, float yi, float h, int n){

  for (int i = 0; i < n; i++){
    yi = yi + h*function(xi,yi);
    xi = xi +h;
  }

  return yi;

}

int main() {

  float xi = 0; /* Start x value*/
  float yi = 0; /* Start y value*/
  float h = 0.25; /* Step size */
  int n = 5; /* Iterations */
  float res = 0; /* Algoritmn Result */

  res = euler_method(xi, yi, h, n);

  printf ("Result: %5f\n", res);

  return 0;
}
