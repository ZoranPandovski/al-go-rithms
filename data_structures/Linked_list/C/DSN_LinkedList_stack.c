#include<stdlib.h>
#include<stdio.h>

struct LinkedList{
    int data;
    struct LinkedList* next;
};

struct stack *createstack(){
    return NULL;
};

void push(struct stack **top, int a){
    struct LinkedList* newnode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if(!newnode){
        return NULL;
    }
    newnode->data=a;
    newnode->next=*top;
    (*top)=newnode;
}

int isEmpty(struct stack *top){
    return (top==NULL);
}

int pop(struct stack **top){
    int data;
    struct LinkedList *temp;
    if(isEmpty(top)){
        return INT_MIN;
    }
    temp= *top;
    *top= temp->next;
    data=temp->data;
    free(temp);
    return data;
}

int stacktop(struct stack* top){
    if(isEmpty(top)){
        printf("Empty");
        return INT_MIN;
    }
    struct LinkedList *t;
    t=top;
    return ((t)->next->data);
}

int main(){
    struct stack* A=createstack();
    push(&A,6);
    push(&A,2);
    stacktop(A);
}

