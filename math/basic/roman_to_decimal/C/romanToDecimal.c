#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 20

void calulaDec(int tam, char romano[MAX]) {
	int i, dec = 0;
	
	for(i = 0; i < tam; i++) {
		if(romano[i] == 'C' && romano[i + 1] == 'M') {
			dec += 900;
			i++;
		}
		else if(romano[i] == 'C' && romano[i + 1] == 'D') {
			dec += 400;
			i++;
		}
		else if(romano[i] == 'X' && romano[i + 1] == 'C') {
			dec += 90;
			i++;
		}
		else if(romano[i] == 'X' && romano[i + 1] == 'L') {
			dec += 40;
			i++;
		}
		else if(romano[i] == 'I' && romano[i + 1] == 'X') {
			dec += 9;
			i++;
		}
		else if(romano[i] == 'I' && romano[i + 1] == 'V') {
			dec += 4;
			i++;
		}
		else if(romano[i] == 'M')
			dec += 1000;
		else if(romano[i] == 'D')
			dec += 500;
		else if(romano[i] == 'C')
			dec += 100;
		else if(romano[i] == 'L')
			dec += 50;
		else if(romano[i] == 'X')
			dec += 10;
		else if(romano[i] == 'V')
			dec += 5;
		else if(romano[i] == 'I')
			dec += 1;
	}
	
	printf("%d\n", dec);
}

int main() {
	char romano[MAX];
	int tam;
	
	scanf("%s", romano);
	tam = strlen(romano);
	calulaDec(tam, romano);
	
	return 0;
}
