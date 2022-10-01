// this program is an implementation of max heap data structure. It returns the maximum element in O(1) time
// space complexity: O(n)
// n is number of keys in heap

// heap is a binary tree
// heap is stored and maintained in nothing but an array in which elements are stored in a
// particular order so that retrieval time of maximum/ minimum element is improved to O(1)

#include<bits/stdc++.h>
using namespace std;

// define the maximum size of heap
#define MAXSIZE 100

class MaxHeap
{
public:
    int arr[MAXSIZE];
    int size;

    MaxHeap()
    {
        size= 0;
    }

    // for each node in heap, its parent in array can be found at (node-1)/2
    int Parent(int node)
    {
        return (node-1)/2;
    }

    // for each node in heap, its left child in array can be found at 2*node+1
    int LeftChild(int node)
    {
        return 2*node +1;
    }

    // for each node in heap, its right child in array can be found at 2*node+2
    int RightChild(int node)
    {
        return 2*node +2;
    }

    // this function is used to insert a new element into heap at its correct location
    // Time complexity : O(log n)
    void Insert(int key)
    {

        // new element is first added at end of array
        size++;
        int curr= size-1;
        arr[curr] = key;

        // and then to maintain the maximum element at top, recurse to the top
        while(curr!=0 && arr[Parent(curr)]<arr[curr])
        {
            swap(arr[curr], arr[Parent(curr)]);
            curr= Parent(curr);
        }
    }

    // this returns the maximum element in O(1)
    // O(1)
    int Top()
    {
        return arr[0];
    }

    // this function helps to remove the top element from the heap
    // Time complexity: O(log n)
    void Pop()
    {
        // last element is brought to the top and then heapify is called to shift it to its appropriate position
        arr[0] = arr[size-1];
        size--;

        Heapify(0);
    }

    bool IsEmpty()
    {
        return size==0;
    }

    int Size()
    {
        return size;
    }

    // correct this subtree
    void Heapify(int idx)
    {
        int l = LeftChild(idx);
        int r = RightChild(idx);

        int largest = idx;

        if(l<size && arr[l]>arr[largest])
        {
            largest =l;
        }

        if(r<size && arr[r]>arr[largest])
        {
            largest= r;
        }

        if(largest == idx)
        {
            return;
        }
        swap(arr[idx], arr[largest]);
        Heapify(largest);
    }
};


int main()
{
    int n;
    cin>>n;

    int choice;

    // generate a new max heap
    MaxHeap *hp = new MaxHeap();

    for(int i=0;i<n;i++)
    {
        cin>>choice;

        // insert an element into heap
        if(choice==1)
        {
            int x;
            cin>>x;

            hp->Insert(x);
        }

        // print the top element
        // pop the top element
        else if(choice==2)
        {
            cout<<hp->Top()<<endl;
            hp->Pop();
        }
    }

    // print the size of heap
    cout<<hp->Size()<<endl;
}

/*
Testcases:
n = 3;
choice = 1, x = 1
choice = 1, x = 3
choice = 2

Output:
3
1
*/
