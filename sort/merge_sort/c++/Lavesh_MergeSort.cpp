#include<iostream>
using namespace std;
void merge(int *a,int p,int q,int r)
{
	int lb1=p,ub1=q,lb2=q+1,ub2=r,n1=q-p+1,n2=r-q;
	int arr[n1+n2+1],k=1,i,j;
	for(i=lb1,j=lb2;i<=ub1 && j<=ub2;k++)
	{
		if(a[i]>a[j])
		{
			arr[k]=a[j];
			j++;
		}
		else 
		{	arr[k]=a[i];
			i++;	
		}
	}
	while(i<=ub1)
	{
		arr[k++]=a[i];
		i++;
	}
	while(j<=ub2)
	{
		arr[k++]=a[j];
		j++;
	}
	for(int i=1;i<n1+n2+1;i++)
	{
		a[p++]=arr[i];
	}
}
void merge_sort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int p=1,r=n;
	merge_sort(a,p,r);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
