#include <iostream>
#include <stdio.h>


using namespace std;

class Rmn
{
public:
int dd,mm,m,yy,YY;
void getData();
void showData();
};

void Rmn::getData()
{

  cout<<"\n The program to generate Ramanujam's Birthday Magic Square\n";

  cout<<"\n Enter your Date of Birth in the order of day (dd) ,month (mm) and year in the form (YYYY) \n";
  //bug fixed
  cin>>dd;
  if(dd>31){
    cout<<"Day can be only between 1 and 31"<<endl;
    int temp;
    cin>>temp;
    dd=temp;
    cout<<"Enter the month"<<endl;
  }
  cin>>mm;
  if(mm>12){
    cout<<"Month can be only between 1 and 12 inc."<<endl;
    int temp;
    cin>>temp;
    mm=temp;
    cout<<"Enter the year"<<endl;
  }
  cin>>m;
  yy=(m/1000)*10 + (m%1000/100);
  YY=m%100;


}

void Rmn::showData()
{
  int a[4][4];
 a[0][0]=dd;
 a[0][1]=mm;
 a[0][2]=yy;
 a[0][3]=YY;
 a[1][0]=YY+1;
 a[1][1]=yy-1;
 a[1][2]=mm-3;
 a[1][3]=dd+3;
 a[2][0]=mm-2;
 a[2][1]=dd+2;
 a[2][2]=YY+2;
 a[2][3]=yy-2;
 a[3][0]=yy+1;
 a[3][1]=YY-1;
 a[3][2]=dd+1;
 a[3][3]=mm-1;

 for(int i=0;i<=3;i++)

 {
   for(int j=0;j<=3;j++)
   {
 cout<<" "<<a[i][j]<<" ";

   }
  cout<<endl;

 }
int sum;
sum=dd+mm+yy+YY;

 cout<<"the sum of every row, column, diagonal, and most 2x2 blocks is =  "<<sum;

}

int main()
{

  Rmn r;

  cout<<"The Ramanujam Birthday Magic square is a mathematical puzzle that'll generate a 4x4 square that has the  same sum across every row,column,diagonal and most 2x2 block  ";

  r.getData();
  r.showData();
  return 0;


}
