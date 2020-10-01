#include<iostream>
int main()
{
	int value, count = 0;
	std::cout<<"Enter a value...";
	std::cin>>value;
	std::cout<<"The prime numbers till "<<value<<" are"<<endl;
	for(int i = 2 ; i < value ; i++)
	{
		for (int j = 2; j < value; j++)
		{
			if(i % j == 0 && i != j)
				count++;
		}
		if(count<1)
			std::cout<<i<<"\n;
		count = 0;
	}
}