#include <iostream>

using namespace std;

long coin_change(int n,int m,int *C)
{
	long table[n+1][m+1];                                              //Creating the dp table of n+1 rows and m+1 columns.
	long x,y;

	for(int i=0;i<m+1;i++)                                            //There is only 1 way to make change for 0 cents.
		table[0][i] = 1;
	for(int i=1;i<n+1;i++)
		table[i][0] = 0;                                              //When the number of available types of coins is zero there is no way to make change

	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i>=C[j])
			{
				x = table[i-C[j]][j];                                 //When C[j] denomination is used to make change
			}
			else 
				x = 0;
			if(i>0)
			{
				if(j==0)
					y = 0;
				else
					y = table[i][j-1];                                //When it is not used
			}
			else 
				y = 0;

			table[i][j] = x+y;                                        //Total number of ways will be a sum of these two
		}
	}
	return table[n][m-1];                                             //Returning the required answer from the dp table
}

int main()
{
	int n=5,m=3;                                                      //To make change for 5 cents using infinite supply of coins of denominations 1,2,3

	int C[3] = {1,2,3};

	long ways;

	ways = coin_change(n,m,C);

	cout<<"The number of ways to make the required change is "<<ways<<"."<<endl;
	
	return 0;
}