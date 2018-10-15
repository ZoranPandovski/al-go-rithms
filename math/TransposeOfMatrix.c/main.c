#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the matrix : ");
    scanf("%d",&n);
    int a[n][n],b[n][n],i,j,k,l;
    printf("Enter the element of the matrix : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    printf("The transpose of the matrix is : \n");
    for(k=0;k<n;k++)
    {
        for(l=0;l<n;l++)
        {
           b[k][l]=a[l][k];
           printf("%d ",b[k][l]);
        }
        printf("\n");
    }
    return 0;
}
/* testCase 1

Enter the size of the matrix : 4
Enter the element of the matrix :
4 5 6 8
2 3 4 6
7 5 8 9
2 4 8 6
The transpose of the matrix is :
4 2 7 2
5 3 5 4
6 4 8 8
8 6 9 6
*/
