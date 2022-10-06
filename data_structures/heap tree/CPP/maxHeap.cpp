#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr, int n)
{
    int lastNonLeaf = (n / 2) - 1;
    for (int i = lastNonLeaf; i >= 0; i--)
        maxHeapify(arr, n, i);
}

int getMax(vector<int> &arr, int &n)
{
    int lastElement = arr[n - 1];
    int maxEl = arr[0];
    arr[0] = lastElement;
    n--;

    maxHeapify(arr, n, 0);
    return maxEl;
}

int main()
{
    vector<int> heap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tp;
        cin >> tp;
        heap.push_back(tp);
        buildMaxHeap(heap, heap.size());
    }

    int k = n;
    while (k)
    {
        cout << getMax(heap, k) << " ";
    }
    cout << endl;
    return 0;
}
