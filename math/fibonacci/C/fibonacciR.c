#include<stdio.h>

int fib(int num){
	
	if(num==0)
		return 0;
	else if(num==1)
		return 1;

	return fib(num - 1) + fib(num -2);
}

int main(){
	
	int num;

	printf("Number: ");
	scanf("%d",&num);

	printf("Fibonacci is: %d\n", fib(num));
}
