/*
*  RK4 Method for resolving differential equtions
*/
#include <stdio.h>
#include <math.h>

float function (float xi, float yi){
  /* Given function is x^2+y^2 */
  return (pow(xi,2)+pow(yi,2));
}

float runge_kutta(float xi, float yi, float h, int n){
  float k1, k2, k3, k4; /* Incremental values */

  for (int i = 0; i < n; i++){
    k1 = function(xi,yi);
    k2 = function(xi+(h/2),yi+(h*k1/2));
    k3 = function(xi+(h/2),yi+(h*k2/2));
    k4 = function(xi+h,yi+(h*k3));
    yi = yi + h*((k1 + 2*k2 + 2*k3 +k4)/6);
    xi = xi + h;
  }

  return yi;
}

int main(void) {
  float xi = 0; /* Start x value */
  float yi = 0; /* Start y value */
  float h = 0.2; /* Step size */
  int n = 10; /* Iterations */
  float res = 0;

  res = runge_kutta(xi,yi,h,n);
  printf ("\nResult: %5f\n", res);

  return 0;
}
