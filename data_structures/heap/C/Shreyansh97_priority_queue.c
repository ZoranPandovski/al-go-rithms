#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct pq {
	void* arr;
	int size_of_element;
	int num_of_elements;
	int head;
}PQ;

/**
	Creates an instance of a priority queue independent of the type of data

	@param num_of_elements The initial capacity of the heap
	@param size_of_element The size in bytes of 1 element in the heap
*/
PQ* initialize(int num_of_elements,int size_of_element) {
	PQ* pq = (PQ*) malloc(sizeof(PQ));
	pq->arr = calloc(num_of_elements+1,size_of_element);
	pq->size_of_element = size_of_element;
	pq->num_of_elements = num_of_elements;
	pq->head = 0;
	return pq;
}

void* get(PQ* pq,int index) {
	int offset = index*(pq->size_of_element);
	return (pq->arr)+offset;
}

void set(PQ* pq,int index,void* value) {
	int offset = index*(pq->size_of_element);
	memcpy((pq->arr)+offset,value,pq->size_of_element);
}

void swap(PQ* pq,int i,int j) {
	int off1 = i*(pq->size_of_element);
	int off2 = j*(pq->size_of_element);
	void* temp = malloc(pq->size_of_element);
	memcpy(temp,(pq->arr)+off1,pq->size_of_element);
	memcpy((pq->arr)+off1,(pq->arr)+off2,pq->size_of_element);
	memcpy((pq->arr)+off2,temp,pq->size_of_element);
	free(temp);
}

PQ* heapify(PQ* pq,int index, int (*comparator)(void*, void*)) {
	int left = index*2;
	int right = index*2+1;
	int min = index;
	int head = pq->head;
	if(left<=head && comparator(get(pq,left),get(pq,min)) < 0)
		min = left;
	if(right<=head && comparator(get(pq,right),get(pq,min)) < 0)
		min = right;
	if(min!=index) {
		swap(pq,min,index);
		heapify(pq,min,comparator);
	}
	return pq;
}

/**
	Adds an element to the priority queue

	@param pq A pointer to the Priority Queue
	@param val_to_push The data that needs to be inserted
	@param comparator A function that compares 2 data items. Works as a min heap by default. 
*/
PQ* push(PQ* pq,void* val_to_push, int (*comparator)(void*, void*)) {
	if(pq->head >= pq->num_of_elements)
		return pq;
	pq->head = pq->head+1;
	set(pq,pq->head,val_to_push);
	int temp=pq->head;
	while(temp>1) {
		int parent = temp/2;
		if(comparator(get(pq,parent),get(pq,temp)) > 0) {
			swap(pq,parent,temp);
			temp = parent;
		}
		else
			break;
	}
	return pq;
}

/**
	Removes the root of the heap

	@param pq A pointer to the priority queue
	@param comparator A function that compares 2 data items. Works as a min heap by default

	@return The data item at the top of the heap. NULL if empty
*/

void* pop(PQ* pq, int (*comparator)(void*, void*)) {
	if(pq->head < 1)
		return NULL;
	void* retval = malloc(pq->size_of_element);
	memcpy(retval, get(pq,1), pq->size_of_element);
	swap(pq,1,pq->head);
	pq->head = pq->head - 1;
	heapify(pq,1,comparator);
	return retval;
}

/**
	A comparator function defined by me
*/
int comp(void* a, void* b) {
	int c = *(int*)a;
	int d = *(int*)b;
	return c-d;
}

/**
Demonstrates the use of these functions using by creating a priority queue of int
*/
int main() {
	PQ* pq = initialize(10,sizeof(int));

	//adding an element
	int a = 10,b = 5;
	push(pq,&a,comp);
	push(pq,&b,comp);

	//getting the root
	void* c = pop(pq,comp);

	return 0;
}