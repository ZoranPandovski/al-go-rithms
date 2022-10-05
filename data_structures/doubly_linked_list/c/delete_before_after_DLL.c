#include <stdio.h>
#include <malloc.h>


// The basic structure of a double linked list
// with two pointers pointing to the previous and next elements 
// and a int with the data of current node
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

// Start of the list should be NULL for now as the list is empty
struct node *start = NULL;

// Function definitions so we can write define the actual funtions after main
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);


int main()
{
    int option;
    do
        {
        // Main menu of the program, just printf
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Delete a node before a given node");
        printf("\n 4: Delete a node after a given node");
        printf("\n 5: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        // Switch case is more efficient here than if-else simply becuase we know the input range
        switch(option)
        {   
            // We always return start becuase we should always know where the start of the list is
            case 1: start = create_ll(start);
                printf("\n DOUBLY LINKED LIST CREATED");
                break;
            case 2: start = display(start);
                break;
            case 3: start = delete_before(start);
                break;
            case 4: start = delete_after(start);
                break;
        }
    } while(option != 5);

    return 0;
}


struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    // As long as -1 is not entered, we take inputs
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while(num !=-1)
    {
        if(start == NULL) // Basically, if list is empty, then this block executes
        {
            new_node = (struct node*)malloc(sizeof(struct node)); // Allocating memory

            // Making the new node as the start
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            start = new_node;
        }
        else // Otherwise we just add to the end of existing list
        {
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node)); // Allocating memory
            new_node -> data = num;
            while(ptr -> next != NULL)
            ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> prev = ptr;
            new_node -> next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}


struct node *display(struct node *start)
{
    struct node *ptr;

    // This ptr pointer will traverse through the nodes for us and print them
    ptr = start;
    while(ptr!=NULL)
    {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next; // Move on to next node
    }
    return start;
}

// To delete the beginning of the node
// We will call this function in delete before, if the node before is start
struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    // Travering using a ptr again
    ptr = start;
    start = start -> next;
    start -> prev = NULL;
    
    free(ptr); //Free the memory allocated

    return start;
}


struct node *delete_before(struct node *start)
{
    struct node *ptr, *temp;
    int val;

    printf("\n Enter the value before which the node has to deleted:");
    scanf("%d", &val);

    // Using ptr to traverse through the list until we reach the required node
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    temp = ptr -> prev;

    if(temp == start)
        start = delete_beg(start);
    else
    {   
        // Changing the pointers of the node
        ptr -> prev = temp -> prev;
        temp -> prev -> next = ptr;
    }

    free(temp); // Freeing memory regarless of the case

    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;

    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);

    //Using ptr to traverse to required node
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;

    // Changing pointers, we will free the memory next
    temp = ptr -> next;
    ptr -> next = temp -> next;
    temp -> next -> prev = ptr;

    free(temp); // Freeing memory

    return start;
}