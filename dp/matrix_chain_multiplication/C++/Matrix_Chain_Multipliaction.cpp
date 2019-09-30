#include<iostream>
#include<conio.h>
using namespace std;
long int m[50][50],p[50],s[50][50];
void matrix_chain(int n){
long int i,j,k,l,q;
for(i=1;i<=n;i++)
{
	m[i][i]=0;
}
for(l=2;l<=n;l++)
{
	for(i=1;i<=n-l+1;i++)
	{	j=i+l-1;
	m[i][j]=20000;
	for(k=i;k<j;k++)
	{
		q=(m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
		if(q<m[i][j])
		{
			m[i][j]=q;
			s[i][j]=k;
		}
	}	
	}
}
}
void display(long int s[50][50],int i,int j)
{
	if(i==j)
	{
		cout<<"A"<<i;
	}
	else
	{
		cout<<"(";
		display(s,i,s[i][j]);
		display(s,s[i][j]+1,j);
		
}
}
main()
{
	long int n,i,j;
	cout<<"Enter number of matrices:";
	cin>>n;
	cout<<"Enter Order Array:"<<endl;
for(i=0;i<=n;i++)
{
	cin>>p[i];
}
	matrix_chain(n);
	cout<<"M Table : "<<endl;
for(int l=1;l<=n;l++)
{
	for(int i=1;i<=n;i++)
	{
		cout<<m[l][i]<<"\t";
	}
	cout<<endl;
}
cout<<"S Table : "<<endl;
for(int l=1;l<=n;l++)
{
	for(int i=1;i<=n;i++)
	{
		cout<<s[l][i]<<"\t";
	}
	cout<<endl;
}
cout<<"Most efficient way to multiply given sequence of
matrices is:"<<endl;
display(s,1,n);
getch();
}