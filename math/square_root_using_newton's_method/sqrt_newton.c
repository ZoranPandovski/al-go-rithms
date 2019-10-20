#include <stdio.h>
void main()
{
	float num,g;
	scanf("%f",&num);
	g=num/2;
	while(g*g!=num)
	{
		g=(g+(num/g))/2;
	}
	printf("Square Root:%f",g);
}
