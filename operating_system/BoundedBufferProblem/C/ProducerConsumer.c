#define BUFFER_SIZE 7
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex; 
sem_t full,empty;
int buffer[BUFFER_SIZE];
int counter; 

pthread_t tid;
void *consumer(void *param);
void *producer(void *param); 
void insert_item(int);
int remove_item();

void initialize()
 {
  pthread_mutex_init(&mutex,NULL);
  sem_init(&full,1,0); 
  sem_init(&empty,1,BUFFER_SIZE); 
  counter=0;
 }


void *producer(void *param)
 {
    int item;
    int waittime;
    waittime=rand()% 5;
    sleep(waittime);
    item=rand()%10; 
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    printf("Producer produced %d\n",item);
    
    insert_item(item);
    pthread_mutex_unlock(&mutex); 
    sem_post(&full);
 }    



void *consumer(void *param)
 {
  int item;
  int waittime;
  waittime=rand() % 3;
  sleep(waittime);
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  item=remove_item();
  printf("Consumer Consumed : %d\n",item);
  pthread_mutex_unlock(&mutex);
  sem_post(&empty); 
 }
 

void insert_item(int item)
 {
   buffer[counter++]=item;
 } 


int remove_item()
 {
    return(buffer[--counter]);
 }

int main()
 {
	 int n1;
	 int n2;
	 int i;
	 printf("Enter no. of producers :\n");
         scanf("%d",&n1);
         printf("Enter no. of consumers :\n");
	 scanf("%d",&n2);

	 initialize();

   	 for(i=0;i<n1;i++)
		pthread_create(&tid,NULL,producer,NULL);
   		
         for(i=0;i<n2;i++)
	 	pthread_create(&tid,NULL,consumer,NULL);
 	
	sleep(5);
         exit(0);
 }
