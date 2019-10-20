
#include <stdio.h>

/** Memoized Fibonacci algorithm in o(n) time efficiency **/
int Fibo(int n) {
  int memo[n];
  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 1;
  if(n==0) {
    return memo[0];
  }
  if(memo[n] != 0) {
    return memo[n];
  }
  else {
    int f = Fibo(n-1) + Fibo(n-2);
    memo[n] = f;
    return f;
  }
}
 

int main() {
  
  int n; 

  printf("How many Fibonacci numbers do you want?\n");
  scanf("%d", &n);
  
  printf("%d\n",Fibo(n));

  /** Iterative Fibonacci version **
  
  int num1 = 0, num2 = 1, temp;
  for (int i = 0; i <= n; i++) {
    printf("%d\n", num1);

    temp = num1 + num2;
    num1 = num2;
    num2 = temp;
  }
  */
  return 0;
}
