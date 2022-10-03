/** 
Append k last node of a linked list 

LL -> 1 2 3 4 5 6

k = 3

******* Solution *******

LL -> 4 5 6 1 2 3   

Solution by DivyanshuKaushik
*/

#include<bits/stdc++.h>
// use functions linkedlist.cpp 
#include "linkedlist.cpp"

using namespace std;

int length(node* head){
    int len=0;
    node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

node* appendKNodes(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = length(head);
    k = k%l;
    int count = 1;
    while(tail->next!=NULL){
        // new tail 
        if(count==l-k)
            newTail=tail;
        // new head 
        if(count==l-k+1)
            newHead = tail;
        tail = tail->next;
        count++;
    }
    tail->next = head;
    newTail->next = NULL;
    return newHead;
}

int main(){
    node* head = NULL;
    int values[] = {1,2,3,4,5,6};
    for(auto i:values){
        insertAtTail(head,i);
    }
    node* newHead = appendKNodes(head,3);
    display(newHead);
    return 0;
}
