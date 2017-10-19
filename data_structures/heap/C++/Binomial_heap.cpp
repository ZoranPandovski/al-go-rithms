/*--------------CONCEPT-------------------*/

	/*----CONCEPT OF BINOMIAL HEAP AS TAUGHT IN CLASS AND FROM CORMEN BOOK IS USED----*/

	/*----SETW FUNCTION FROM STANDARD LIBRARY IS USED----*/
/*----------ASSUMPTION----------*/

	/*----NUMBER OF HEAPS WILL ALWAYS BE LESS THAN 100----*/

#include <bits/stdc++.h>

using namespace std;

//NODE DECLARATION
typedef struct node
{
	struct node *parent;
	int key;
	int degree;
	struct node *leftmostchild;
	struct node *sibling;
	
}node;


//FUNCTION TO SWAP TWO INTEGERS
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//FUNCTION TO LINK TWO BINOMIAL TREES (MAKES X PARENT OF Y)
void binomiallink(node* y, node* x)		
{
	y->parent = x;
	y->sibling = x->leftmostchild;
	x->leftmostchild = y;
	x->degree = x->degree + 1;
}

//FUNCTION TO ALLOCATE MEMORY AND HANDLE POINTERS FOR A NEWLY CREATED NODE
node* makebinomialheap()
{
	node* newnode = new node;
	newnode->parent = NULL;
	newnode->leftmostchild = NULL;
	newnode->sibling = NULL;
	newnode->degree = 0;
	newnode->key = -1;
	return newnode;
}

//FUNCTION THAT RETURNS NODE WITH MINIMUM VALUE FROM A BINOMIAL HEAP
node* getmin(node* head)
{
	//Y IS USED TO POINT TO MINIMUM NODE
	node* y = NULL;

	//X WILL BE USED TO ITERATE THROUGH THE ROOT LIST
	node* x = head;
	
	//DENOTES INFINITY
	int min = 99999;
	
	while(x != NULL)
	{
		if(x->key < min) 
		{
			min = x->key;
			y = x;
		}
		x = x->sibling;
	}

	return y;
}

//FUNCTION TO ADD NODE X BEFOR NODE P IN A BINOMIAL HEAP
node* insertbeforep(node* head ,node* p, node* x)
{
	//TEMP WILL POINT TO THE NODE JUST BEFORE NODE P
	node* temp = head;
	while(temp->sibling != NULL && temp->sibling != p)temp = temp->sibling;
	
	if(temp == head)
	{
		x->sibling = temp;
		head = x;
	}
	else
	{
		temp->sibling = x;
		x->sibling = p;
	}

	return head;
}

//FUNCTION TO MERGE TWO BINOMIAL HEAPS INTO ONE LIST BUT THAT LIST MAY NOT NECESSARILY BE A BINOMIAL HEAP
node *binomialmerge(node *h1, node *h2)
{
	//CHECK IF EITHER IS NULL
	if (h1 == NULL && h2 != NULL)
	{
		return h2;
	}
	else if (h2 == NULL && h1 != NULL)
	{
		return h1;
	}
	else if (h1 == NULL && h2 == NULL)
	{
		return NULL;
	}

	//Z DENOTES HEAD TO THE FINAL HEAP AFTER MERGING THE TWO INPUT HEAPS
	node *z;

	//X WILL BE USED TO ITERATE HEAP 1 AND Y WILL BE USED TO ITERATE HEAP 2
	node *x = h1, *y = h2, *temp;

	//SELECT THE NODE WHICH HAS LEAST DEGREE FROM EITHER X OR Y
	if (x->degree < y->degree)
	{
		temp = x;
		x = x->sibling;
	}
	else
	{
		temp = y;
		y = y->sibling;
	}

	z = temp;
	
	//FROM THAT X OR Y SELECT A PART OF THAT HEAP WHERE DEGREE OF ALL ROOT NODES IS LESS THAN THE DEGREE OF OTHER
	while(x != NULL && y != NULL)
	{
		if (x->degree < y->degree)
		{
			temp->sibling = x;
			x = x->sibling;
		}
		else
		{
			temp->sibling = y;
			y = y->sibling;
		}
		temp = temp->sibling;
	}

	//WHEN EITHER OF THE LIST CONTAIN ONLY ONE NODE
	if (temp->sibling == NULL)
	{
		if (x != NULL)
		{
			temp->sibling = x;
		}
		if (y != NULL)
		{
			temp->sibling = y;
		}
	}

	return z;
}

//FUNCTION TO UNITE TWO BINOMIAL HEAP INTO ONE BINOMIAL HEAP
node* binomialheapunion(node* h1, node* h2)
{
	//FINAL HEAP DENOTES THE HEAD OF THE BINOMIAL HEAP FORMED AFTER MERGING THE TWO HEAPS
	node* finalheap = makebinomialheap();

	//MERGER THE TWO HEAPS
	finalheap = binomialmerge(h1,h2);
	
	//NOW WE JUST HAVE TO REORGANISE THE FINALHEAP SO THAT IT FOLLOWS ALL PROPERTIES OF BINOMIAL HEAP

	if(finalheap == NULL) return finalheap;

	//THREE POINTERS X, NEXTX AND PREVX WII BE USED 

	//X IS ITERATOR WHICH STARTS FROM HEAD OF THE FINALHEAP
	node* x = makebinomialheap();
	x=finalheap;

	//NEXTX WILL ALWAYS POINT TO SIBILING OF X
	node* nextx = x->sibling;
	
	//PREVX WILL ALWAYS POINT TO NODE PREVIOUSTO X WHICH INITIALLY IS NULL
	node* prevx = NULL;

	//WHILE X HAS NOT REACHED THE FINAL NODE
	while(nextx != NULL)
	{
		//UPDATE NEXTX
		nextx = x->sibling;

		if(nextx == NULL) break;

		//ALL THE CONDITIONS MENTIONED HERE ARE THE CONDITIONS WHERE NOTHING NEEDS TO BE DONE SO JUST UPDATE X AND PREVX AND NEXTX
		if((x->degree != nextx->degree) || (nextx->sibling != NULL && (nextx->sibling)->degree == x->degree))
		{
			prevx = x;
			x = nextx;
		}
		else 
		{
			//MAKE NODE WITH LEAST KEY THE PARENT NODE
			if(x->key <= nextx->key){
				
				//UPDATE POINTER OF X AS NEXTX WILL BECOME ITS CHILD
				x->sibling = nextx->sibling;

				//LINK NEXTX AND X
				binomiallink(nextx,x);
			}
			else
			{
				//UPDATE PREVX
				if(prevx == NULL)
				{
					finalheap = nextx;
				}
				else
				{
					prevx->sibling = nextx;
				}

				//LINK X AND NEXTX
				binomiallink(x,nextx);
				x = nextx;
			}
		}
	}
	return finalheap;

}

//FUNCTION USED TO INSERT A NUMBER X INTO A BINOMIAL HEAP
node* binomialinsert(node* head, int x)
{
	//IF THE BINOMIAL HEAP IS EMPTY THEN HEAD->HEY == -1
	if(head->key == -1)
	{
		head->key = x;
		return head;
	}

	//TRANSFER X TO A TEMPORARY NODE AND TAKE UNION OF THAT NODE WITH THE ORIGINAL HEAP
	node* temp = makebinomialheap();
	temp->key = x;
	temp->degree = 0;
	head = binomialheapunion(head,temp);

	return head;
}


//FUNCTION WHICH RETURNS MINIMUM OF THREE NUMBERS
int min (int a, int b, int c)
{
	int min = b;
	if(a<b) min =a;
	if(c < min) min = c;
	return min;
}

//FUNCTION TO PRINT THE NODES OF THE BINOMIAL HEAP AT A GIVEN DEPTH 
void showheap(node * node , int depth)
{
	
	//RECURSIVE FUNCTION THAT MAKES LAST SIBILING NODE TO BE PRINTED FIRST
	if (node->sibling != NULL)
	{
		showheap(node->sibling , depth);
	}

	//FOR NODES IN THE ROOT LIST
	if (node->parent == NULL)
	{
		cout<<endl;
	}

	//FOR ALL NODES WITH NO LEFT CHILD OR NO PARENT
	if ( node->leftmostchild != NULL || node->parent == NULL )
	{
		//GIVE INDENTION = DEPTH*6+4 THEN PRINT THEN KEY
		cout<<setw(depth*6 + 4)<<node->key;

		if (node->leftmostchild == NULL)
		{
			cout<<endl<<endl;
		}
	}
	else
	{
		//GIVE INDENTION = 6 THEN PRINT THEN KEY
		cout<<setw(6)<<node->key<<endl;
	}

	//AFTER PRINTING A NODE PRINT ITS CHILD NODES
	if (node->leftmostchild != NULL)
	{
		showheap(node->leftmostchild , depth+1);
	}

}

//FUNCTION TO PRINT THE BINOMIAL HEAP
void printheap(node *head)
{
	cout<<"Structure of the binomial Heap (rotated 90 degrees cwise) is :\n\n ";
	if (head == NULL){
		cout<<"Heap is empty"<<endl;
	}
	else 
	{
		cout<<endl;

		//START SHOEING THE HEAP FROM DEPTH 0;
		showheap(head , 0);
	}
}

//FUNCTION TO EXTRACT MINIMUM NODE FROM THE BINOMIAL HEAP
node* extractmin(node* &head)
{
	//NULL CHECK
	if(head == NULL)
	{
		return NULL;
	}

	//MIN DENOTES THE POINTER TO THE NODE WITH MINIMUM KEY IN THE ROOT LIST
	node* min = getmin(head);

	node* x = min;
	
	//CHILDLIST DENOTES THE HEAD OF THE REVERSED CHILD LIST OF THE MIN NODE
	node* childlist = makebinomialheap();
	
	node* temp = head;

	//LEFT CHILD DENOTES THE HEAD OF THE CHILD LIST OF THE MIN NODE
	node* leftchild = min->leftmostchild;
	
	//BRING TEMP JUST PREVIOUS TO MIN NODE
	while(temp != min && (temp->sibling != NULL && temp->sibling != min))
	{
		temp = temp->sibling;
	}

	//IF MINIMUM IS EQUAL TO THE HEAD
	if(min == head)
	{
		head = head->sibling;
	}
	else
	{
		//ISOLATE MIN NODE FORM THE ROOT LIST
		temp->sibling = min->sibling;
		min->sibling = NULL;
		min->leftmostchild = NULL;

	}

	//REVERSE THE CHILD LIST OF MIN
	if(leftchild != NULL)
	{	
		//TEMPLC WILL DENOTE THE HEAD OF THE CHILD LIST OF THE MIN NODE
		node* templc = leftchild;
		temp = leftchild->sibling;
		leftchild->sibling = NULL;
		leftchild->parent == NULL;
		while(temp != NULL)
		{
			x = temp->sibling;
			temp->sibling = leftchild;
			leftchild = temp;				
			temp = x;
			leftchild->parent = NULL;
		}

		//NOW UNITE REVERSED CHILD LIST AND THE MAIN HEAP
		head = binomialheapunion(head,leftchild);
	}

	return min;
} 

//FUNCTION THAT ORIGINALLY PRINTS ALL THE AVAILABLE CHOICES
void choices()
{
    cout<<endl<<"Choose one of the following options:\n";
    cout<<"(c)\tMAKE-BINOMIAL-HEAP\n";
    cout<<"(u)\tBINOMIAL-HEAP-UNION\n";
    cout<<"(i)\tBINOMIAL-HEAP-INSERT\n";
    cout<<"(d)\tBINOMIAL-HEAP-EXTRACT-MIN\n";
    cout<<"(s)\tPRINT THE BINOMIAL HEAP\n";
    cout<<"(+)\tTurn on print after extract min\n";
    cout<<"(-)\tTurn off print after extract min\n";
    cout<<"(q)\tEXIT THE PROGRAM\n";
    cout<<endl<<"Enter Choice :\n";
}

int main()
{
	int n,i,f=0,j;

	//INPUT CHARACTER IS STORED IN X
	char x = 'z';

	//NUMBER OF HEAPS IS STORED IN THIS
	int numberofheaps = 0;

	//AT MAX 100 HEAPS CAN BE CREATED
	node* heap[100];

	//PRINT CHOICES
	choices();

	while(1)
	{
		cin>>x;
		switch(x)
		{
			case 'c':
			{
				heap[numberofheaps] = makebinomialheap();
				numberofheaps++;
				cout<<"Made empty heap with index: "<<numberofheaps-1<<" , total number of heaps is "<<numberofheaps<<endl;
				break;
			}
			case 'u':
			{
				if(numberofheaps == 0)
				{
					cout<<"Create a heap first"<<endl;
					continue;
				}
				cout<<"Enter the indexes of the two binomial heaps you want to merge."<<endl<<"The heap indices are from 0 to "<<numberofheaps-1<<endl;
	            int a , b;
	            cin>>a>>b;
	            if (a >= numberofheaps || b >= numberofheaps || a < 0 || b < 0)
	            {
	            	cout<<"ERROR : No Heap Found at that INDEX"<<endl;
	            	continue;
	            }
	            else if (a == b)
	            {
	            	cout<<"Cannot Merge the heap with itself. Please Enter distinct values"<<endl;
	            	continue;
	            }
	            heap[a] = binomialheapunion(heap[a] , heap[b]);
	            cout<<"After the UNION , the new heap is stored in the index : "<<a<<endl;
	            break;

			}
			case 'i':
			{
				if (numberofheaps == 0)
	        	{
	        		cout<<"Create a heap First"<<endl;
	        		continue;
	        	}
	        	int x;
	        	cin>>x;
	        	heap[numberofheaps-1] = binomialinsert(heap[numberofheaps-1], x);
	        	break;
			}
			case 'd':
			{
				if(numberofheaps == 0)
				{
					cout<<"Create a heap first"<<endl;
					continue;
				}
				
				node* min = extractmin(heap[numberofheaps-1]);
				if (f == 1 && min != NULL)// no silent extract min
            	{
            		cout<<"Minimum Extracted : "<<min->key<<endl;
            	}
            	if(min == NULL)cout<<"Heap is empty"<<endl;	
				break;
			}
			case 's':
			{
				if (numberofheaps == 0)
	        	{
	        		cout<<"Create a heap First\n";
	        		continue;
	        	}
	        	if (numberofheaps > 1)
	        	{
	        		cout<<"Which Heap do you want to print? Please enter the index of that heap(Available Heaps are from 0 to "<<numberofheaps-1<<") :\t";
	        		int x;
	        		cin>>x;
	        		if (x < 0 || x >= numberofheaps)
	        		{
	        			cout<<"Please Enter A valid HEAP INDEX"<<endl;
	        			continue;
	        		}
	        		printheap(heap[x]);
	        	}
	        	else
	        	{
	        		printheap(heap[numberofheaps-1]);
	        	}
	        	break;
			}
			case '+':
	        	f = 1;
	        	cout<<"PrintFlag turned 'ON'"<<endl;
	        	break;

	        case '-':
	        	f = 0;
	        	cout<<"PrintFlag turned 'OFF'"<<endl;
	        	break;
	        case 'q':
	        	return 0;
	     	default:
	            cout<<"Please Enter a valid choice.\n";
	            break;
		}
	}

	return 0;
}