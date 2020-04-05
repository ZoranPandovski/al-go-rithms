#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int>&v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1])
                swap(v[j], v[j+1]);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    bubble(v);
    cout<<"Sorted array is\n";
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
