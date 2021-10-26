/*Stack Operations using Static Array*/
#include <stdio.h>
#define CAPACITY 5
int stack[CAPACITY], top = -1;

void push(int);
int pop(void);
int peek(void);
void traverse(void);

void main()
{
    int ch, item;
    while(1)
    {
        printf("1. PUSH \n2. POP \n3. PEEK \n4. TRAVERSE \n5. QUIT\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                {
                    printf("Enter an element : ");
                    scanf("%d", &item);
                    push(item);
                    break;
                }
            case 2:
                {
                    printf("%d is Popped \n\n", pop());
                    break;
                }
            case 3:
                {
                    printf("Top element is %d \n\n", peek());
                    break;
                }
            case 4:
                {
                    traverse();
                    break;
                }
            case 5:
                exit(0);
            default:
                printf("Invalid Option!");
        }

    }
}

int isFull()
{
    if(top == CAPACITY - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Overflow! \n\n");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("%d is Pushed in the Stack! \n\n", ele);
    }
}

int pop()
{
    if(isEmpty())
        return 0;
    else
        return stack[top--]; //first return stack[top] and the top-- occurs
}

int peek()
{
    if(isEmpty())
        return 0;
    else
        return stack[top]; // no top-- i.e. no deletion
}

void traverse()
{
    if(isEmpty())
        printf("Stack is Empty! \n\n");
    else
    {
        int i;
        printf("Stack Elements : \n\n");
        for(i = 0; i <= top; i++)
        {
            printf("%d \n", stack[i]);
        }
        printf("\n");
    }
}

