#include<iostream>
using namespace std;
int prime(int i);
int sum=0,product=1,k;     //sum is used for not printing last comma
int main()
{
	int n;
	cout<<"\t\t\tenter a no. ";
	cin>>n;
	k=n;
	cout<<"\t\t\t"<<n<<" = ";
	prime(n);
	return 0;
}
int prime(int n)
{   
	for(int i=2;i<=n;i++)
	{    
	    int flag=1;  //to check whether a no. is prime or not
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
			  flag=0;
			  break;	
			}
			
		}
		if(flag==1&&n%i==0&&product!=k)
		{  
			if(n%i==0&&sum==0)   //for not printing last comma
			{
			  cout<<i;
			  sum++;
		    }
		   else if(n%i==0&&sum!=0)
			{
			  cout<<" * "<<i;
			  sum++;
		    }
		    product*=i;
		    prime(n/i);
		}
		
	}
  
  return 0; 
}
