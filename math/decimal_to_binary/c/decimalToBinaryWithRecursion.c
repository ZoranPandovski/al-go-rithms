#include <stdio.h>

void DecBin(int n) {
	if(n > 0) {
		DecBin(n / 2);
		printf("%d", n % 2);
	}
	else if(n != 0)
		printf("%d", n);
}

int main() {
	int n;
	
	while(1) {
		scanf("%d", &n);
		if(n == -1)
			break;
		else 
			DecBin(n);
	}
	
	return 0;
}
