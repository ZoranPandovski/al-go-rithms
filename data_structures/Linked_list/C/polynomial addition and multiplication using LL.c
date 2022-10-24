/*********************************************************************************
TITLE: Program to implement polynomial addition and multiplication using LL.
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 	int coeff; //to store coefficient
 	int expn; //to store exponent
 	struct node *next; //next node
}Node;

typedef struct
{
 	Node *start; //LL of Polynomial
}Poly;


void create_poly(Poly *ptr)
{
 	Node *p, *prev;
 	int ch;

 	do
    	{
        	p=(Node*)malloc(sizeof(Node));
 	 	printf("\n Enter the coefficient : ");
 	 	scanf("%d", &p->coeff);
 	 	printf(" Enter its exponent : ");
 	 	scanf("%d", &p->expn);
 	 	p->next=NULL;
 	 	if(ptr->start==NULL)//is start NULL
 	 	{

 	 	 	ptr->start=p; //point it by start
 	 	}
 	 	else
 	 	{
 	 	 	prev->next = p;
 	 	}
 	 	prev = p; //current node in this iteration becomes previous node in next iteration



 	 	scanf("%d",&ch);
 	}
 	while(ch==1);

}

void display_poly(Poly py)
{

 		Node *ptr;
        	ptr=py.start;
 		while(ptr!=NULL)
 		{
 		 	printf(" %dx^%d ",ptr->coeff,ptr->expn); // display as 5x^3
 		 	if(ptr->next != NULL) //if first or intermediate node
	 	 	 	printf(" + "); //separate the terms by putting '+'
 		 	ptr=ptr->next; //go to next node

}		}

void append_node(Poly *ptr, int n, int c)//same as inserting node at end in LL program
{
 	Node *q, *p;

 	p=(Node*)malloc(sizeof(Node));
 	p->coeff=n;
 	p->expn=c;
 	p->next=NULL;

 	if(ptr->start==NULL)
 	{
 	 	ptr->start=p;
 	}
 	else
 	{
 	 	q = ptr->start; //start traversing from first node
 	 	while(q->next!=NULL) //until u reach to last node
 	 	 	q=q->next;
 	 	q->next=p; //last node gets linked with p

 	}

}
void add_two_poly(Poly *ans,Poly py1,Poly py2) //ans is a pointer to p3 variable
{
 	int sum;

 	Node *ptr1=py1.start,*ptr2=py2.start;
 	//ptr1 for traversing polynomial 1
 	//ptr2 for traversing polynomial 2

 	while(ptr1!=NULL && ptr2!=NULL) // if two nodes in both polynomial present
 	{
 	 	if(ptr1->expn==ptr2->expn) //if expn of terms is same
 	 	{
 	 	 	sum = ptr1->coeff+ptr2->coeff;//add coefficient
 	 	 	append_node(ans,sum,ptr1->expn); //add node in p3 polynomial
 	 	 	ptr1=ptr1->next;
 	 	 	ptr2=ptr2->next;
 	 	}
 	 	else if (ptr1->expn > ptr2->expn) //if expn greater, then append node in p3 polynomial with highest exponent
 	 	{
 	 	 	append_node(ans,ptr1->coeff,ptr1->expn);
 	 	 	ptr1=ptr1->next;
 	 	}
 	 	else //if (ptr1->expn < ptr2->expn)
 	 	{
 	 	 	append_node(ans,ptr2->coeff,ptr2->expn);
 	 	 	ptr2=ptr2->next;
 	 	}
 	}//end of while
 	if(ptr1==NULL) //if first polynomial is exhausted
 	{
 	 	while(ptr2!=NULL) //copy lower order terms of second polynomial to P3
 	 	{

 	 	 	append_node(ans,ptr2->coeff,ptr2->expn);
 	 	 	ptr2=ptr2->next;
 	 	}
 	}
 	if(ptr2==NULL) //if second polynomial is exhausted
 	{
 	 	while(ptr1!=NULL) //copy first polynomial to p3
 	 	{
 	 	 	append_node(ans,ptr1->coeff,ptr1->expn);
 	 	 	ptr1=ptr1->next;
 	 	}
 	}

}
void mul_two_poly(Poly *ans, Poly p1, Poly p2)
{
    int coeff,expn;
    Node*ptr1=p1.start;
    Node*ptr2=p2.start;;
    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
                coeff=ptr1->coeff*ptr2->coeff;
                expn=ptr1->expn+ptr2->expn;
                append_node(ans,coeff,expn);
                ptr2=ptr2->next;
        }
        ptr2=p2.start;
        ptr1=ptr1->next;
    }

}


int main()
{
  Poly p1 , p2 , p3, p4;
  p1.start=NULL;
  p2.start=NULL;
  p3.start=NULL;
  p4.start=NULL;
  int option;

    printf("----------------------------------------------MENU----------------------------------------------");
    printf("\n 1. Create first polynomial");
    printf("\n 2. Create second polynomial");
    printf("\n 3. Add the polynomials");
    printf("\n 4. Multiply the polynomials");
    printf("\n 5. Exit");
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the option: ");
    scanf("%d", &option);
     do
    {
        switch(option)
        {
            case 1:
                printf("\n For polynomial 1 :\n");
                create_poly(&p1);
                printf("------------------------------------------------------------------------------------------------");
                printf("\n First polynomial is : ");
                display_poly(p1);
                printf("\n------------------------------------------------------------------------------------------------\n");

                break;

            case 2:
                printf("\n For polynomial 2 :\n");
                create_poly(&p2);
                printf("------------------------------------------------------------------------------------------------");
                printf("\n Second polynomial is : ");
                display_poly(p2);
                printf("\n------------------------------------------------------------------------------------------------\n");

                break;

            case 3:
                 add_two_poly(&p3,p1, p2);
                 printf("------------------------------------------------------------------------------------------------");
                 printf("\n Resultant polynomial after addition: ");
                 display_poly(p3);
                 printf("\n------------------------------------------------------------------------------------------------\n");


                break;

            case 4:
                mul_two_poly(&p4,p1, p2);
                printf("------------------------------------------------------------------------------------------------");
                printf("\n Resultant polynomial after multiplication: ");
                display_poly(p4);
                printf("\n------------------------------------------------------------------------------------------------\n");


                break;

            case 5:
                exit(0);
        }
    printf("\n Enter the option: ");
    scanf("%d", &option);

    }while(1);
    return 0;
}
/*********************************************************************************
OUTPUT:
----------------------------------------------MENU----------------------------------------------
 1. Create first polynomial
 2. Create second polynomial
 3. Add the polynomials
 4. Multiply the polynomials
 5. Exit
------------------------------------------------------------------------------------------------

 Enter the option: 1

 For polynomial 1 :

 Enter the coefficient : 2
 Enter its exponent : 4

 Enter 1 to continue creation of list and 0 to end it : 1

 Enter the coefficient : 4
 Enter its exponent : 2

 Enter 1 to continue creation of list and 0 to end it : 0
------------------------------------------------------------------------------------------------
 First polynomial is :  2x^4  +  4x^2
------------------------------------------------------------------------------------------------

 Enter the option: 2

 For polynomial 2 :

 Enter the coefficient : 6
 Enter its exponent : 3

 Enter 1 to continue creation of list and 0 to end it : 1

 Enter the coefficient : 2
 Enter its exponent : 2

 Enter 1 to continue creation of list and 0 to end it : 0
------------------------------------------------------------------------------------------------
 Second polynomial is :  6x^3  +  2x^2
------------------------------------------------------------------------------------------------

 Enter the option: 3
------------------------------------------------------------------------------------------------
 Resultant polynomial after addition:  2x^4  +  6x^3  +  6x^2
------------------------------------------------------------------------------------------------

 Enter the option: 4
------------------------------------------------------------------------------------------------
 Resultant polynomial after multiplication:  12x^7  +  4x^6  +  24x^5  +  8x^4
------------------------------------------------------------------------------------------------

 Enter the option: 5

Process returned 0
*********************************************************************************/
