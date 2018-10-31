#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{string str = "\n\tDistrict Haridwar";
str.append("\n\t State - Uttarakhand");
ofstream iit("address.txt",ios::app);
if(!iit)
cout<<"File not found";
iit<<str<<endl;
iit.close();
return 0;
}
