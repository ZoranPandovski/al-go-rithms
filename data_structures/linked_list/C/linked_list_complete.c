#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*headptr = NULL;
void insert(int num,int pos){
    struct node *newptr,*temp,*prev;
    newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = num;
    if(headptr==NULL){
        headptr = newptr;
        newptr->link = NULL;
    }
    else if(pos==0){
        temp = headptr;
        headptr = newptr;
        newptr->link = temp;
    }
    else{
        int i;
        prev = headptr;
        for(i=0;i<=pos-2;i++)
            prev = prev->link;
        temp = prev->link;
        prev->link = newptr;
        newptr->link = temp;
    }
}
void insertLast(int num){
    struct node* newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = num;
    struct node* temp = headptr;
    while(temp->link!=NULL)
        temp = temp->link;
    temp->link = newptr;
    newptr->link = NULL;

}
void delete(int pos){
    struct node *prev,*curr;
    int i;
    if(headptr==NULL)
        printf("List Empty!\n");
    else{
        prev = headptr;
        if(pos==0){
            curr = headptr;
            headptr = headptr->link;
            free(curr);
        }
        else{
            for(i=0;i<=pos-2;i++)
                prev = prev->link;
            curr = prev->link;
            if(curr->link!=NULL)
                prev->link = curr->link;
            else
                prev->link = NULL;
        }
    }
}
void delete_last(){
    struct node* temp = headptr;
    while(temp->link->link!=NULL)
        temp = temp->link;
    temp->link = NULL;
}
void display(){
    struct node* prev = NULL, *curr = headptr, *next = NULL,*temp;
    while(curr!=NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
// void display2(struct node* curr){
//     if(curr->link!=NULL)
//         display2(curr->link);
//     printf("%d ",curr->data);
// }
void reverse(struct node* temp){
    if(temp->link != NULL)
        reverse(temp->link);
    if(temp != headptr)
        printf("%d->", temp->data);
    else 
        printf("%d", temp->data);
}

void display3(struct node* curr){
    if(curr != NULL){
        printf("%d ",curr->data);
        display3(curr->link);
    }
}
int main(){
    int t=0,ch,num,pos;
    struct node* curr = headptr;

    while(t==0){
        printf("Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Num and pos: ");
                scanf("%d%d",&num,&pos);
                insert(num,pos);
                break;
            case 2:
                //printf("Function to delete....\n");
                printf("Pos: ");
                scanf("%d",&pos);
                delete(pos);
                break;
            case 3:
                reverse(headptr);
                printf("\n");
                break;
            case 4:
                t = 1;
                break;
            case 5:
                printf("Last node: ");
                scanf("%d",&num);
                insertLast(num);
                break;
            case 6:
                delete_last();
                break;
            default:
                printf("Error choice!\n");
                break;
        }
    }
}
