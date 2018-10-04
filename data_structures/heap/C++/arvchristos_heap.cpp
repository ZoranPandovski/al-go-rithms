/*************************************************************************************
*
*   ░▀█▀░█▀█░▀█▀░░░█░█░█▀▀░█▀█░█▀█░░░█▀▀░▀█▀░█▀▄░█░█░█▀▀░▀█▀░█░█░█▀▄░█▀▀
*   ░░█░░█░█░░█░░░░█▀█░█▀▀░█▀█░█▀▀░░░▀▀█░░█░░█▀▄░█░█░█░░░░█░░█░█░█▀▄░█▀▀
*   ░▀▀▀░▀░▀░░▀░░░░▀░▀░▀▀▀░▀░▀░▀░░░░░▀▀▀░░▀░░▀░▀░▀▀▀░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀
*
*   Int heap structure implementation using vectors instead of arrays.
*   Holds integers.
*   Can be initialized from existing array,vector or by inserting elements one by one.
*
*
*   Basic operations:
*     1.void insert(int element):   Insert element to heap
*     2.int deletemax():            Delete and return the maximum element from heap
*     3.int peek_max():             Return max element without deleting it from heap
*     4.bool isEmpty():             Check if heap is Empty
*     5.int getHeapSize():          Return heap size
*     6.void printHeap():           Print heap content
*************************************************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>

using namespace std; //Not the best tactic, used for cleaner code and better understanding

class Heap {
  private:
    std::vector<int> heap;
    int hpsz;
  
  public:

    Heap(){
            hpsz=0; //At first the Heap is Empty
            heap.push_back(0);  //Index 0 must be initialized because we start indexing from 1
    }

    Heap(std::vector<int>& array){
            int n = array.size();
            heap.push_back(0);  //The first index of heap array is 1 so we must fill 0 index with dummy content let it be 0
            heap.insert(heap.end(),array.begin(),array.end()); 
            hpsz=n; //Heap size = Heap Array size
            for (int i = n / 2; i > 0; i--) combine(i);
    }

    void insert(int elmnt) {
            heap.push_back(elmnt);
            hpsz++;
            int i = hpsz, parent = i / 2;
            while ((i > 1) && (heap[parent] < heap[i]))
            {
                    iter_swap(heap.begin() + parent, heap.begin() + i);
                    i = parent; parent = i / 2;
            }
    }

    //Get max without deleting from heap
    int peek_max(){
            return heap[1];
    }

    void combine (int i){
            int mp=i,left=2*i,right=(2*i)+1;
            if((left<=hpsz) && (heap[left]>heap[mp])) {
                    mp = left;
            }
            if((right<=hpsz) && (heap[right]>heap[mp])) {
                    mp = right;
            }
            if(mp!=i) {
                    iter_swap(heap.begin() + i, heap.begin() + mp);
                    combine(mp);
            }
    }

    int deletemax(){
            if(isEmpty()) return -1;
            int max = heap[1];

            heap[1] = heap[hpsz--];
            combine(1);
            return max;
    }

    bool isEmpty(){
            return (hpsz==0);
    }

    int getHeapSize(){
            return (hpsz);
    }

};

int main(){
        /*
           Heap can be constructed using vector as input
         */
        int a[] = {3,4,10,8,15,16,17,12,11,20};
        vector<int> heapin (a, a + sizeof(a) / sizeof(a[0]) ); //C++2003
        //std::vector<int> heapin ({3,4,10,8,15,16,17,12,11,20}); //C++2011
        // std::vector<int> heapin(std::begin(a), std::end(a));    //C++2003
        Heap test(heapin);
        /*
           Heap can be constructed using one by one insertion of elements
           <-------------------------------------------------------------->
           Heap test;
           int num_elements;
           printf("Enter number of elements\n");
           scanf("%d\n",&num_elements);
           int elem;

           while(num_elements!=0) {
                  num_elements--;
                  scanf("%dendl",&elem );
                  test.insert(elem);
           }
         */

        //print heap max after each delete
        while (!test.isEmpty()) {
                printf("Max after delete: %d\n", test.deletemax());
        }

}
