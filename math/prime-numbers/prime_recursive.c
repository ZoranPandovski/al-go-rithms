#include <stdio.h>
#include <stdlib.h>

void main(){
	
	int a, b;
	int cont;
	
	printf("Enter a: ");
	scanf("%d", &a);
	printf("\nEnter b:");
	scanf("%d", &b);

	cont = cont_primo(a, b);
	
	printf("%d", cont);
	
}

int cont_primo(int a, int b)
{
	if(a>b)
		return 0;
		
	else
	{	
	if(primo(b))
		return (cont_primo(a, b-1)+1);
	else
		return (cont_primo(a, b-1));
	}
}

int primo(int x)
{
	int i;
	
	for(i = 2; i <= x/2; i++)
		if(x%i == 0)
			return 0;
			
	return 1;
}
