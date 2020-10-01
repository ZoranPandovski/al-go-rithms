#include <stdio.h>
#include <stdlib.h>

struct Node {
	int element;
	struct Node *next;
};

// Sentinel contains all functions to make a simple List, Queue or Stack
struct Sentinel {
	struct Node *head;
	struct Node *tail;
	int length;

	void (*insert)(struct Sentinel *self, struct Node *t, struct Node *x);
	int (*del)(struct Sentinel *self, struct Node *x);
	struct Node *(*search)(struct Sentinel *self, int pos);

	void (*push)(struct Sentinel *self, struct Node *t);
	int (*pop)(struct Sentinel *self);

	void (*enqueue)(struct Sentinel *self, struct Node *t);
	int (*dequeue)(struct Sentinel *self);
};

// Functions to create the structs and check for errors in malloc
struct Sentinel *init();
void *ec_malloc(unsigned int);
void free_struct(struct Sentinel *sentinel);
struct Node *new_node(int element);

void insert(struct Sentinel *self, struct Node *t, struct Node *x);
int del(struct Sentinel *self, struct Node *x);
struct Node *search(struct Sentinel *self, int pos);

void push(struct Sentinel *self, struct Node *t);
int pop(struct Sentinel *self);

void enqueue(struct Sentinel *self, struct Node *t);
int dequeue(struct Sentinel *self);

// BFS Related Code
void bfs(struct Sentinel **graph, int start);
int visited[100];

int main()
{
    // Create a dynamic array of lists with 100 elements
    struct Sentinel **graph = (struct Sentinel **) ec_malloc(sizeof(struct Sentinel *) * 100);

    // Initialize each list with 100 elements
    for (int i = 0; i < 100; i++)
        graph[i] = init();

    // Read the amount of edges
    int edges;
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        // Insert nodes in graph 
        graph[u]->insert(graph[u], new_node(v), graph[u]->tail);
    }
    int start;
    scanf("%d", &start);

    bfs(graph, start);

    for (int i = 0; i < 100; i++)
        free_struct(graph[i]);
	return 0;
}

void bfs(struct Sentinel **graph, int start)
{
    // Create queue and push start value
	struct Sentinel *queue = init();
    queue->push(queue, new_node(start));
    visited[start] = 1;

    // While queue is not empty, read the current node in queue and check its neighbors for unvisited nodes
    while (queue->length != 0) {
        int current = queue->pop(queue);
        printf("%d\n", current);
        for (int i = 0; i < graph[current]->length; i++) {
            struct Node *curNode = graph[current]->search(graph[current], i);
            if (curNode == NULL) continue;
            int cur = curNode->element;
            if (visited[cur] == 0) {
                queue->push(queue, new_node(cur));
                visited[cur] = 1;
            }
        }
    }

	free_struct(queue);
}

void *ec_malloc(unsigned int size)
{
	void *ptr = malloc(size);
	if (ptr == NULL) 
		exit(-1);
	return ptr;
}

void free_struct(struct Sentinel *sentinel)
{
	free(sentinel->head);
	free(sentinel->tail);
	free(sentinel);
}

struct Sentinel *init()
{
	struct Sentinel *t = (struct Sentinel *) ec_malloc(sizeof(struct Sentinel));
	t->head = (struct Node *) ec_malloc(sizeof(struct Node));
	t->tail = (struct Node *) ec_malloc(sizeof(struct Node));
	t->head->next = t->tail->next = NULL;
	t->length = 0;

    // Bind function pointers in struct to actual functions
	t->insert = insert;
	t->del = del;
	t->search = search;
	t->push = push;
	t->pop = pop;
	t->enqueue = enqueue;
	t->dequeue = dequeue;

	return t;
}

struct Node *new_node(int element)
{
	struct Node *t = (struct Node *) ec_malloc(sizeof(struct Node));
	t->element = element;
	t->next = NULL;

	return t;
}

void insert(struct Sentinel *self, struct Node *t, struct Node *x)
{
	if (self->head->next == NULL)
		self->head->next = self->tail->next = t;
	else if (x == self->tail) {
		self->tail->next->next = t;
		self->tail->next = t;
	} else {
		t->next = x->next;
		x->next = t;
	}

	self->length++;
}

int del(struct Sentinel *self, struct Node *x)
{
	struct Node *t;
	if (self->head->next == NULL || x->next == NULL)
		return 0;
	else {
		t = x->next;
		if (t->next == NULL) {
			self->tail->next = x;
			x->next = NULL;
		} else {
			x->next = t->next;
		}
		self->length--;
	}
	int value = t->element;
	free(t);
	return value;
}

struct Node *search(struct Sentinel *self, int pos)
{
	int i = 0;
	struct Node *cur = self->head->next;
	if (cur == NULL)
		return NULL;
	while (i != pos && cur->next != NULL) {
		cur = cur->next;
		i++;
	}
	if (i == pos)
		return cur;
	else
		return NULL;
}

void push(struct Sentinel *self, struct Node *t)
{
	self->insert(self, t, self->head);
}

int pop(struct Sentinel *self)
{
	return self->del(self, self->head);
}

void enqueue(struct Sentinel *self, struct Node *t)
{
	self->insert(self, t, self->tail);
}

int dequeue(struct Sentinel *self)
{
	return self->del(self, self->head);
}
