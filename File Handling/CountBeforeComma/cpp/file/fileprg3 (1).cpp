#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{ string str[16];
int i=0,j=0,last;
ifstream file("telephone directory.txt");
if(!file)
cout<<"File not found";
while(!file.eof())
{if((i+1)%4==0)getline(file,str[i++]);
else
getline(file,str[i++],'\t');
}
last=i;
i=0
;
while(i<last)
{cout<<"\nSerial No. :"<<++j;
 cout<<"\nForename   :"<<str[i++];
 cout<<"\nSurname    :"<<str[i++];
 cout<<"\nDepartment :"<<str[i++];
 cout<<"\nContact No.:"<<str[i++];
}
file.close();
}
