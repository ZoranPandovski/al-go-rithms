#include <iostream>

using namespace std;

int bubblesort(int arr[], int len){
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			count++;
		}
	}
	return count;
}

int main(void){
	int n;
	cout << "Enter size of the array : " << endl;
	cin >> n;
	int arr[n];
	cout << "Enter elements of the array : " << endl;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int count = bubblesort(arr, n);

	cout << "Array After Sorting : " << endl;
	for (int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
	cout << "Steps taken : " << count << endl;
	return 0;
}
