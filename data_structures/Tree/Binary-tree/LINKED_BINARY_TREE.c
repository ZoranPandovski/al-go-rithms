#include <stdio.h>
#include <stdlib.h>

// 	LINKED_BINARY_TREE

typedef struct node{
	int inf;
	struct node *left, *right, *father;
}NODE;

typedef NODE * LINKED_BINARY_TREE;

void maketree(LINKED_BINARY_TREE *, int);
void setleft (LINKED_BINARY_TREE, int);
void setright (LINKED_BINARY_TREE, int);
LINKED_BINARY_TREE left (LINKED_BINARY_TREE);
LINKED_BINARY_TREE right (LINKED_BINARY_TREE);
LINKED_BINARY_TREE father (LINKED_BINARY_TREE);
LINKED_BINARY_TREE brother (LINKED_BINARY_TREE);
int informationofanodeofthetree (LINKED_BINARY_TREE);
int isLeft(LINKED_BINARY_TREE);
int isRight(LINKED_BINARY_TREE);

void maketree(LINKED_BINARY_TREE *t, int inf){
	*t = (LINKED_BINARY_TREE)malloc(sizeof(NODE));
	if(!(*t)){
		puts("Memory Full\n");
		exit(1);
	}
	(*t)->inf = inf;
	(*t)->left = (*t)->right = (*t)->father = NULL;
}

void setleft(LINKED_BINARY_TREE t, int inf){
	t->left = (LINKED_BINARY_TREE)malloc(sizeof(NODE));
	if(!t){
		puts("Memory Full\n");
		exit(2);
	}
	(t)->inf = inf;
	(t)->left = (t)->right = NULL;
	(t)->father = t;
}

void setright(LINKED_BINARY_TREE t, int inf){
	t->right = (LINKED_BINARY_TREE)malloc(sizeof(NODE));
	if(!t){
		puts("Memory Full\n");
		exit(2);
	}
	(t)->inf = inf;
	(t)->left = (t)->right = NULL;
	(t)->father = t;
}

int informationofanodeofthetree (LINKED_BINARY_TREE t){
	return t->inf;
}

LINKED_BINARY_TREE left (LINKED_BINARY_TREE t){
	return t->left;
}

LINKED_BINARY_TREE right (LINKED_BINARY_TREE t){
	return t->right;
}

LINKED_BINARY_TREE father (LINKED_BINARY_TREE t){
	return t->father;
}

LINKED_BINARY_TREE brother (LINKED_BINARY_TREE t){
	if(father(t))
		if(isLeft(t))
			return right(father(t));
		else return left(father(t));
	return NULL;
}

int isLeft(LINKED_BINARY_TREE t){
	if(!(father(t)))
		return 0;
	if(left(father(t)) == t)
		return 1;
	return 0;
}

int isRight(LINKED_BINARY_TREE t){
	if(!(father(t)))
		return 0;
	if(!(left(father(t)) == t))
		return 1;
	return 0;
}

// BINARY_SEARCH_TREE - basically equal to the LINKED_BINARY_TREE, the difference is how to elements are inserted and the Depth_First_Search and Breadth_First_Search 
// Consider the TAD e the fuctions of LINKED_BINARY_TREE for BINARY_SEARCH_TREE.
/*
void Breadth_First_Search (LINKED_BINARY_TREE t){
	LINKED_QUEUE q;
	make_queue(&q);
	
		if(t)
			insert_QUEUE(q, t);
	
	while(!(isEmpty(q))){
	p
	printf("Quering in the queue: %d\n", query(q));
		if(left(query(q)))
			insert_QUEUE(q,left(query(q)));	
		if(right(query(q)))
			insert_QUEUE(q,right(query(q)));
	
	removeQUEUE(q);	
	}		
}
*/
// The Depth_First_Search has three modes to search on a tree: VLR, LVR, LRV.
// VLR is on Preorder 
// LVR is Inorder 
// LRV is in Posorder

void Depth_First_Search_VLR (LINKED_BINARY_TREE t){ //PreOrder
	printf("%d", informationofanodeofthetree(t));
	Depth_First_Search_VLR(left(t));
	Depth_First_Search_VLR(right(t));
}

void Depth_First_Search_LVR (LINKED_BINARY_TREE t){ // InOrder
	Depth_First_Search_VLR(left(t));
	printf("%d", informationofanodeofthetree(t));
	Depth_First_Search_VLR(right(t));
}

void Depth_First_Search_LRV (LINKED_BINARY_TREE t){ // PostOrder
	Depth_First_Search_VLR(left(t));
	Depth_First_Search_VLR(right(t));
	printf("%d", informationofanodeofthetree(t));
}

void InsertingBINARY_SEARCH_TREE (LINKED_BINARY_TREE *t, int inf){
	
	if (!(*t)){
		maketree(t,inf);
	}else {
		LINKED_BINARY_TREE aux = *t;	
	do{
		if(inf < aux->inf){
			if((*t)->left)
				aux = (*t)->left;
			else{
				setleft(aux, inf);
				break;
			}
		}else if((*t)->right)
				aux = (*t)->right;
			  else {
			  	setright(aux, inf);
				break;
			  }
	}while(1);		
		}
}


int main(){}


