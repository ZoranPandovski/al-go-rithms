#include<stdio.h>
#include<stdlib.h>

struct node
  {
  int info;
  struct node *next;
};


int i=0,a=-1;
int GetNode(struct node *head,int positionFromTail)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    if(head->next != NULL);
        a = GetNode(head->next, positionFromTail);
    if(i == positionFromTail)
        return head->info;
    ++i;
    return a;
}


struct node *START=NULL;
struct node* createNode()
  {
  struct node *new;
  new = (struct node*)malloc(sizeof(struct node));
  return new;
  }

void add(int n)
  {
  struct node *new, *t;
  new = createNode();
  new->info = n;
  new->next = NULL;
  if(START == NULL)
    START = new;
  else
    {
    t = START;
    while(t->next != NULL)
      t = t->next;
    t->next = new;
    }
  }

void show()
  {
  char c;
  struct node *t;
  t = START;
  while(t != NULL)
    {
    printf("%d ", t->info);
    t = t->next;
    }
  fflush(stdin);
  scanf("%c", &c);
  // c = getchar();
  // c = getchar();
  }

void del()
  {
  struct node *t;
  if(START == NULL)
    printf("\nList Empty !");
  else
    {
    t = START;
    START = START->next;
    free(t);
    }
  }

void main()
  {
  int ch, n;
  do
    {
    system("cls");
    printf("1) Enter a new number at ending.\n");
    printf("2) Delete a number from starting.\n");
    printf("3) Print full list.\n");
    printf("0) Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &ch);
    switch (ch)
      {
      case 1: printf("\n Enter the Number : ");
              scanf("%d", &n);
              add(n);
              printf("\nAdded to list !");
              break;
      case 2: del();
              break;
      case 3: printf("\n\n");
              show();
              break;
      case 4: printf("%d", GetNode(START, 2));
      case 0: break;
      default:printf("\nInvalid Input");
      }
    }while(ch!=0);
  }
