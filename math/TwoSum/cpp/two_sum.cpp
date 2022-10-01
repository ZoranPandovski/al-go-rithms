#include<iostream>
using namespace std;
int sumPair(int a[],int n,int s){
    int i=0;
    int j=n-1;
    while(i<j){
        int cs=a[i]+a[j];
        if(cs>s){
            j--;
        }
        else if(cs<s){
            i++;
        }
        else if(cs==s){
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
    }
}
int main(){
    int n,s;
    cin>>s;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sumPair(a,n,s);
}

