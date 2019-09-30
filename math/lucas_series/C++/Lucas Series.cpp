#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	
	int a1=2,a2=1,an,n;
	cout<<"Enter Number of Terms you want to Display (>2)\n";
	cin>>n;

	int i=0;
	cout<<a1<<","<<a2<<",";				//Printing First 2 Elements
	
	while(i<n-2){
		an=a1+a2;
		a1=a2;
		a2=an;
		cout<<an<<",";
		i++;
	}

	getch();
	return 0;
}