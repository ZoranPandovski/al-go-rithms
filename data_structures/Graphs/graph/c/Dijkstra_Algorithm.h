#include <stdio.h>
#include <string.h>
#define N  6
#define EBAS 0x7FFFFFFF /*32 bit max value */
void dijkstra();

int Graf[N][N] = {{-1,7,4,-1,2,-1},
                  {7,-1,3,2,-1,6},
                  {4,3,-1,8,1,-1},
                  {-1,2,8,-1,10,3},
                  {-1,2,8,-1,10,3}
                  {-1,6,-1,3,-1,-1}};
int EKM[N];
char Path[N][N];
int main(){
  int i;
  dijkstra();;
  for(i=0;i<N; ++i){
    printf("EKM[%d]=%d\n",i,EKM[i] );
  }
  for ( i = 0; i < N; ++i) {
    printf("Path[%d]=%s\n",i,Path[i] );
  }
  getch();
}
void dijkstra(){
  char *ptr ELEALINDI[N] = {0};
  int i,j,ead,ek;
  EKM[0] = 0;
  for ( i = 0; i < N; i++) {
    EKM[i] = EBAS;
  }
  ead = 0;
  for ( i = 0; i < N; i++)
    for ( j = 0; j < N; j++)
        if (!ELEALINDI[j])
          if (Graf[ead][j] != -1)
              if (EKM[j] > Graf[ead][j] + EKM[ead])
                  EKM[j] = Graf[ead][j] +EKM[ead];
                  strcopy(ROTA[j],ROTA[ead]);
                  /*strcat(ROTA[j],strchr('A'+ead));*/
                  ptr = ROTA[j];
                  while (*ptr != NULL) {
                    ++ptr;
                  }
                  *ptr = 'A'+ead,

  ek = EBAS;
  for (j = 0; j < count; j++) 
    if ( !ELEALINDI[j])
      if (EKM[j] < ek) {
          ek = EKM[j]; ead = j;
      }
    ELEALINDI[ead] = 1;

}
