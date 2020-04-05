#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{ string str= "material engineering";
double a=1.0123456789;
int b=15;
bool flag=1;
cout.width(20);
cout<<str<<"[width(30)]"<<endl;
cout.width(10);
cout.fill('y');


cout<<" "<<str<<"[width-fill]"<<endl;
cout.width(20);
cout.fill('y');
cout<<str<<"[width-fill]"<<endl;
cout<<setw(10)<<setfill('x')<<""<<str<<"[setw setfill]"<<endl;
cout<<setw(20)<<setfill('x')<<str<<endl;
cout<<"a= "<<a<<endl;
cout<<setprecision(12)<<"a = "<<a<<"[setprecision]"<<endl;
cout<<showpos<<b<<"[showpos]"<<endl;
cout<<boolalpha<<flag<<endl;
}
