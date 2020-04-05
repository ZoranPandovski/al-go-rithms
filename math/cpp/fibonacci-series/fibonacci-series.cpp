#include<iostream>
//using namespace std;
int main()
{
	int n, x1 = -1, x2 = 1, x3 = 0;
	std::cout<<"Enter a value...";
	std::cin>>n;
	std::cout<<"The fibonacci series till "<<n<<" are"<<endl;
	for(int i = 0 ; i < n ; i++)
	{
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
		std::cout<<x3<<"\n";
	}
	return 0;
}