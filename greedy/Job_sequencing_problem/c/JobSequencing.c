#include<stdio.h>

finalResult(int j[],int d[],int n,int store[],int max)
{
    for(int i=0;i<max;i++)
    {
        int min;
        if(n<d[i])
            min=n;
        else
            min=d[i];
        for(int k=min-1;k>=0;k--)
        {
            if(store[k]==0)
            {
                store[k]=j[i];
                break;
            }
        }
    }
        printf("The job sequence for maximum profit is :");
       for(int i=0;i<max;i++)
        printf("%d ",store[i]);
}

int max_deadline(int d[],int n)
{
    int max;
    int g=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]>g)
            g=d[i];
    }
    if(n>g)
        max=g;
    else
        max=n;
    printf("The maximum number of jobs that can be completed is %d\n",max);
    return max;
}
sort(int p[],int j[],int d[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int k=0;k<n-i-1;k++)
        {
            if(p[k]<p[k+1])
            {
                int temp1=p[k];
                p[k]=p[k+1];
                p[k+1]=temp1;
                int temp2=j[k];
                j[k]=j[k+1];
                j[k+1]=temp2;
                int temp3=d[k];
                d[k]=d[k+1];
                d[k+1]=temp3;
            }
        }
}
}

int main()
{
    int n,i;
    printf("Enter number of jobs ");
    scanf("%d",&n);
    int j[n],p[n],d[n];
    for(int i=0;i<n;i++)
    {
        printf("enter deadline and profit of job %d ",i+1);
            j[i]=i+1;
            scanf("%d",&d[i]);
            scanf("%d",&p[i]);
    }
    sort(p,j,d,n);
    int store[n];
    for(i=0;i<n;i++)
        store[i]=0;
    int max=max_deadline(d,n);
    finalResult(j,d,n,store,max);
 return 0;
}
