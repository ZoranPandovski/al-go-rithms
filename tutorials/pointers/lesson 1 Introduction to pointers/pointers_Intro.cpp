#include<iostream>
using namespace std;
int main(){
int a=1025;
int *p;
p=&a;
cout<<"Size of an integer variable is :"<<sizeof(int)<<" Bytes"<<endl;
cout<<"Address is :"<<p<<" And  Value is :"<<*p<<endl;
cout<<"Address is :"<<p+1<<" And  Value is :"<<*(p+1)<<endl;
char *q;
q=(char*)p;  //typecasting here-
cout<<"Size of an Character variable is :"<<sizeof(char)<<" Bytes"<<endl;
cout<<"Address is :"<<q<<" And  Value is :"<<*q<<endl;
cout<<"Address is :"<<q+1<<" And  Value is :"<<*(q+1)<<endl;


return 0;
}
