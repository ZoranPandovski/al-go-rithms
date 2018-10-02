#include<iostream>
#include<map>
#include<string.h>
#include<fstream>
#include<list>
using namespace std;
  int count,len,k=0,i=0;
  char ch2[100];
  string x;
  list<string>l1;
  list<string>l2;
  list<string>::iterator itr;

  void weddingCount()
  {
      for(i=0;i<len;i++)
    {
        if(x[i]!=',')
        {
            ch2[k]=x[i];
            k++;
        }
        if(x[i]==',')
        break;
    }

  }
int main()
{
  fstream myfile("file.txt");
  //cout<<count;
  while(!myfile.eof())
  {
    myfile>>x;
    l1.push_back(x);
  }
for(itr=l1.begin();itr!=l1.end();itr++)
{
  x=*itr;
  k=0;
  len=x.length();
  weddingCount();
ch2[k]='\0';
l2.push_back(ch2);
}
char arr2[100];
k=0;
map<string,int> m;
for(itr=l2.begin();itr!=l2.end();itr++)
{
++m[*itr];
m.insert(pair <string,int>(*itr,k));
}
map<string,int>::iterator it;
for(it=m.begin();it!=m.end();it++)
{
cout<<it->first<<"\t"<<it->second<<"\n";
}


}
