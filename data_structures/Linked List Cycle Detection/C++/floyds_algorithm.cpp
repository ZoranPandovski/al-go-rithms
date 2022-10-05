# include <iostream>
using namespace std;


class node{
    public: 

    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};


void insert_at_tail(node* &head, int val){
    node* n = new node(val);

    //LL is empty
    if (head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}


void insert_at_head(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}


bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if (temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


bool detect_cycle(node* &head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}

void make_cycle(node* &head,  int pos){
    node* temp = head;
    node* startNode;
    int count = 1;

    while(temp->next != NULL){
        if (count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

void remove_cycle(node* &head){
    node* fast = head;
    node* slow = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main(){
    node* head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    display(head);
    make_cycle(head, 2);

    cout << "Cycle Present ? - ";
    if (detect_cycle(head)){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    
    cout << "Cycle Present ? - ";
    remove_cycle(head);
        if (detect_cycle(head)){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}