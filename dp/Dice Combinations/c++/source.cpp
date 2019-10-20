
  #include<bits/stdc++.h>
  using namespace std;
  //
  #define ll    long long int
  const ll mod=1e9+7;
  //
  //
    int vec[1000001];

  int main(){
    vec[0]=1;
    vec[1]=1;

    ll n;
    cin>>n;
    
    for(int i=2;i<=n+1;i++){
        for(int j=1;j<=6;j++)
        vec[i]+= ((i-j)>=0)? vec[i-j]: 0;
      
      vec[i]%=mod;
    }
    
    cout<<vec[n];
    return 0; 
}   