#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <string.h>

typedef struct _llnode{
	void* data;
	struct _llnode *next;
}LLNODE;

typedef struct {
	int (*cmp)(void*,void*); // a comparator that checks whether 2 elements are equal
	int el_size;
	LLNODE* first;
}LL;

LL* initialize_ll(int size,int (*cmp)(void*,void*)) {
	LL* ll = malloc(sizeof(LL));
	ll->first = NULL;
	ll->el_size = size;
	ll->cmp = cmp;
	return ll;
}

int find_in_ll(LL* head,void* data) {
	LLNODE* tmp = head->first;
	while(tmp) {
		if(head->cmp(tmp->data, data))
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void add_to_ll(LL* head,void* data) {
	if(find_in_ll(head,data))
		return;
	LLNODE* lln = malloc(sizeof(LLNODE));
	lln->data = malloc(sizeof(head->el_size));
	memcpy(lln->data,data,head->el_size);
	lln->next = head->first;
	head->first = lln;
}

void remove_from_ll(LL* head, void* data) {
	if(head->first && head->cmp(head->first->data,data)) {
		LLNODE* torm = head->first;
		head->first = torm->next;
		free(torm);
		return;
	}
	LLNODE* prev = head->first;
	LLNODE* curr = head->first->next;
	while(curr) {
		if(head->cmp(curr->data,data)) {
			prev->next = curr->next;
			free(curr->data);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

#endif