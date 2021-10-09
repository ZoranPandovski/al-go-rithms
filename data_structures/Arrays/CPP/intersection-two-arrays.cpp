 int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        unordered_map<int,int> mp;
        int ctr=0;
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        for(int i=0;i<m;i++)
        {
            if(mp[b[i]]>0)
            {
                ctr++;
                mp[b[i]]=0;
            }
        }
        return ctr;
    }
    