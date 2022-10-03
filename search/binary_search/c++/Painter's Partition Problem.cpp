// If by a certain case we can neglect a particular part of the search space then we should be using B.S.

// Statement
Given an array/list of length 'N', where the array/list represents the boards and each element of the 
given array/list represents the length of each board. Some 'K' numbers of painters are available to paint 
these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the 'N' 
boards under a constraint that any painter will only paint the continuous sections of boards.

// Example
Input:- k=2 and arr=[10,20,30,40]
Output:- 60

we can divide the first 3 boards for one painter and the last board for the second painter.

bool ispossiblesol(vector<int> &arr,int n,int k,int mid){
	int painter=1,res=0;
	for(int i=0;i<n;i++){
		if(res+arr[i]<=mid){
			res=res+arr[i];
		}
		else{
			painter++;
			if(painter>k ||arr[i]>mid){
				return false;
			}
			res=arr[i];
		}
	}
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int size=boards.size(),sum=0,s=0,e,mid,ans=-1;
	for(int i=0;i<size;i++){
		sum+=boards[i];
	}
	e=sum;
	while(s<=e){
		mid=s+(e-s)/2;
		if(ispossiblesol(boards,size,k,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}
