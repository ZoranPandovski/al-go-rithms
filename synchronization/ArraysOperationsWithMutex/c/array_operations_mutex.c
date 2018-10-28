#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 100
#define COLUMNS 10

/** Global Variables Declarations */


int testMatrix[ROWS][COLUMNS];
pthread_mutex_t lock_mechanism;


void fillMatrix(int targetMatrix[ROWS][COLUMNS], int number){

	if(number == -1){
		srand(time(NULL));
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLUMNS; j++){
				targetMatrix[i][j] = rand();

			}
		}
	}


	else{
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLUMNS; j++){
				targetMatrix[i][j] = number;
			}
		}
	}
}

void printMatrix(int targetMatrix[ROWS][COLUMNS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++){
			printf("%d\t", targetMatrix[i][j]);
		}
	printf("\n");
	}
}


void *lineSummation(void *id){
	int line_total = 0;

	pthread_mutex_lock(&lock_mechanism);
	for(int j = 0; j < ROWS; j++){
		line_total += testMatrix[(int)(size_t)id][j];
	}
	pthread_mutex_unlock(&lock_mechanism);

	printf("Thread[%d] Finished, Line Summation = %d \n", (int)(size_t)id, line_total);

	pthread_exit(NULL);
}

void matrixSummationLines(){
	/** Each thread will be locked in one column, and will summ all rows by
	 *  this thread id. **/
	pthread_t threads_id[COLUMNS];

	fillMatrix(testMatrix, 1);
	pthread_mutex_init(&lock_mechanism, NULL);

	for(int i = 0; i < COLUMNS; i++){
		pthread_create(&threads_id[i], NULL, lineSummation, (void*)(size_t) i);
		pthread_join(threads_id[i], NULL);
	}

	pthread_mutex_destroy(&lock_mechanism);

}

void *columnSummation(void *id){
	int column_total = 0;

	pthread_mutex_lock(&lock_mechanism);
	for(int i = 0; i < COLUMNS; i++){
		column_total += testMatrix[i][(int)(size_t)id];
	}
	pthread_mutex_unlock(&lock_mechanism);

	printf("Thread[%d] Finished, Column Summation = %d \n", (int)(size_t)id, column_total);

	pthread_exit(NULL);
}

void matrixSummationColumns(){
	pthread_t threads_id[ROWS];

	fillMatrix(testMatrix, 1);
	pthread_mutex_init(&lock_mechanism, NULL);

	for(int i = 0; i < ROWS; i++){
		pthread_create(&threads_id[i], NULL, columnSummation, (void*)(size_t) i);
		pthread_join(threads_id[i], NULL);
	}

	pthread_mutex_destroy(&lock_mechanism);

}

int main(int argv, char **argc){

	matrixSummationLines();
	matrixSummationColumns();

	return(EXIT_SUCCESS);
}
