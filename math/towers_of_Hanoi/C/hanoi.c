#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	towers(n, 'A', 'B', 'C');
}

void towers(int n, char frompeg, char topeg, char auxpeg){
	if(n == 1){
		printf("\n%s%c%s%c", "move disc 1 from stake ",
		frompeg, " to stake ", topeg);
	return;
}
	towers(n-1, frompeg, auxpeg, topeg);
	printf("\n%s%d%s%c%s%c", "move disc ", n, " from stake ",
	frompeg, " to stake ", topeg);
	towers(n-1, auxpeg, topeg, frompeg);
}

