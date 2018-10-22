#pragma once
#include <iostream>
using namespace std;
//Heap sort
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void Heapify(int Heap[], int i, int n)	//n la so phan tu con lai trong Heap
{
	if (i * 2 + 1 <= n - 1)
	{
		int child1 = i * 2 + 1, child2 = i * 2 + 2, tmp = child1;
		if (Heap[child2] > Heap[child1] && i * 2 + 2 <= n - 1) tmp = child2;
		if (Heap[i]< Heap[tmp])
		{
			swap(Heap[i], Heap[tmp]);
			Heapify(Heap, tmp, n);
		}
	}
}
void heap_sort(int Heap[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--) Heapify(Heap, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(Heap[i], Heap[0]);
		Heapify(Heap, 0, i);
	}
}


//merge sort
void merge(int a[], int l, int r)
{
	int m = (l + r) / 2;
	int *b = new int[r - l + 1], n1 = m - l + 1, n2 = r - m;
	int tmp = 0, tmp1 = l, tmp2 = m + 1;
	while (tmp1 <= m && tmp2 <= r)
	{
		if (a[tmp1] < a[tmp2])
		{
			b[tmp] = a[tmp1];
			tmp++;
			tmp1++;
		}
		else
		{
			b[tmp] = a[tmp2];
			tmp++;
			tmp2++;
		}
	}
	while (tmp1 <= m)
	{
		b[tmp] = a[tmp1];
		tmp++;
		tmp1++;
	}
	while (tmp2 <= r)
	{
		b[tmp] = a[tmp2];
		tmp++;
		tmp2++;
	}
	tmp = 0;
	for (int i = l; i <= r; i++)
	{
		a[i] = b[tmp];
		tmp++;
	}
	delete b;
}
void merge_array(int a[], int l, int r)
{
	if (l == r) return;
	int m = (l + r) / 2;
	merge_array(a, l, m);
	merge_array(a, m + 1, r);
	merge(a, l, r);
}
void merge_sort(int a[], int n)
{
	merge_array(a, 0, n - 1);
}
//Quick sort
void quicksort(int a[], int l, int r)
{
	int key = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < key) i++;
		while (a[j] > key) j--;
		if (i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}
void quick_sort(int a[], int n)
{
	quicksort(a, 0, n - 1);
}
//Selection sort
void Selection_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int tmp = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[tmp]) tmp = j;
		}
		int tg = a[tmp];
		a[tmp] = a[i];
		a[i] = tg;
	}
}


//Insertion sort
void Insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		bool check = true;
		int tmp = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp < a[j])
			{
				a[j + 1] = a[j];
			}
			else
			{
				a[j + 1] = tmp;
				check = false;
				break;
			}
		}
		if (check) a[0] = tmp;
	}
}

//Binary insertion sort
int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}
void binaryInsertion_sort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

//Bubble sort
void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j=0;j<n-1;j++)
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
	}
}


//Shell sort
void shell_sort(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{		
		for (int i = gap; i < n; i += 1)
		{		
			int tmp = a[i];		
			int j;
			for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
				a[j] = a[j - gap];
			a[j] = tmp;
		}
	}
}

//Shaker sort
void shaker_sort(int a[], int n)
{
	int l = 0, r = n - 1;
	int k = 0;
	while (l < r)
	{
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}

//Counting sort
void counting_sort(int a[], int n)
{
	int max = 0;
	int *count = new int[1000001];
	for (int i = 0; i < 1000001; i++) count[i] = 0;
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
		if (max < a[i]) max = a[i];
	}
	int tmp = 0;
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			a[tmp] = i;
			tmp++;
			count[i]--;
		}
	}
	delete[] count;
	
}
//Radix Sort
int max(int a[], int n)
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
		if (a[i]>tmp) tmp = a[i];
	return tmp;
}
int pow(int a)
{
	int res = 0;
	while (a > 0)
	{
		a /= 10;
		res++;
	}
	return res - 1;
}
void count_sort(int a[], int n, int exp)
{
	int count[20] = { 0 };
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10] ++;
	}
	for (int i = 1; i < 20; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		arr[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = arr[i];
	delete[]arr;
}
void radix_sort(int a[], int n)
{
	int d = pow(max(a, n));
	int tmp = 1;
	for (int i = 0; i <= d; i++)
	{
		count_sort(a, n, tmp);
		tmp *= 10;
	}
}