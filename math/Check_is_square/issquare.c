#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
bool isPerfectSquare(long double x) 
{   
   
  long double sqr = sqrt(x); 
  return ((sqr - floor(sqr)) == 0); 
} 
  
int main() {
  int sq;
  printf("Enter number: ");
  scanf("%d",&sq);
  if (isPerfectSquare(sq)) 
    printf("Yes\n"); 
  else
    printf("No\n"); 
  return 0; 
} 
