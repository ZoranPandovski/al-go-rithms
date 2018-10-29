## using Recursion Binary search implementation #################

int binarySearch(int arr[], int right, int left, int x){
	
	while(left<=right){
		
		int mid = left + (right-left)/2;
			
			if(arr[mid]==x){
				
				return m;
			}
          if(arr[mid] <x){
		  
		  left = md+1;
	  }
		else 
		{ right = mid-1;
		
		return -1;
	}
		
		int main(void){
			
			int arr[5] = {2, 4,7,9,8,5};
			
			int n = sizeof(arr)/ sizeof(arr[0]);
			int x=9;
			
			int outcome = binarySearch(arr,0,n-1, x);
                         
			(result == -1)?
				cout<< outcome
				
				return 0;
			
			
			
			
			
