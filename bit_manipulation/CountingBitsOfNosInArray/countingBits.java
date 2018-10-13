class Solution {
    public int[] countBits(int num) {
        int[] arr=new int[num+1];
        arr[0]=0;
        if(num==0)
        {
            return arr;
        }
        arr[1]=1;
        for(int i=2;i<=num;i++)
        {
            if((i&1)==1)
            {
                arr[i]=1+arr[i-1];   
            }
            else
            if((i&(i-1))==0)
            {
                arr[i]=1;
            }
            else
            {
                arr[i]=arr[i/2];
            }
        }
        return arr;
    }
}
