include<stdio.h>
#include<conio.h>
void  tsearch(int *a,int i,int j,int k);
main() {
  int a[30],n,i,k;
        printf("\nEnter n:");
  scanf("%d",&n);
  printf("\nEnter nos in ascending order:");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  printf("Enter no to search:");
  scanf("%d",&k);
  tsearch(a,0,n-1,k);

  getch();
}

void tsearch(int *a,int i,int j,int k) {
  int m1,m2;
  m1=(i+j)/3;
  m2=2*(i+j)/3;
  if(k==a[m1])
   {
    printf("\nno found at %d",m1);
    return;
   }
  else  if(k==a[m2])
   {
    printf("\nno found at %d",m2);
    return;
   }
  if(k<a[m1])
    return(tsearch(a,i,m1-1,k));
  if(k>a[m2])
    return(tsearch(a,m2+1,j,k));
  else   
    return(tsearch(a,m1+1,m2-1,k));
}
