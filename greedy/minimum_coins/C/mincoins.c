#include<stdio.h>
#define len(x) sizeof(x)/sizeof(x[0])

//array of available denominations in decreasing order
int notes[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
	int amount, count = 0;
	scanf("%i", &amount);

 	for(int i=0; i<len(notes) && amount>0; i++){
			if(notes[i] > amount) continue;
			count += amount/notes[i];//floor divsion
			amount = amount%notes[i];
	}
	printf("%i\n", amount == 0 ? count: -1);
}

//problem description
//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
//https://www.tutorialspoint.com/find-out-the-minimum-number-of-coins-required-to-pay-total-amount-in-cplusplus
