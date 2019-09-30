/** Program to sort an array using bitonic sort method
**  Note: This program works only when size of input is a power of 2
**
**  Resources references:
**  -https://www.geeksforgeeks.org/bitonic-sort/
**  -http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/bitonic/bitonicen.htm
**  -https://en.wikipedia.org/wiki/Bitonic_sorter
*/


#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N;      // data array size
int *a;     // data array to be sorted

const int ASCENDING = 1;
const int DESCENDING = 0;

void init(void);
void sort(void);
void print(void);
void test(void);
inline void exchange(int, int);
void compare(int, int, int);
void bitonicMerge(int, int, int);
void bitonicSort(int, int, int);


int main(int argc, char **argv)
{

    if (argc != 2)
    {
      printf("Usage: %s q\nwhere N = 2^q is problem size (power of two)\n",argv[0]);
      exit(1);
    }


    N = 1<<atoi(argv[1]);
    a = (int *)malloc(N*sizeof(int));

    init();
    sort();

    test();
    print();
}

/** Function init(): initialize array "a" with data **/
void init()
{
    int i;
    for (i=0; i<N; i++)
    {
        a[i] = rand() % N;  // (N-i)
    }
}

/** INLINE function exchange() : pair swap **/
inline void exchange(int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/** Function compare()
   The parameter dir indicates the sorting direction, ASCENDING
   or DESCENDING; if (a[i] > a[j]) agrees with the direction,
   then a[i] and a[j] are interchanged.
**/
void compare(int i, int j, int dir)
{
    if( dir == (a[i]>a[j]) )    exchange(i,j);
}


/** Function bitonicMerge()
   It recursively sorts a bitonic sequence in ascending order,
   if dir = ASCENDING, and in descending order otherwise.
   The sequence to be sorted starts at index position lo,
   the parameter cnt is the number of elements to be sorted.
 **/
void bitonicMerge(int lo, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        int i;
        for (i=lo; i<lo+k; i++)
            compare(i, i+k, dir);
        bitonicMerge(lo, k, dir);
        bitonicMerge(lo+k, k, dir);
    }
}

/** function bitonicSort()
    first produces a bitonic sequence by recursively sorting
    its two halves in opposite sorting orders, and then
    calls bitonicMerge to make them in the same order
 **/
void bitonicSort(int lo, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;

        // sort in ascending order
        bitonicSort(lo, k, ASCENDING);

        // sort in descending order
        bitonicSort(lo+k, k, DESCENDING);

        // Merge whole sequence in ascending/descending order depending on dir
        bitonicMerge(lo, cnt, dir);
    }
}


/** function sort()
   Caller of bitonicSort for sorting the entire array of length N
   in ASCENDING order
 **/
void sort()
{
    bitonicSort(0, N, ASCENDING);
}

/** Function test() : verify sort results **/
void test()
{
  int pass = 1;
  int i;
  for (i=1; i<N; i++)
  {
    pass &= (a[i-1] <= a[i]);
  }

  printf("Test %s\n",(pass) ? "PASSED" : "FAILED");

}

/** Function print() : print array elements **/
void print()
{
  int i;
  for (i=0; i<N; i++)
  {
    printf("%d\n", a[i]);
  }
  printf("\n");
}
