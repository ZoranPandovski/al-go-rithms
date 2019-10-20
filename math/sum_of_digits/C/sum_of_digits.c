#include <stdio.h>

int sum_of_digits(int x){
	int s = 0;
	while (x){
		s += (x % 10);
		x /= 10;
	}
	return s;
}

int main(){
	int x;
	scanf("%d", &x);
	printf("Sum of digits: %d\n", sum_of_digits(x));
	return 0;
}
