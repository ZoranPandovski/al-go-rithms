#include<iostream>
using namespace std;
long long power(long long a,int n){
	if(n==0)
	  return 1;
	if((n%2)==0)
	  return power(a*a,n/2);
	else
	  return a*power(a*a,n/2);    
}
int main(){
	long long a;
	int n;
	cout<<"Enter the value of a"<<endl;
	cin>>a;
	cout<<"Enter the value of the power"<<"\n";
	cin>>n;
	cout<<"The value of "<<a<<"^"<<n<<" is: "<<power(a,n); 
    return 0; 
}
