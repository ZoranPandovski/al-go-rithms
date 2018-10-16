#include<stdio.h>
void main()
{
	int i,lb,ub,a[12]={10,9,8,7,6,9,8,5,4,3,2,1};
	void quick(int [],int,int);
	lb=0,ub=11;
        quick(a,lb,ub);
	for(i=0;i<12;i++)
	printf(" %d ",a[i]);
}

void quick (int a[],int lb,int ub)
{
   	int pivot,temp,l,u;
	u=ub,l=lb;
	temp=(l+u)/2;
	pivot=a[temp];
	while(l<=u)
	{
		for(;a[l]<pivot;l++);
		for(;a[u]>pivot;u--);
                  temp=a[l];
		  a[l]=a[u];
		  a[u]=temp;
		  u--,l++;

		if(lb<u)
        quick(a,lb,u);
		if(l<ub)
	quick(a,l,ub);
	}
}
