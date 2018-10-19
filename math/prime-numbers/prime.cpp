#include<iostream>
int main()
{
	int i, j, value, count = 0;
	std::cout<<"Enter a value...";
	std::cin>>value;
	std::cout<<"The prime numbers till "<<value<<" are";
	for(i = 2 ; i < value ; i++)
	{
		for (j = 2; j < value; j++)
		{
			if(i % j == 0 && i != j)
				count++;
		}
		if(count<1)
			std::cout<<i<<endl;
		count = 0;
	}
}