#include <stdio.h>

void shell_sort(int *a, int n)
{
  int i, j, inc, temp;

  for(inc = n/2 ; inc > 0 ; inc /= 2)
  {
    for(i = inc ; i < n ; i++)
    {
      temp = a[i];
      for(j = i ; j >= inc ; j-= inc)
      {
        if(temp < a[j-inc])
          a[j] = a[j-inc];
        else
          break;
      }
      a[j] = temp;
    }
  }
}

int main(void)
{
  int i;
  int a[10] = { 5 , 211 , 66 , 7 , 12 , 2, 76 , 134 , 99 , 9 };

  printf("In: ")
  for(i = 0 ; i < 10 ; i++)
  {
    printf("%d ", a[i]);
  }
  shell_sort(a, 10);
  printf("\nOut: ")
  for(i = 0 ; i < 10 ; i++)
  {
    printf("%d ", a[i]);
  }

  return 0;
}