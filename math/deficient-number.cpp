string isDeficient(long long int x) {
        long long int sum=0,n=x;
        for(long long int i=1;i<=sqrt(x);i++)
        {
            if(n%i==0)
            {
                if((n/i)==i)
                sum+=i;
                else 
                {
                    sum+=(n/i);
                    sum+=i;
                }
            }
        }
        if((2*x)-sum>0)
        return "YES";
        return "NO";
    }