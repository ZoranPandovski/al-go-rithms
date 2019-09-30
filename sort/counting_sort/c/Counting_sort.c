/*
*   ░█▀▀░█▀█░█░█░█▀█░▀█▀░▀█▀░█▀█░█▀▀░░░█▀▀░█▀█░█▀▄░▀█▀
*   ░█░░░█░█░█░█░█░█░░█░░░█░░█░█░█░█░░░▀▀█░█░█░█▀▄░░█░
*   ░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀▀▀░░░▀▀▀░▀▀▀░▀░▀░░▀░
*
*   Counting sort alogorithm using arrays in C.
*   Integer sorting. Max value of input array should be small enough so as not to cause memory issues.
*   More info: https://en.wikipedia.org/wiki/Counting_sort
*
*/

#include <stdio.h>

int find_max(int a[],int length){

   int max = a[0];

   for (int i = 1; i < length; i++) {
     if (a[i]>max) {
       max = a[i];
     }
   }

  return max;
}

int main(int argc, char const *argv[]) {

  //Input not sorted array
  int nosrt[] = {4,3,10,8,15,16,17,1,12,11,20};

  int nosrt_length = sizeof(nosrt)/sizeof(nosrt[0]);
  int max_in = find_max(nosrt,nosrt_length);

  int aux[max_in];
  int result[nosrt_length+1];

  //Initialize result array
  for (int i = 0; i < nosrt_length+1; i++) {
    result[i] = 0;
  }

  //Initialize auxilary array
  for (int i = 0; i < max_in + 1; i++) {
    aux[i] = 0;
  }

  //Count appearance frequency of input array and store it in aux array
  //Aux[j] contains the number of elements = j
  for (int j = 0; j < nosrt_length; j++) {
    aux[nosrt[j]]++;
  }

  //Calculate running sum. Aux[k] contains the number of elements <= k
  for (int k = 1; k <= max_in; k++) {
    aux[k] += aux[k-1];
  }

  //Sort elements retaining their appearance order (Stable sorting algorithm)
  for (int y = nosrt_length-1; y >=0 ; y--) {
    result[ aux[nosrt[y]] ] = nosrt[y];
    aux[nosrt[y]]--;
  }

  //Print results
  for (int w = 1; w <= nosrt_length; w++) {
    printf("%d\n",result[w] );
  }

  return 0;
}
