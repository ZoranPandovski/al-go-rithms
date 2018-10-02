#include <stdio.h>
#define N 4

void multVetorMatriz (int v[N], int A[N][N], int w[N]) {
	int i, j, soma;
	
	for(i = 0; i < N; i++) {
		soma = 0;
		
		for(j = 0; j < N; j++) {
			soma += A[i][j];
		}
		w[i] = soma * v[i];
	}
	
	for(i = 0; i < N; i++)
		printf("w%d: %d\n", i + 1, w[i]);
} 

int main() {
	int i, j, A[N][N], v[N], w[N];
	
	for(i = 0; i < N; i++)
		scanf("%d", &v[i]);
	
	for(i = 0; i < N;i++)
		for(j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	
	multVetorMatriz(v, A, w);	
		
	return 0;
}
