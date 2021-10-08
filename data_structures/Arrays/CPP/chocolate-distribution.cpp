long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    long long int l=0,r=m-1,minm=1e18+9;
    while(r<n)
    {
        minm=min(minm,a[r]-a[l]);
        l++;
        r++;
    }
    return minm;
}