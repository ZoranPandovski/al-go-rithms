#include<stdio.h>
void main()
{
	int i, n , x1 = -1, x2 = 1, x3 = 0;
	printf("Enter a valuee...\n");
	scanf("%d",&n);
	printf("The fibonacci series till %d are\n",n );
	for(i = 0; i < n ; i++)
	{
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
		printf("%d\n",x3);
	}

}