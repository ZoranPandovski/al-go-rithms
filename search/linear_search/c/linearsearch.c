#include<stdio.h>
int main()
{
    int n,i,x,flag=0;                       
    int a[100100]; 
    scanf("%d",&n);            //how many numbers in which you want to search
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);     //Taking input from user 
    } 
    scanf("%d",&x);            // Number which we want to search
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            {
                flag=1;        //If number is found then set the flag
            }
    }    
    if(flag==1)
        printf("Yes\n");      //If number is found then print yes.
    else
        printf("No\n");       // If number is not there then print no.
return 0;
}
