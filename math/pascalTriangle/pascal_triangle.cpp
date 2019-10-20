#include <iostream>

using namespace std;

int pascal(int i, int j)
{
	if ( i==j || j==0 )
		return 1;
	return (pascal(i-1,j)+pascal(i-1, j-1));
}

void draw_pascal(int n)
{
	for(int i=0; i<n ;i++)
	{
		for ( int j=0 ; j<=i; j++)
		{
			cout <<pascal(i,j) << '\t';
			fout <<pascal(i,j) << '\t';
		}
		cout << endl;
		fout << endl;
	}
	fout.close();

}

int main()
{
	int n;
	cout << "n: ";
	cin >> n;
	draw_pascal(n);
	return 0;
}
