#include<stdio.h>
#define s(x) scanf("%d",&x)
#define f(i,n) for(i=1;i<=n;i++)

void update(int i, int x, int *BIT, int n)
{
    for(;i<=n;i+=i&(-i))
    {
        //printf("%d\n",BIT[i]);
        BIT[i]+=x;
    }
}
int query(int x, int *BIT)
{
    int sum=0;
    for(;x>0;x-=x&(-x))
    {
        sum+=BIT[x];
    }
    return sum;
}
int main()
{
    int *BIT,*a,i,n;
    s(n);
    BIT=(int *)malloc((n+1)*sizeof(int));
    memset(BIT,0,(n+1)*sizeof(int));
    a=(int *)malloc((n+1)*sizeof(int));
    f(i,n)
    {
        printf("c");
        s(a[i]);
        update(i,a[i],BIT,n);
    }
    //f(i,n)printf("%d\n",BIT[i]);
    int x,y;
    s(x),s(y);
    printf("%d\n",query(y,BIT)-query(x-1,BIT));
    return 0;
}
