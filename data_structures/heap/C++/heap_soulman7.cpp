#include <bits/stdc++.h>
using namespace std;

struct heap{
	int* arr;
	int size;
	int capacity;
	
	heap(int cap){
		capacity =cap;
		size =0;
		arr =new int[cap];
	}
	
	int parent(int i){
		return (i-1)/2;
	}
	
	int right(int i){
		return 2*i+2;
	}
	
	int left(int i){
		return 2*i+1;
	}
	
	void heapify(int i){
		int lar =i;
		int r =right(i);
		int l =left(i);
		
		if(l<size && arr[lar] <arr[l]){
			lar =l;
		}
		if(r<size && arr[lar] <arr[r]){
			lar =r;
		}
		
		if(lar!=i){
			swap(arr[i],arr[lar]);
			heapify(lar);
		}
	}
	
	void push(int key){
		if(size==capacity){
			cout<<"cant insert\n";
		}
		size++;
		int i =size-1;
		arr[i] =key;
		
		while(i>=0 && arr[i]>arr[parent(i)]){
			swap(arr[i],arr[parent(i)]);
			i =parent(i);
		}
	}
	
	void pop(){
		if(size==0){
			cout<<"no element left\n";
		}
		swap(arr[0],arr[size-1]);
		size--;
		heapify(0);
	}
	
	int top(){
		return arr[0];
	}
};

int main() {
	// your code goes here
	
	heap* h =new heap(10);
	for(int i=5;i>=0;i--){
		h->push(i);
	}
	
	for(int i=0;i<6;i++){
		cout<<h->top()<<"\n";
		h->pop();
	}
	return 0;
}