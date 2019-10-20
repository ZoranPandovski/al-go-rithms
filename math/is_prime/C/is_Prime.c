#include <stdio.h>


// Function that returns 1 if n is Prime or 0 is it is not prime
int isPrime(int n){
	int i = 2;
	while(i < n){
		if (n % i == 0) return 0;
		i++;
	}
	return 1;
}

int main()
{
	int i;
	for(i=1;i<30;i++){
		if(isPrime(i)) 
			printf("%d is Prime\n",i);
	}
	return 0;
}
