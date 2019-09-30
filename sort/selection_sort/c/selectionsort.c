#include <stdio.h>

void change_position(int *positionI, int *positionJ){
	int aux;

	aux = *positionI;
	*positionI = *positionJ;
	*positionJ = aux;
}
	
void selection_sort(int *vector, int Max_size){
	int i, j, position;

	for(i=0;i<(Max_size - 1);i++){
		position = i;
		
		for(j = i+1;j <Max_size;j++){
			
			if(vector[j] < vector[position]){
				position = j;
			}
		}

		if(i != position){
			change_position(&vector[i],&vector[position]);
		}
	}

}
