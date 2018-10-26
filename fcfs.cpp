#include <iostream>
using namespace std;

int main()
{
	int AT[4];
	for(int i=0;i<4;i++)
	{
		cin>>AT[i];
	}
	
	int CT[4];
	int BT[]={4,2,6,3};
	CT[0]=BT[0];
	for(int i=1;i<4;i++)
	{
		int s=0;
		for(int j=0;j<i;j++)
		{
			s+=BT[j];
		}
		int e;
		if(AT[i]>CT[i-1])
		{
			e=AT[i]-BT[i-1];
		}
		else
		{
			e=0;
		}
		CT[i]=e+BT[i]+CT[i-1];
		
	}
	for(int i=0;i<4;i++)
	{
		cout<<CT[i]<<" ";
	}
	int TAT[4];
	int WT[4];
	int s=0;
	
	return 0;
}