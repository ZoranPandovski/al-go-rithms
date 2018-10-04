#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
using namespace std;

void oddEvenSort(int a[],int n){
	int phase,i,temp;
    int thread_count = 4;
#   pragma omp parallel num_threads(thread_count) default(none) shared(a,n) private(i,temp,phase)
	for( phase=0 ; phase<n ; phase++){
		if(phase%2 == 0){
#           pragma omp for
			for(i=1;i<n;i+=2){
				if(a[i-1]>a[i]){
					temp = a[i];
					a[i] = a[i-1];
					a[i-1]=temp;
				}
			}
		}
		else{
#           pragma omp for
			for( i=1 ; i<n-1 ; i+=2){
				if(a[i]>a[i+1]){
					temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		}
	}

}


void oddEvenSort1(int a[],int n){
	int phase,i,temp;
    int thread_count = 4;
	for( phase=0 ; phase<n ; phase++){
		if(phase%2 == 0){
#   		pragma omp parallel for num_threads(thread_count) default(none) shared(a,n) private(i,temp)
			for(i=1;i<n;i+=2){
				if(a[i-1]>a[i]){
					temp = a[i];
					a[i] = a[i-1];
					a[i-1]=temp;
				}
			}
		}
		else{
#   		pragma omp parallel for num_threads(thread_count) default(none) shared(a,n) private(i,temp)
			for( i=1 ; i<n-1 ; i+=2){
				if(a[i]>a[i+1]){
					temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		}
	}

}


int main(){
	int size = 20000;
	int lista[size];
	for(int i =0; i < size ; i++){
		srand(time(NULL));
		lista[i] = rand()%10000;
	}

	double start = omp_get_wtime();
	oddEvenSort(lista,size);
	printf("Time: \t %f \n", omp_get_wtime()-start);

	start = omp_get_wtime();
	oddEvenSort1(lista,size);
	printf("Time: \t %f \n", omp_get_wtime()-start);
	return 0;
}
