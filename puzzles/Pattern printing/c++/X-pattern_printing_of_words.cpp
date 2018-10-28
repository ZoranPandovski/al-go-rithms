#include<iostream>
using namespace std;
int main(){
    int n,i,j,k=0,m=0;
    cin>>n;
    for(i=0;i<n*2-1;i++){
            if(m==0)
                ++k;
            else
                --k;
        for(j=0;j<n*2-1;j++){
            if(i==n-1&&j==n-1){
                cout<<k;m++;break;
            }
            else if(j==i||j==n*2-i-2){
                cout<<k;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
