#include<stdio.h>
void add(long long int n1[],long long int n2[],long long int s[],long long int c[])
{
  for(int i=7;i>=0;i--)
  {
  s[i]=n1[i]^n2[i]^c[i+1];
  c[i]=(n1[i]&n2[i])|(n1[i]&c[i+1])|(c[i+1]&n2[i]);
  }
  if(c[0]==c[1])
  {
  for(int i=0;i<8;i++)
    {
    printf("%lld",s[i]);
    }
  }

  else{
  if(c[0]==0 && c[1]==1)
  printf("Overflow\n");
  else{
  printf("Underflow\n");
  }
}

}

int main()
{
printf("Enter two 8 bit binary numbers for addition\n");
long long int a,b;
scanf("%lld",&a);
scanf("%lld",&b);
long long int n1[8]={0},n2[8]={0},s[8],c[9]={0},n3[8]={0},n4[8]={0,0,0,0,0,0,0,1};
int i=7;
int t1=8,t2=8;
while(t1>0)
{

  long long int l=a%10;
  n1[i]=l;
  i--;
  a=a/10;
  t1--;
}

int j=7;
while(t2>0)
{

   long long int k=b%10;
   n2[j]=k;
   j--;
   b=b/10;
t2--;
}
add(n1,n2,s,c);
}
