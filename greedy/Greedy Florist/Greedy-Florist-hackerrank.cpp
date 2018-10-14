#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k,i,j,cost;
    cin>>n>>k;
    vector<int> c(n);
    vector<int> frnds(k,0);
    for(i=0;i<n;i++){
        cin>>c[i];
    }i=0;j=0;cost=0;
    sort(c.begin(),c.end(),greater<int>());
    
    while(i<n){
        if(j==k){j=0;}
        cost+=(frnds[j]+1)*c[i];frnds[j]++;j++;i++;
    }
    cout<<cost<<endl;
    return 0;
}/
