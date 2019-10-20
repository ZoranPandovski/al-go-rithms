#include<stdio.h>
#include<stdlib.h>

typedef struct Node { //structure of node
    int data; //data part
    struct Node* prev; //previous node address part
    struct Node* next; //next node address part
} node;

node* createNode(int); //function that creates new node in dynamic memory ie. heap
void insert(int); //function that inserts the created node into the list
void print(void); //function that prints the list

node* head; //head pointer

int main() {
    head = NULL;
    int n, x, i;
    printf("Enter total number: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter the number: ");
        scanf("%d", &x);
        insert(x);
    }
    printf("Given list is: ");
    print();
    return 0;
}

node* createNode(int num) {
    node* temp = (node*)malloc(sizeof(node)); //create node in heap memory
    temp->data = num; //asign the given number to node
    temp->next = NULL; //store NULL in next portion
    temp->prev = NULL; //store NULL in previous portion
    return temp; //returns pointer to new node created in memory
}

void insert(int num) {
    node* new = createNode(num); 
    if(head == NULL) { //check if list is empty
        head = new;
        return;
    }
    new->next = head; //adjust links
    head->prev = new;
    head = new;
    return;
}

void print() {
    node* temp = head;
    while(temp != NULL) {
        printf("%d", temp->data); //print the number
        temp = temp->next; //move to next node in the list
    }
    return;
}