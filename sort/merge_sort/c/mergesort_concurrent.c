#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/types.h>
#include <unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>

const int SELECTION_SORT_LIMIT = 5;

int * arr;
int * a1;
int * a2;
int sz;
int shm_id;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int l, int r)
{
  int mi,temp;
  for(int i=l; i<=r; i++)
  {
    mi = i;
    for(int j=i+1; j<=r; j++)
      if(arr[mi]>arr[j])
        mi = j;

    swap(&arr[mi], &arr[i]);
  }
}

void merge(int arr[], int l, int m, int r)
{
  int n1 = m-l+1;
  int n2 = r-m;
  int a1[n1];
  int a2[n2];
  int i,j,k;

  for(i=0; i<n1; i++)
    a1[i] = arr[l+i];
  for(j=0; j<n2; j++)
    a2[j] = arr[m+1+j];

  i=0;j=0;k=l;
  while(i<n1 && j<n2)
  {
    if(a1[i] < a2[j])
      arr[k++] = a1[i++];
    else
      arr[k++] = a2[j++];
  }
  while(i<n1)
    arr[k++] = a1[i++];
  while(j<n2)
    arr[k++] = a2[j++];
}

void mergeSort(int arr[], int l, int r)
{
  if(l>=r)return;

  if((r-l)<=SELECTION_SORT_LIMIT)
  {
    selection_sort(arr, l, r);
    return;
  }

  int m = (r-l)/2+l;
  pid_t pid_l, pid_r;

  if((pid_l = fork())==-1)
  {
    perror("fork");
    _exit(EXIT_FAILURE);
  }
  else if(pid_l==0)
  {
    mergeSort(arr, l, m);
    _exit(EXIT_SUCCESS);
  }
  else
  {
    if((pid_r = fork())==-1)
    {
      perror("fork");
      _exit(EXIT_FAILURE);
    }
    else if(pid_r==0)
    {
      mergeSort(arr, m+1, r);
      _exit(EXIT_SUCCESS);
    }
    else
    {
      int status;
      waitpid(pid_l, &status, 0);
      waitpid(pid_r, &status, 0);
      merge(arr, l, m, r);
    }
  }
}

int main()
{
  scanf("%d",&sz);
  a1 = (int*)malloc(sizeof(int)*(sz+5));
  a2 = (int*)malloc(sizeof(int)*(sz+5));
  if((shm_id = shmget(IPC_PRIVATE, (sz+5) * sizeof(int),  IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR)) < 0)
  {
    perror("shmget");
    _exit(EXIT_FAILURE);
  }

  if( !(arr = shmat(shm_id, NULL, 0)) )
  {
      perror("shmat");
      _exit(EXIT_FAILURE);
  }

  for(int i=0; i<sz; i++)
    scanf("%d",&arr[i]);

  mergeSort(arr, 0, sz-1);

  for(int i=0; i<sz; i++)
    printf("%d ",arr[i]);
  printf("\n");

  if (shmdt(arr) == -1)
  {
       perror("shmdt");
       _exit(EXIT_FAILURE);
  }
  if (shmctl(shm_id, IPC_RMID, NULL) == -1)
  {
       perror("shmctl");
       _exit(EXIT_FAILURE);
  }
  return 0;
}
