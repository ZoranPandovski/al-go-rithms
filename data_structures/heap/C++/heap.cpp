#include<bits/stdc++.h>
using namespace std;
int heap[100000];
int sz;

int parent(int pos){
    return pos/2;
}
int left(int pos){
    return 2*pos;
}
int right(int pos){
    return 2*pos + 1;;
}

void heapify(int pos){
    if(heap[parent(pos)]<heap[pos] && pos>0 &&parent(pos) >0){
            return;
        }
    else if(pos>0 && parent(pos)>0){
            swap(heap[parent(pos)],heap[pos]);
            heapify(parent(pos));
        }
    return;
}

void insert(int data,int size){
    heap[size]=data;
    heapify(size);
}


int main(){
    sz=0;
    int num_elements;
    cout<<"Enter number of elements"<<endl;
    cin>>num_elements;
    while(num_elements--){
        int elem;
        cin>>elem;
        sz++;
        insert(elem,sz);
        cout<<heap[1];
    }
}

