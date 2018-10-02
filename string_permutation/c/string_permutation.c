/* String permutation in C */

#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{
    *x = *y - *x + (*y = *x);
}

/* Function to print permutations of string */
void permute(char *a, int l, int r)
{
    int i;
    if (l == r) {
        printf("%s\n", a);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); 
        }
    }
}

/* Driver program to test above functions */
int main() {
    int n;
    char str[] = "ABC";
    n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}
