#ifndef _buddy_Lib_File_H_
#include <math.h>

#define _buddy_Lib_File_H_

int InitMyMalloc(int size);

void* myMAlloc(int size);

int MyFree(void* ptr);


void DumpFreeList();

#endif