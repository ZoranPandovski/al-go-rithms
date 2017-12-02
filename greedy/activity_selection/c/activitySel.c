#include<stdio.h>
 

 
 
 
void activities(int s[], int f[], int n)
 
{
 
	int i, j;
 
	printf ("Selected Activities are:\n");
 
	i = 1;
 
	printf("A%d ", i);
 
	for (j = 1; j < n; j++)
 
	{
 
		if (s[j] >= f[i])
 
		{
 
			printf ("A%d ", j+1);
 
			i = j;
 
		}
 
	}
 
}
 
 
 
void main()
 
{
 
	int s[] =  {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
 
	int f[] =  {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
 
	int n = sizeof(s)/sizeof(s[0]);
 
	
 
	activities(s, f, n);
 
	getchar();
 
	
 
}
 