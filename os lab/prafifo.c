/*Page segmented algo using fifo*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j,n1,flag=0,flag1=0,num,k;


	printf("Enter the  number of frames\n");
	scanf("%d",&n);
	int arr[n],pfault[n];
	printf("Enter the sequence of frame\n");
	for(i=0;i<n;i++)
        {
		scanf("%d",&arr[i]);
		pfault[i]=0;
	}

	printf("Enter the number of working frames at a time\n");
	scanf("%d",&n1);
	int f_arr[n1][n];

	for(i=0;i<n1;i++)
	{
		for(j=0;j<n;j++)
		{
			f_arr[i][j]=-56;
		}
	}

	for(i=0;i<n;i++)
	{	flag=0;flag1=0;
		for(j=0;j<n1;j++)
		{
			if(arr[i]==f_arr[j][i])
			{
				flag=1;
				pfault[i]=0;
				break;
			}
		}
		if(flag==1)
		continue;
		if(flag==0)
		{
			pfault[i]=1;
			for(j=0;j<n1;j++)
			{
				if(f_arr[j][i]==-56)
				{
					for(k=i;k<n;k++)
					f_arr[j][k]=arr[i];
					flag1=1;
					break;
				}
			}
			if(flag1==0){
				num=arr[i-n1];
				for(j=0;j<n1;j++)
				{
					if(f_arr[j][i]==num)
					{
						for(k=i;k<n;k++)
						f_arr[j][k]=arr[i];
						break;
					}
				}
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
	printf("\n\n");
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			if(f_arr[i][j]!=-56)
			printf("%d  ",f_arr[i][j]);
			else{
				printf("   ");
			}
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(pfault[i]==0)
		printf("X  ");
		else
		printf("F  ");
	}
	printf("\n");
  return 0;
}




























					
