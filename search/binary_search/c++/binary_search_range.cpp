/* akash mahalik
	https://github.com/akashmahalik
	This basically returns the range in which the value to be searched is present in the vector
	Eg : = [ 1 , 2 , 3 , 3 , 3 , 4] If we search for 3 this will return an vector [2 , 4]
	 indicating that 3 is present from position 2 to 4
	 Will return a vector [-1 , -1] if the value to be found is not present .
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> binary_search_range(const vector<int> &A, int B) {
   
    int n = A.size();
        int i = 0, j = n - 1;
        vector<int> ret(2, -1);
        // Search for the left one
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < B) i = mid + 1;
            else j = mid;
        }
       
        if (A[i]!=B) return ret; // If the number doesn't exist
       
        else ret[0] = i;
       
       
        // Search for the right one
        j = n-1;  // We don't have to set i to 0 the second time.
       
        while (i < j)
        {
            int mid = (i + j) /2 + 1;   // Make mid biased to the right
            if (A[mid] > B) j = mid - 1;  
            else i = mid;               // So that this won't make the search range stuck.
        }

        ret[1] = j;
        
        return ret; 
    
}
int main()
{	vector<int> v,v_test,result;
	int x,n,to_Search;;
	
	cout<<"Enter the size of the array ";
	cin>>n;
	cout<<"Enter "<<n<<" numbers :";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	v_test = v;
	sort(v_test.begin(),v_test.end());
	for (int i = 0; i < n; ++i)
	{
		if(v_test[i]!=v[i])
		{
			cout<<"The array entered is not sorted. "<<endl;
			return 0;
		}
	}
	
	cout<<"Enter the number to search :";
	
	cin>>to_Search;
	

	result = binary_search_range(v,to_Search);
	if(result[0]!=-1)
	cout<<to_Search<<" is Present in the array from "<<result[0]<<" to "<<result[1]<<"."<<endl;
	else
	cout<<to_Search<<" is Not Present in the array"<<endl;
}