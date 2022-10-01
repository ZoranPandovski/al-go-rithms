
class LazySegmentTree 
{ 
	final int MAX = 1000;	 // Max tree size 
	int tree[] = new int[MAX]; // To store segment tree 
	int lazy[] = new int[MAX]; // To store pending updates 

	void updateRangeUtil(int si, int ss, int se, int us, 
						int ue, int diff) 
	{ 
		if (lazy[si] != 0) 
		{ 
			
			tree[si] += (se - ss + 1) * lazy[si]; 

			
			if (ss != se) 
			{ 
				 
				lazy[si * 2 + 1] += lazy[si]; 
				lazy[si * 2 + 2] += lazy[si]; 
			} 

			
			lazy[si] = 0; 
		} 


		if (ss > se || ss > ue || se < us) 
			return; 


		if (ss >= us && se <= ue) 
		{ 
			
			tree[si] += (se - ss + 1) * diff; 

			
			if (ss != se) 
			{ 
				 
				lazy[si * 2 + 1] += diff; 
				lazy[si * 2 + 2] += diff; 
			} 
			return; 
		} 

		
		int mid = (ss + se) / 2; 
		updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff); 
		updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff); 

		
		tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2]; 
	} 

	
	void updateRange(int n, int us, int ue, int diff) { 
		updateRangeUtil(0, 0, n - 1, us, ue, diff); 
	} 


	int getSumUtil(int ss, int se, int qs, int qe, int si) 
	{ 
		
		if (lazy[si] != 0) 
		{ 
		
			tree[si] += (se - ss + 1) * lazy[si]; 

			
			if (ss != se) 
			{ 
				
				lazy[si * 2 + 1] += lazy[si]; 
				lazy[si * 2 + 2] += lazy[si]; 
			} 


			lazy[si] = 0; 
		} 

		
		if (ss > se || ss > qe || se < qs) 
			return 0; 

	 

		if (ss >= qs && se <= qe) 
			return tree[si]; 


		int mid = (ss + se) / 2; 
		return getSumUtil(ss, mid, qs, qe, 2 * si + 1) + 
			getSumUtil(mid + 1, se, qs, qe, 2 * si + 2); 
	} 

	 
	int getSum(int n, int qs, int qe) 
	{ 
		// Check for erroneous input values 
		if (qs < 0 || qe > n - 1 || qs > qe) 
		{ 
			System.out.println("Invalid Input"); 
			return -1; 
		} 

		return getSumUtil(0, n - 1, qs, qe, 0); 
	} 


	void constructSTUtil(int arr[], int ss, int se, int si) 
	{ 
		
		if (ss > se) 
			return; 

		
		if (ss == se) 
		{ 
			tree[si] = arr[ss]; 
			return; 
		} 

		int mid = (ss + se) / 2; 
		constructSTUtil(arr, ss, mid, si * 2 + 1); 
		constructSTUtil(arr, mid + 1, se, si * 2 + 2); 

		tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2]; 
	} 


	void constructST(int arr[], int n) 
	{ 
		 
		constructSTUtil(arr, 0, n - 1, 0); 
	} 



	public static void main(String args[]) 
	{ 
		int arr[] = {1, 3, 5, 7, 9, 11}; 
		int n = arr.length; 
		LazySegmentTree tree = new LazySegmentTree(); 

	
		tree.constructST(arr, n); 

		
		System.out.println("Sum of values in given range = " + 
						tree.getSum(n, 1, 3)); 

		
		tree.updateRange(n, 1, 5, 10); 

		
		System.out.println("Updated sum of values in given range = " + 
						tree.getSum(n, 1, 3)); 
	} 
} 

