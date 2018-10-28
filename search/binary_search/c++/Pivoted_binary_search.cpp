/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
You are given a target value to search. If found in the array, return its index, otherwise return -1.*/

int binarysearch(const vector<int> &A, int start, int end, int val)
{
    int sz = A.size();
    if(start<=end)
    {
        if(start==end && A[start]==val)
            return start;
        else if(start==end)
            return -1;
        int mid = start + (end-start)/2;
        if(A[mid]==val)
            return mid;
        else if(A[mid]>val)
            return binarysearch(A, start, mid-1, val);
        return binarysearch(A, mid+1, end, val);
            
    }
    return -1;
}

int search(const vector<int> &A, int B) {

    int pivotpoint = -1;
    int done = false;
    int start = 0;
    int end = A.size()-1;
    int sz = end+1;
    while(start<=end)
    {
     if(start==end)   
     {
         pivotpoint = start;
         break;
     }else{
         //case 1: mid is pivot

         int mid = start + (end-start)/2;
         if((mid==0 || A[mid]<A[mid-1]) && (A[mid]<A[mid+1] || mid==sz-1))
         {
             pivotpoint = mid;

             break;
         }else if(A[mid]>A[end])
         {
             start = mid+1;
         }
         else
         {
             end = mid-1;
         }
     }
     
    }
    
    if(pivotpoint ==0)
        return binarysearch(A, 0, sz-1, B);
    
    if(B>=A[0])
    {
        return binarysearch(A, 0, pivotpoint-1, B);
    }
    return binarysearch(A, pivotpoint, sz-1, B);
}

int main()
{
	cout<<"Enter the array length: ";
	int n;
	cin>>n;
	vector<int> a(n);
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<"Enter the element to find: ";
	int b; cin>>b;
	cout<<"Pivot Index found at: "<<search(a,b)<<endl;
}

