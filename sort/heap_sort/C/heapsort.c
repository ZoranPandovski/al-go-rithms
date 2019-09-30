#include <stdio.h>
#define LENGTH 10

int heapSize;

void Heapify(int* A, int i) //Heapify tree at every call
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest;

  //Checking if root node has the greatest value among other nodes
  if(l <= heapSize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if(r <= heapSize && A[r] > A[largest])
    largest = r;
  if(largest != i) //Recursive call from here
    {
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      Heapify(A, largest);
    }
}

void BuildHeap(int* A) //Called in the beginning just once 
{
  heapSize = LENGTH - 1;
  int i;
  for(i = (LENGTH - 1) / 2; i >= 0; i--)
    Heapify(A, i);
}

void HeapSort(int* A)
{
  BuildHeap(A); //Building heap for the first time
  int i;
  for(i = LENGTH - 1; i > 0; i--)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      Heapify(A, 0); //Recursively heapifying
    }
}

int main()

{
  int ar[LENGTH] = {1,4,2,6,88,5,8,2,9,3};
  HeapSort(ar);
  int i;

  for(i = 0; i < LENGTH; i++)
    printf("%d ",ar[i]);
  return 0;
}