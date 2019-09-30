/* Radix Sort algorithm(with queues)
 * For more information:
 * https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/tutorial/
*/
#include <stdio.h>
#include <stdlib.h>

// define queue node struct
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// get queue end
Node *queueEnd(Node *Q)
{
    while (Q->next != NULL)
        Q = Q->next;
 
    return Q;
}

// pop all elements from a queue and put them in a partially sorted array
void dequeue(Node **Q, int v[], int *cnt)
{
    while (*Q != NULL) {
        Node *tmp = *Q;
 
        v[(*cnt) ++] = (*Q)->val;
        *Q = (*Q)->next;
 
        free(tmp);
    }
 
    *Q = NULL;
}

// push an element in queue
void queuePush(Node **Q, int el)
{
    Node *tmp = malloc(sizeof(Node));
 
    tmp->val = el;
    tmp->next = NULL;
 
    if (*Q == NULL)
        *Q = tmp;
    else
        (queueEnd(*Q))->next = tmp;    
}

// get the maximum value in the array
int getMax(int v[], int n)
{
    int i, max = 0;

    for (i = 0; i < n; ++ i)
        if (max < v[i])
            max = v[i];

    return max;
}
 
void countSort(int v[], int n, int e)
{
    // create a queue for each digit
    Node *Q[10] = {NULL};
    int i;

    // push a number in its corresponding digit queue
    for (i = 0; i < n; ++ i)
        queuePush(&Q[(v[i] / e) % 10], v[i]);
   
    int cnt = 0;

    for (i = 0; i < 10; ++ i)
        dequeue(&Q[i], v, &cnt);
}

void radixSort(int v[], int n)
{
    int M = getMax(v, n);
    int e;
 
    for (e = 1; M / e > 0; e *= 10)
        countSort(v, n, e);
}
 
int main()
{
    int v[] = {5, 37, 79, 128, 913, 715, 189, 854, 685, 12, 0};
    int n = sizeof(v) / sizeof(v[0]);
    int i;

    radixSort(v, n);
 
    for (i = 0; i < n; ++ i)
        printf("%d ", v[i]);
 
    printf("\n");
 
    return 0;
}