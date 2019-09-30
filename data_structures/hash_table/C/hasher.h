#ifndef OPEN_HASH
#define OPEN_HASH

#include <stdlib.h>
#include "linked_list.h"

typedef struct {
	LL** hash_table;
	int el_len;
	int numel;
	int (*eq_cmp)(void*,void*);
	int (*hash)(void*);
}OPEN_HASHER;

/**
Creates an instance of a hash table

@param el_len The size of the type of element to be used with the hasher in bytes
@param numel Initial size of the hash table (Approximate number of elements)
@param eq_cmp A function pointer that checks if 2 elements are equal
@param hash A function pointer that finds the hash value of an element

@returns an instance of a hasher
*/
OPEN_HASHER* initialize_hasher(int el_len, int numel, int (*eq_cmp)(void*, void*), int (*hash)(void*)) {
	OPEN_HASHER* hasher = malloc(sizeof(OPEN_HASHER));
	hasher->el_len = el_len;
	hasher->numel = numel;
	hasher->eq_cmp = eq_cmp;
	hasher->hash = hash;
	hasher->hash_table = malloc(sizeof(LL*) * numel);
	for(int i=0;i<numel;i++)
		hasher->hash_table[i] = initialize_ll(el_len,eq_cmp);
	return hasher;
}

int getidx(OPEN_HASHER* oh, void* data) {
	int pos = oh->hash(data);
	pos %= oh->numel;
	return pos;
}


/**
Adds an element to the hash table

@param oh Pointer to an instance of a hash table
@param data Pointer to the data to be inserted
*/
void add_hasher(OPEN_HASHER* oh, void* data) {
	int i = getidx(oh,data);
	add_to_ll(oh->hash_table[i],data);
}

/**
Checks if an element is present in the hash table

@param oh Pointer to an instance of a hash table
@param data Pointer to the data to be searched

@returns 1 if found 0 otherwise
*/
int find_hasher(OPEN_HASHER* oh, void* data) {
	int i = getidx(oh, data);
	return find_in_ll(oh->hash_table[i],data);
}
/**
Removes an element from the hash table

@param oh Pointer to an instance of a hash table
@param data Pointer to the data to be removed
*/
void remove_hasher(OPEN_HASHER* oh, void* data) {
	int i = getidx(oh,data);
	remove_from_ll(oh->hash_table[i],data);
}

#endif