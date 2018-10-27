#include<iostream>
using namespace std;
int main(){
  int a[25],i,n;
  cout<<"Enter the number of elements you wanna enter:\n";
  cin>>n;
  cout<<"Enter the elements:\n";
  for(i=0;i<n;i++)
    cin>>a[i];
  for(i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            a[j]=a[j]+a[j+1];
            a[j+1]=a[j]-a[j+1];
            a[j]=a[j]-a[j+1];
        }
    }

    }
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";
return 0;

}
