/*
*   This is are the implementation of 3 File organization stratagies such as
*   Single level organization, two level organization, and Hierarichal file organization

*   This File is for the menu for the 3 types of stratagies/
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "single.c"
#include "double.c"
#include "hierach.c"

void main() {
  system("clear");
  printf("File organization stratagies\n" );
  printf(" 1. Single Level \n");
  printf(" 2. Two Level \n");
  printf(" 3. Hierarichal\n");
  printf(" 0. Exit\n");
  printf("\t Choose :");
  int opt;
  scanf("%d", &opt);
  system("clear");

  switch (opt) {
    case 1: single();break;
    case 2: two();break;
    case 3: hierarichal();break;
    case 0: exit(0);
    default: printf("Invalid option!! TRY AGAIN\n" );main();break;

  }

}
