#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 5
#define MAX_NUM_VERTICES 20

struct vertices_s {
    int visited;
    int deg;
    int adj[MAX_DEGREE]; /* < 0 if incoming edge */
} vertices[] = {
    {0, 3, {2, -3, 4}},
    {0, 2, {-1, 3}},
    {0, 3, {1, -2, 7}},
    {0, 3, {-1, -5, 6}},
    {0, 2, {4, -7}},
    {0, 3, {-4, 7, -8}},
    {0, 4, {-3, 5, -6, -12}},
    {0, 3, {6, -9, 11}},
    {0, 2, {8, -10}},
    {0, 3, {9, -11, -12}},
    {0, 3, {-8, 10, 12}},
    {0, 3, {7, 10, -11}}
};
int num_vertices = sizeof(vertices) / sizeof(vertices[0]);

struct stack_s {
    int top;
    int items[MAX_NUM_VERTICES];
} stack = {-1, {}};

void stack_push(int v) {
    stack.top++;
    if (stack.top < MAX_NUM_VERTICES)
	stack.items[stack.top] = v;
    else {
	printf("Stack is full!\n");
	exit(1);
    }
}

int stack_pop() {
    return stack.top < 0 ? -1 : stack.items[stack.top--];
}

void dfs(int v, int transpose) {
    int i, c, n;
    vertices[v].visited = 1;
    for (i = 0, c = vertices[v].deg; i < c; ++i) {
	n = vertices[v].adj[i] * transpose;
	if (n > 0)
	    /* n - 1 because vertex indexing begins at 0 */
	    if (!vertices[n - 1].visited)
		dfs(n - 1, transpose);
    }
    if (transpose < 0)
	stack_push(v);
    else
	printf("%d ", v + 1);
}

void reset_visited() {
    int i;
    for (i = 0; i < num_vertices; ++i)
	vertices[i].visited = 0;
}

void order_pass() {
    int i;
    for (i = 0; i < num_vertices; ++i)
	if (!vertices[i].visited)
	    dfs(i, -1);
}

void scc_pass() {
    int i = 0, v;
    while((v = stack_pop()) != -1) {
	if (!vertices[v].visited) {
	    printf("scc %d: ", ++i);
	    dfs(v, 1);
	    printf("\n");
	}
    }
}

int main(void) {
    order_pass();
    reset_visited();
    scc_pass();
    return 0;
}
