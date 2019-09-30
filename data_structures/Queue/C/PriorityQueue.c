#include <stdio.h> 
#include <stdlib.h> 
#define MAX 5 

void insert_by_priority(int); 
void delete_by_priority(int); 
void create(); 
void check(int); 
void display_pqueue(); 

int pri_que[MAX]; 
int front, rear; 

int main() 
{ 
    int n, ch;  
    printf("\n1 Insert"); 
    printf("\n2 Delete"); 
    printf("\n3 Display"); 
    printf("\n4 Exit");  
    create();  
    while (1) 
    { 
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);   
        switch (ch) 
        { 
        case 1: 
            printf("\nInsert Element : "); 
            scanf("%d",&n); 
            insert_by_priority(n); 
            break; 
        case 2: 
            printf("\nEnter Element to Delete : "); 
            scanf("%d",&n); 
            delete_by_priority(n); 
            break; 
        case 3: 
            display_pqueue(); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("\n Invalid Choice"); 
        } 
    } 
}  
void create() //Create Function 
{ 
    front = rear = -1; 
}  
void insert_by_priority(int data) //Insert Function 
{ 
    if (rear >= MAX - 1) 
    { 
        printf("\nQueue is Overflow"); 
        return; 
    } 
    if ((front == -1) && (rear == -1)) 
    { 
        front++; 
        rear++; 
        pri_que[rear] = data; 
        return; 
    }    
    else 
        check(data); 
    rear++; 
}  
void check(int data) //Check Function - to check priority and place element 
{ 
    int i,j;  
    for (i = 0; i <= rear; i++) 
    { 
        if (data >= pri_que[i]) 
        { 
            for (j = rear + 1; j > i; j--) 
            { 
                pri_que[j] = pri_que[j - 1]; 
            } 
            pri_que[i] = data; 
            return; 
        } 
    } 
    pri_que[i] = data; 
}  
void delete_by_priority(int data) //Delete Function 
{ 
    int i;  
    if ((front==-1) && (rear==-1)) 
    { 
        printf("\nQueue is empty no elements to delete"); 
        return; 
    }  
    for (i = 0; i <= rear; i++) 
    { 
        if (data == pri_que[i]) 
        { 
            for (; i < rear; i++) 
            { 
                pri_que[i] = pri_que[i + 1]; 
            } 
            pri_que[i] = -99; 
            rear--; 
            if (rear == -1) 
               front = -1; 
            return; 
        } 
    } 
    printf("\n%d not found in queue to delete", data); 
} 
void display_pqueue() //Display Function 
{ 
    if ((front == -1) && (rear == -1)) 
    { 
        printf("\nQueue is empty"); 
        return; 
    }  
    for (; front <= rear; front++) 
    { 
        printf(" %d ", pri_que[front]); 
    } 
     front = 0; 
}
