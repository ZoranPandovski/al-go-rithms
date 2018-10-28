#include<stdio.h>
#include<stdlib.h>
#define N 3

/* This algorithm performs row operations on the original matrix and the identity matrix so that the original matrix turns into an identity matrix. 
 * It is worth noting that in the traditional Gauss-Jordan elimination method, you are allowed to swap the rows. For simplicity, this algorithm
 * uses these valid row operations to compute the inverse:
 *  Dividing the entire row by a constant
 *  Subtracting a row by another row
 *  Subtracting a row by another row multiplied by a constant
 * The value returned is the result of row operations being done on the identity matrix.
 */

void inverse(double matrix[N][N]) {
 double identity[N][N];
 int i, j;
 
 for(i = 0; i < N; i++) {
  for(j = 0; j < N; j++) {
   if(i == j) {
    identity[i][j] = 1;
   } else {
    identity[i][j] = 0;
   }
  }
 }

 int tempi = 0, tempj = 0;
 double m;
 for(i = 0; i < N; i++) {
  for(j = 0; j < N; j++) {

   m = matrix[i][j];

   if(i==j) {
     while(tempi < N) {
      matrix[i][tempi] /= m;
      identity[i][tempi] /= m;

      tempi++;
     }
     tempi = 0;
     break;

    } else {
     if(m != 0) {
     while(tempj < N) {
      matrix[i][tempj] -= matrix[j][tempj] * m;
      identity[i][tempj] -= identity[j][tempj] * m;

      tempj++;
     }
     tempj = 0;
    }
   }
  }
 }

 tempj = N;
 for(i = N; i--;) {
  for(j = N; j--;) {
   m = matrix[i][j];

   if(i!=j) {
    if(m != 0) {
     while(tempj > 0) {
      tempj--;
      matrix[j][tempj] -= matrix[j][tempj] * m;
      identity[i][tempj] -= identity[j][tempj] * m;
     }
     tempj = N;
    }
   }
  }
 }

 for(i = 0; i < N; i++) {
  for(j = 0; j < N; j++) {
   printf("%lf\t", identity[i][j]);
   if(j == (N-1)) printf("\n");
  }
 }
}

int main(int argc, char ** argv) {
 double matrix[N][N];
 int i, j;

 printf("Enter values in row-major order:\n");
 for(i = 0; i < N; i++) {
  for(j = 0; j < N; j++) {
   scanf("%lf", &matrix[i][j]);
  }
 }
 inverse(matrix);

 return 0;
}
