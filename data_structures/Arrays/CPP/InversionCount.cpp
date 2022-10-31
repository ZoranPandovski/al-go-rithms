#include<iostream>
using namespace std;
 long long merge(long long v[],int l,int h,int m)
    {
        long long int i=l,t=l,j=m,k=0,ans=0;
        vector<long long> res;
        while(i<=m-1 && j<=h)
        {
            if(v[i]>v[j])
            {
                ans+=m-i;
                res.push_back(v[j]);
                j++;
            }
            else
            {
                res.push_back(v[i]);
                i++;
            }
        }
        
        while(i<=m-1)
        {
            res.push_back(v[i]);
            i++;
        }
        
        while(j<=h)
        {
            res.push_back(v[j]);
            j++;
        }
        
        for(auto &i : res)
        {
            v[t]=i;
            t++;
        }
        
        return ans;
    }
    long long count(long long v[],int l,int h)
    {
        if(l>=h)
          return 0;
        
        int m = l + (h-l)/2;
        
        long long int a = find(v,l,m);
        long long int b = find(v,m+1,h);
        long long int c = merge(v,l,h,m+1);
        
        return (a+b+c);
    }
int main()
{
   int n, count = 0;
   cout << "Enter number of elements : ";
   cin >> n;
   long long arr[n];
   cout << "Enter " << n << " elements:\n";
   for (int i = 0; i < n; i++)
       cin >> arr[i];
   
   cout <<"Output: "<< count(arr,n)<<". The inversions :";
   
}
