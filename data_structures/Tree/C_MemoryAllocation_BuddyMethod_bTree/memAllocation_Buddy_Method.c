#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include "buddy_Lib_File.h"


typedef struct buddyNode {
	int usedSize;
	int unUsedSize;
	int index;
	struct buddyNode *tree;
	struct buddyNode *next;
} buddyNode;


buddyNode *root;
buddyNode *scanner;
int numNodesFreeList=0;
int memAvailable=0;

struct buddyNode realBoadyTree[4096];

int InitMyMalloc(int size){

	static int initialized=0;

	
	if(initialized == 1) {
		return -1;
	}	
	if(size <= 0) {
		return -1;
	}


	int sizeOfPage= getpagesize();//pageSize
    
    int temp = size % sizeOfPage;
    if(temp != 0){
    	size =  size + sizeOfPage - temp;
	}
	
	int fd = open("/dev/zero", O_RDWR);
	

	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (ptr == MAP_FAILED) { 
		exit(1); 
	}

	root = (buddyNode *) ptr;
	root->index = 0;
	root->unUsedSize = size;
	root->usedSize = 0;
	//head->next = head; //FIXME
	//numNodesFreeList++;
	//memAvailable = head->size;
	
	close(fd);

	// Set this bit only if Mem_Init called correctly
	//	fprintf(stdout,"Header size = %lu\n",sizeof(header_t)); // FIXME remove

	

	printf("Size : %d !!\n" , size );


	int i = 0 ;
	int dept = 0;
	int tempSize = size;

	int counter = 1;
	int exp_counter = 0;
		//printf("Buraya gelebildi4\n");

	//tree for buddies
	root = (struct buddyNode*) malloc(sizeof(struct buddyNode) * size);
	
	for (; i <= size-1 ; i++){
		//printf("Burada ne sorun var acaba\n");	
		realBoadyTree[i].usedSize = 0;
		realBoadyTree[i].unUsedSize = tempSize;
		//printf("Burada ne sorun var acaba2\n");
		if (pow(2,exp_counter) == counter){
			tempSize = tempSize/2;
			exp_counter++;
			counter = 0;
		}
		counter++;
	}


	i = 0;

	for (; i <= size-1 ; i++){
		
		 
			printf("%i . index :  , %d unUsedSize \n", i,  realBoadyTree[i].unUsedSize );
		
	}
	printf("1. left : %d \n", realBoadyTree[1].unUsedSize );

	printf("2. left : %d \n", realBoadyTree[3].unUsedSize );
	
	printf("3. left : %d \n", realBoadyTree[7].unUsedSize );
	
	printf("4. left : %d \n", realBoadyTree[15].unUsedSize );
		
	printf("5. left : %d \n", realBoadyTree[31].unUsedSize );
	
	printf("6. left : %d \n", realBoadyTree[63].unUsedSize );
	
	printf("7. left : %d \n", realBoadyTree[127].unUsedSize );

	printf("8. left : %d \n", realBoadyTree[255].unUsedSize );

	printf("9. left : %d \n", realBoadyTree[511].unUsedSize );

	printf("10. left : %d \n", realBoadyTree[1023].unUsedSize );
	
	printf("11. left : %d \n", realBoadyTree[2047].unUsedSize );
	
	printf("12. left : %d \n", realBoadyTree[4095].unUsedSize );
		

	root = realBoadyTree;
	initialized=1;
	return 0;
}

int powerOfTwo(int number){
	int i = 1 ;
	for ( ; i <= 32 ; i++){
		if (pow(2 , i) == number){
			return 0;
		}else if (pow(2 , i) > number){
			return pow(2 , i) - number;
		}
	}
}


void *myMAlloc(int size) {

	int i = 0;
	printf("Allocating...\n");

	printf("Paramater  : %d \n", size );
	while (1 == 1){
		printf("Tree size : %d and index : %d \n" , realBoadyTree[i].unUsedSize + realBoadyTree[i].usedSize , i );
		if (realBoadyTree[i].unUsedSize+realBoadyTree[i].usedSize > size){
			;
		}else{
			i = (i-1)/2;
			printf("Given %d size for %d \n" , realBoadyTree[i].unUsedSize + realBoadyTree[i].usedSize  , size  );
			break;
		}
		i = i*2 + 1;

	}
	printf("The current value of i :  %d \n" , i);

	int findedSegment ;
	int j = i;
	int haveSpace = 0;
	for ( ; j <= j*2 ; j++  ){//finding optimal segment
		if (realBoadyTree[j].unUsedSize >= size){
			findedSegment = j;
			haveSpace = 1;
			break;
		}
	}

	if (haveSpace == 0){
		return NULL;//There is no place
	}else{
		realBoadyTree[findedSegment].usedSize = size;
		realBoadyTree[findedSegment].unUsedSize = realBoadyTree[i].unUsedSize - size;
		buddyNode *ptr = (void *)realBoadyTree;
		ptr->usedSize = realBoadyTree[findedSegment].usedSize;
		ptr->index = findedSegment;
		realBoadyTree[0].unUsedSize = 
		printf("%p\n", (void *)ptr);
		return (void*) ptr;
	}	
}


int MyFree(void* ptr) {

	printf("Free...\n");
	if(ptr == NULL) { // Do nothing
		return 0;
	}

	struct buddyNode *node2 = (struct buddyNode *)ptr; 
	int temp = realBoadyTree[node2->index].usedSize;
	realBoadyTree[node2->index].usedSize = 0;
	realBoadyTree[node2->index].unUsedSize = realBoadyTree[node2->index].unUsedSize + temp ;




	buddyNode *block = ((buddyNode *)ptr - 1);
	

	struct buddyNode *node = root;
	if ((struct buddyNode *)root > (struct buddyNode *)block) {
		buddyNode *new = (void *) block;
		new->next = root;
		new->unUsedSize = block->usedSize ;
	}
	else {
		buddyNode *new = (void *) block;
		new->unUsedSize = block->unUsedSize;
	}
	return 0;
}





void DumpFreeList(){//fonksiyon tamamen bos olanlari gostermeden sadece kısmen boş olanları gosterir.
	int i = 0;
	for (; i < sizeof(realBoadyTree) / sizeof(buddyNode) ; i++){
			if (realBoadyTree[i].usedSize != 0 && i != 0)
				printf("%i . index :  , %d unUsedSize \n", i,  realBoadyTree[i].unUsedSize );
	}
	printf("***********************************************************************\n");
}


int main(int argc, char *argv[]) {
	printf("Init... Result :%d\n",InitMyMalloc(4096));
	
	void *ptr[10];
	ptr[0] = myMAlloc(450);
	printf("return from myMalloc %p\n", ptr);
	DumpFreeList();
	
	ptr[1] = myMAlloc(70);
	printf("Iteration %d:: Mem_Alloc called, return value:%p\n",1, ptr);
	DumpFreeList();
	

	MyFree(ptr[1]);
	
	DumpFreeList();
	
	return 0;
}