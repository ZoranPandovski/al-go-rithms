#include <bits/stdc++.h>
using namespace std;

void minHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[largest])
        largest = l;
    if (r < n && arr[r] < arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        minHeapify(arr, n, largest);
    }
}

void buildMinHeap(vector<int> &arr, int n)
{
    int lastNonLeaf = (n / 2) - 1;
    for (int i = lastNonLeaf; i >= 0; i--)
        minHeapify(arr, n, i);
}

int getMin(vector<int> &arr, int &n)
{
    int lastElement = arr[n - 1];
    int maxEl = arr[0];
    arr[0] = lastElement;
    n--;

    minHeapify(arr, n, 0);
    return maxEl;
}

void deleteK(vector<int>& arr, int &n, int p)
{
    int lastElement = arr[n - 1];
    arr[p] = lastElement;
    n--;

    minHeapify(arr, n, 0);
}

int main()
{
    vector<int> heap;
    int n,p;
    cin >> n>>p;
    for (int i = 0; i < n; i++)
    {
        int tp;
        cin >> tp;
        heap.push_back(tp);
        buildMinHeap(heap, heap.size());
    }

    deleteK(heap, n, p-1);
    int k = n;
    while (k)
    {
        cout << getMin(heap, k) << " ";
    }
    cout << endl;
    return 0;
}
