#include<stdio.h>

int multiplywith2(int n){
	return n << 1;
}

int main(){
	printf("%i\n",multiplywith2(8));
	printf("%i\n",multiplywith2(15));

	return 0;
}
