#include<stdio.h>

int fib(int num){
	
	if(num < 2)
		return 1;

	return fib(num - 1) + fib(num -2);
}

int main(){
	
	int num;

	printf("Number: ");
	scanf("%d",&num);

	printf("Fibonacci is: %d\n", fib(num));
}
