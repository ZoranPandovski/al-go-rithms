#include<iostream>
using namespace std;
int main()
{
	int a[20],n,j,gap,item;
	cout<<"Enter the number of elements: ";
	cin>>n;
	gap=n/2;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(gap>=1)
	{
		for(int i=gap;i<n;i=i+gap)
		{
			item=a[i];
			for(j=i-gap;j>=0 && a[j]>item;j=j-gap)
			{
				a[j+gap]=a[j];
			}
			a[j+gap]=item;
		}
		gap=gap/2;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
