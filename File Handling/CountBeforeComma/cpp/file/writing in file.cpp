#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{string str ="\t Department of Metallurgical and material engineering";
str.append("\n\tIndian Institute of Technology");
str.append("\n\tRoorkee");
str.append("\n\t PIN-247677");
ofstream iit;
iit.open("address.txt");
if(!iit)
cout<<"File not found";
iit<<str<<endl;
iit.close();
ifstream it;
it.open("address.txt");
if(!it)
cout<<"file not found";

while(it)
{
getline(it,str);
cout<<str<<endl;
}
it.close();


}
