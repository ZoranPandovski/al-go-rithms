#include <stdio.h>
int main()
{
int a[100], i, num, c = 0, n;
printf("Enter size of array\n");
scanf("%d", &n);
printf("Enter array elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
printf("Enter no you want to search\n");
scanf("%d", &num);
for (i = 0; i < n; i++)
{
if (num == a[i])
{
printf("%d is found at a[%d]\n", num, i);
c++;
}
}
if (c == 0)
printf("Number is not present in array");
printf("This is prepared by VIMARSH JAISWAL , Roll no 2100321530187");
return 0;
}

