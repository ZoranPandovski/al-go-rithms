#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int ITERS;

int *buffer;
int size, filled;
pthread_mutex_t mutex;
pthread_cond_t prod, cons;
int producers_left, consumers_left; 

void* Producer(void* tNo) {
	int t = (int)(*((int *)tNo));
	for(int i=0;i<ITERS; i++) {
		pthread_mutex_lock(&mutex);
		
		while(filled == size) {
			if(consumers_left == 0) {
				printf("All consumers left.\n");
				producers_left--;
				pthread_mutex_unlock(&mutex);
				return 0;
			}
			pthread_cond_wait(&cons, &mutex);
		}
		buffer[filled] = rand();
		printf("Producer %d filled position %d with %d.\n", t, filled, buffer[filled]);
		filled++;
		producers_left--;
		pthread_cond_broadcast(&prod);
		pthread_mutex_unlock(&mutex);
	}
}

void* Consumer(void* tNo) {
	int t = (int)(*((int *)tNo));
	for(int i=0;i<ITERS; i++) {
		pthread_mutex_lock(&mutex);

		while(filled == 0) {
			if(producers_left == 0) {
				printf("All producers left.\n");
				consumers_left--;
				pthread_mutex_unlock(&mutex);
				return 0;
			}
			pthread_cond_wait(&prod, &mutex);
		}
		printf("Consumer %d consumed position %d with %d.\n", t, filled-1, buffer[filled-1]);
		filled--;
		consumers_left--;
		pthread_cond_broadcast(&cons);
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int pN, cN;
	scanf("%d %d %d %d", &pN, &cN, &size, &ITERS);
	int maxN = pN>cN?pN:cN;
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&prod, NULL);
	pthread_cond_init(&cons, NULL);

	producers_left = pN*ITERS;
	consumers_left = cN*ITERS;
	
	pthread_t *producer = (pthread_t *)malloc(pN * sizeof(pthread_t));
	pthread_t *consumer = (pthread_t *)malloc(cN * sizeof(pthread_t));
	int *threadNo = (int *)malloc(maxN * sizeof(int));
	for(int i=0;i<maxN; i++)
		threadNo[i] = i;

	buffer = (int *)malloc(size * sizeof(int));
	filled = 0;

	for(int i=0;i<pN;i++) {
		pthread_create(&producer[i], NULL, Producer, (void *)(threadNo + i));
	}

	for(int i=0;i<cN;i++) {
		pthread_create(&consumer[i], NULL, Consumer, (void *)(threadNo + i));
	}


	for(int i=0;i<cN;i++) {
		pthread_join(consumer[i], NULL);
	}


	for(int i=0;i<pN;i++) {
		pthread_join(producer[i], NULL);
	}


	free(buffer);
	free(threadNo);
	free(producer);
	free(consumer);
	return 0;
}