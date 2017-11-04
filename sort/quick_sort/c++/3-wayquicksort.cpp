#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int A[maxn];

void partition(int A[], int start, int end, int *index1, int *index2) {
	int small=start, large=end, curr=start+1, pivot=A[start];

	while(curr<=large) {

		if(A[curr]<pivot) {
			swap(A[small], A[curr]);	
			small++;
			curr++;		
		} else if(A[curr]>pivot) {
			swap(A[curr], A[large]);
			large--;
		} else{
			curr++;
		}
	}
	
	*index1=small;
	*index2=large;
	
	return ;
}

void quickSort(int A[], int start, int end) {
	if(start>end)
		return ;
		
	int index=rand()%(end-start+1)+start;
	
	swap(A[index], A[start]);
	
	int index1, index2;
	
	partition(A, start, end, &index1, &index2);
	
	quickSort(A, start, index1-1);
	
	quickSort(A, index2+1, end);
	
	return ;
	
}


int main() {
	int n, i;
	
	cin >> n;
	
	for(i=0; i<n; i++)
		cin >> A[i];
	
	quickSort(A, 0, n-1);
	
	for(i=0; i<n; i++)
		cout << A[i] << " ";
	
	return 0;
}
