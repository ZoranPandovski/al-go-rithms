#include<iostream>
using namespace std;
class XORLinkedList{
public:
    int data;
    XORLinkedList* xorPtr;
    XORLinkedList(int data){
        this->data=data;
        this->xorPtr=NULL;
    }
};
XORLinkedList* XOR(XORLinkedList* prev,XORLinkedList* next){
    return (XORLinkedList*)((unsigned int)(prev) ^(unsigned int)(next));
}
XORLinkedList* insertAtIthPositionHelper(XORLinkedList** head,int data,int i,XORLinkedList** prev){
    if(*head==NULL){
        if(i==0){
            XORLinkedList* newNode=new XORLinkedList(data);
            (*head)=newNode;
        }
        return (*head);
    }
    if(i==0){
        XORLinkedList* newNode=new XORLinkedList(data);
        (*head)->xorPtr=XOR((*prev),newNode);
        newNode->xorPtr=XOR((*prev),NULL);
        return newNode;
    }
    XORLinkedList* temp=XOR((*prev),(*head));
    XORLinkedList* prev2=(*head);
    (*head)=insertAtIthPositionHelper(&temp,data,i-1,&prev2);
    return (*head);
}
XORLinkedList* insertAtIthPosition(XORLinkedList** head,int data,int i){
    return insertAtIthPositionHelper(head,data,i,NULL);
}
void printList(XORLinkedList* prev,XORLinkedList* head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head,XOR(head->xorPtr,prev));
    return;
}
