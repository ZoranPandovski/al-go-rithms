int i,n,max,sum;
n=nums.size();
max=INT_MIN;
sum=0;

for(i=0;i<n;i++)
{
    sum=sum+nums[i];
    if(sum>max)
    {
        max=sum;
    }

    if(sum<0)
    {
        sum=0;
    }

}
return max;
