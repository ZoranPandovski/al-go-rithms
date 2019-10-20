#include <stdio.h>
#include <stdlib.h>
int sort(int a[],int n)
{
    int i,j,temp,min,minindex;
    min = a[0];
    for(i=0;i<n;i++)
    {
      min = a[i];
      minindex = i;
        for(j=i;j<n;j++){
            if(a[j]<min)
            {
               min=a[j];
               minindex = j;

            }
        }
       temp = a[i];
       a[i] = a[minindex];
       a[minindex] = temp;
    }
}

void fcfs(int hp,int upper,int lower,int req[],int n)
{
    int res = abs(req[0]-hp);
    int i;
    for(i=1;i<n;i++)
    {
        res+=abs(req[i]-req[i-1]);
    }
    printf("\nFCFS \n ******* \n Total head movement: %d\n",res);
    
}
void scan(int hp,int upper,int lower,int req[],int n)
{
    int req_copy[20],i,j,res,k;
    for(i=0;i<n;i++)
        req_copy[i] = req[i];
    sort(req_copy,n);
    for(i=0;i<n;i++)
    {
        if(req_copy[i]>hp)
        {
            res=abs(upper-hp);
            if(i!=0)
            {
                res+=abs(upper-req_copy[0]);
            }
            break;
        }
    }
    printf("\nSCAN \n ******* \n Total head movement: %d",res);
    
}
void cscan(int hp,int upper,int lower,int req[],int n)
{
    int req_copy[20],i,j,res,k;
    for(i=0;i<n;i++)
        req_copy[i] = req[i];
    sort(req_copy,n);
    for(i=0;i<n;i++)
    {
        if(req_copy[i]>hp)
        {
            res=abs(req_copy[i]-hp);
            for(j=i+1;j<n;j++)
            {
                res+=abs(req_copy[j]-req_copy[j-1]);
            }
            res+= (upper-req_copy[n-1] + abs(req_copy[0]-lower)+(upper-lower)) ;
            for(k=1;k<i;k++)
            {
                res+=abs(req_copy[k]-req_copy[k-1]);
            }
            break;
        }
    }
    printf("\nCSCAN \n ******* \n Total head movement: %d",res);
    
}
void main()
{
    int hp,n, upper , lower,i;
    printf("Enter head position:");
    scanf("%d",&hp);
    printf ("Enter lower limit and upper limit: ");
    scanf("%d %d",&lower,&upper);
    int req[20];
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter requests: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }   
    fcfs(hp,upper,lower,req,n);
    scan(hp,upper,lower,req,n);
    cscan(hp,upper,lower,req,n);
}