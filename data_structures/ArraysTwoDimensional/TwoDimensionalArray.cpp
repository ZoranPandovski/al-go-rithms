//Implementation of Two Dimensional array in C++

#include<iostream>
using namespace std;

class twoDarray
{
	int a[50][50],i,j,n,r,c,s1 = 0, s2 = 0,old,ne,del;
public:
	void insert();
	void display();
	void search();
	void update();
	void dele();
	void sumdiagonal();
};

void twoDarray::insert()
{
	cout<<"\nEnter the no. of rows and columns : ";
	cin>>r>>c;
	cout<<"\nEnter elements : ";
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			cin>>a[i][j];
	}
}

void twoDarray::display()
{
	cout<<"\nThe matrix is :";
	for(i = 0; i < r; i++)
	{
	    cout<<"\n";
		for(j = 0; j < c; j++)
			cout<<a[i][j]<<"\t";
	}
}

void twoDarray::search()
{
	cout<<"\nEnter element you want to search : ";
	cin>>n;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(a[i][j] == n)
			{
				cout<<"\nElement found at position :"<<i << " : "<< j;
				return;
			}
		}
	}
	cout<<"\nElement not found!";
}

void twoDarray::update()
{
    cout<<"\nEnter element to be updated : ";
    cin>>old;
    cout<<"\nEnter new value : ";
    cin>>ne;
    for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(a[i][j] == old)
			{
			    a[i][j] = ne;
			    return;
			}
		}
	}
}

void twoDarray::dele()
{
    cout<<"\nEnter element you want to delete : ";
    cin>>del;
    for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(a[i][j] ==del )
			{
				a[i][j++] = -1;
				cout<<"Row : "<<i<<" , Column : "<<j;
				return;
			}
		}
	}
}

void twoDarray::sumdiagonal()
{
    if( r == c)
    {
	    for(i = 0; i < r; i++)
	    {
		    for(j = 0; j < c; j++)
		    {
			    if(i == j)
			    {
				    s1+= a[i][j];
			    }
			    if(i == c-(j+1))
			    {
				    s2+= a[i][j];			
			    }
			
		    }
	    }
    }
    else
    {
        cout<<"\nMatrix is not sqaure. Sum of diagonal cannot be found!";
        return;
    }
	cout<<"\nSum of 1st diagonal is : "<<s1;
	cout<<"\nSum of 2nd diagonal is : "<<s2;
}

int main()
{
	twoDarray o;
	o.insert();
	o.display();
	o.search();
	o.update();
	o.display();
	o.dele();
	o.display();
	o.sumdiagonal();
	return 0;
}
