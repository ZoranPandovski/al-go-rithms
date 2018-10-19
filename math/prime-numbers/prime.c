#include<stdio.h>
int main()
{
	int i, j, value, count = 0;
	printf("Enter the value...");
	scanf("%d",&value);
	printf("The prime numbers till %d are\n",value );
	for(i = 2 ; i < value ; i++)
	{
		for (j = 2; j < value; j++)
		{
			if(i % j == 0 && i != j)
				count++;
		}
		if(count<1)
			printf("%d\n",i );;
		count = 0;
	}
}