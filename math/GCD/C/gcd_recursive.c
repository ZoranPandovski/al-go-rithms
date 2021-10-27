#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1;
	int n2;
	int result;
	
	printf("Enter the first number: ");
	scanf("%d", &n1);
	printf("\nEnter the second number: ");
	scanf("%d", &n2);
	
	result = gcd(n1,n2);
	printf("\n");
	printf("The Great Commun Divider is: %d", result);
}

int gcd(int n1, int n2){
	if(n2 == 0){
		return n1;
	}
	else 
		return(gcd(n2,n2%n1));
}
