#include <stdlib.h>

void shellSort(int* array, int size){

	for(int h = size; h > 0; h = h/3 - 1){

		for(int i = h; i < size; i++){
			int aux = array[i];
			int j;
			for(j = i; j >= h && array[j-h] > aux; j-= h){
				array[j] = array[j-h];
			}
				array[j] = aux;
		}
	}
}
