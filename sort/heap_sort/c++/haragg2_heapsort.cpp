#include <iostream>

using namespace std;

// Class that implemnts a heap data structure
// Member variable: an array, array size, index of last valid entry of heap 
// Public member functoins: add, remove
// Private member functoins:heapifyup, heapifydown, swap, print
class Heap{
    private:
        int size;
        int lastposition;
        int *arr;

    public:
        Heap(int s):size(s),lastposition(-1){arr=new int[size];}
        Heap(int *a, int s):arr(a),lastposition(s-1){
            for(int i=0; i<s; i++){
                heapifyup(i);
                }
            return;
        }
        
        void add(int x){
            arr[++lastposition]=x;
            heapifyup(lastposition);
            return;
            }
            
        int remove(){
            int tmp=arr[0];
            swap(0,lastposition--);
            heapifydown(0);
            return tmp;
            }
            
    private:
        void heapifyup(int position){
            if (position==0)return;
            int parent=(position-1)/2;
            if (arr[position]>arr[parent]){
                swap(position,parent);
                heapifyup(parent);
                }
            return;
        }
        
        void heapifydown(int position){
            int left=2*position+1;
            int right=2*position+2;
            if (left>lastposition && right>lastposition)return;
            if (left==lastposition){
                if(arr[left]>arr[position])swap(left,position);
                return;
            }
            if (arr[left]>arr[right]){
                if (arr[left]>arr[position]){
                    swap(left,position);
                    heapifydown(left);}
                    }
            else {
                if (arr[right]>arr[position]){
                    swap(right,position);
                    heapifydown(right);}
                }
            return;
        }
        
        void swap(int i, int j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            return;
            }
            
        void print(int *a){
            for (int j=0;j<11;j++){
            cout<<a[j]<<" ";}
            cout<<endl;
            }
    
    };

//Function prototype
void HeapSort(int* arr, int size);    
    
int main(){
    int size;
    cout<<"Enter the array size"<<endl;
    cin>>size;
    int *array=new int[size];
    cout<<"Enter the elements of array"<<endl;
    for (int i=0;i<size;i++){
        cin>>array[i];
    }
    HeapSort(array,size);
    for (int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// Subroutine to sort the array by using heap sort
// Inputs: A pointer to array, array size
// Outputs: None
void HeapSort(int* arr, int size){
    Heap h(arr,size);
    for(int i=0;i<size;i++){
        h.remove();
        }
}
