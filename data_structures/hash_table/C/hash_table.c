/**
Demonstrates how to use the hash table defined in hasher.h
By creating a hash table of integers.
*/

#include <stdio.h>
#include "hasher.h"

int hash(void* data) {
	int a = *(int*)data;
	return a % 100007;
}

int eq_cmp(void* data1, void* data2) {
	if(hash(data1) == hash(data2)) {
		int a = *(int*)data1;
		int b = *(int*)data2;
		return a==b;
	}
	return 0;
}

int main() {
	// Instantiating a hasher
	OPEN_HASHER *oh = initialize_hasher(sizeof(int),10,eq_cmp,hash);

	//adding elements
	int a = 10;
	add_hasher(oh,&a);
	a = 15;
	add_hasher(oh,&a);

	//deleting elements
	remove_hasher(oh,&a);

	//finding elements
	a = 10;
	if(find_hasher(oh,&a))
		printf("Found\n");
	else
		printf("Not Found\n");
}