#include<iostream>
using namespace std;
void search(int x[], int p, int q, int r)
{
	int mid=(p+q)/2;
	if(x[mid]==r)
	{
		cout<<"Found at posiiton "<<mid+1;
		return;
	}
	else if(r>x[mid])
	search(x,mid+1,q,r);
	else if(r<x[mid])
	search(x,p,mid-1,r);
	else
	{
		cout<<"Element not found";
		return;
	}
}

int main(){
    int arr[100],i,j,k,l,n,temp,flag=0;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Sorted array is"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"enter the element you want to search"<<endl;
    cin>>l;
    search(arr,0,n-1,l);
	return 0;
}
