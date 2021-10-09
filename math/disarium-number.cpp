int isDisarium(int N) {
        // code here
        int n=N,m=N;
        int ctr=0;
        while(n!=0)
        {
            ctr++;
            n/=10;
        }
        long long sum=0;
        while(m!=0)
        {
            sum+=pow(m%10,ctr--);
            m=m/10;
            if(sum>N)
            return 0;
        }
        if(sum==N)
        return 1;
        return 0;
    }