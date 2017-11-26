#include<stdio.h>

int a[1000000];

void merge(int low, int mid, int high){
	int n1=mid-low+1;
	int n2=high-mid;
	int i,j,k;
	int left[1000000],right[1000000];

	for(i=0;i<n1;i++)
		left[i]=a[low+i];
	for(i=0;i<n2;i++)
		right[i]=a[mid+1+i];
	i=0,j=0,k=low;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			a[k++]=left[i++];
		}
		else{
			a[k++]=right[j++];
		}
	}
	while(i<n1)
		a[k++]=left[i++];
	while(j<n2)
		a[k++]=right[j++];
}

void sort(int low, int high){
	int mid;
	//mid = (low+high)/2;
	if(low<high){
		mid = (low+high)/2;
		sort(low,mid);
		sort(mid+1,high);
		merge(low,mid,high);
	}
}

int main(){
	int n,len;
	int i=0;
	while(scanf("%d",&n)!=EOF){
		a[i++]=n;
	}
	len=i;
	//printf("%d\n",i);
	//for(i=0;i<len;i++)
	//	printf("%d ", a[i]);
	//printf("\n");
	sort(0,len-1);
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
