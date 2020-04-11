#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//Global variable for DebugMode.
int DebugMode;

typedef struct mazeStruct
{
	char** arr;
	int xsize, ysize;
	int xstart, ystart;
	int xend, yend;
} maze;	


//Stack struct defintion.
struct NODE {
	int xCord;
	int yCord;
	struct NODE* next;
};

//Defining stack as a NODE*
typedef struct NODE* stack;

//Initialize stack.
void init(stack* cur, int x, int y) {
	
	//If stack is empty, return.
	if((*cur) == NULL){
		return;
	}
	
	//Otherwise initialize values.
	(*cur)->next = NULL;
	(*cur)->xCord = x;
	(*cur)->yCord = y;
	
	
}

//Checks if stack is empty.
int is_empty(stack hd){
	if (hd == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//Pushes value onto the stack.
void push(stack* hd, int pushX, int pushY){
	
	//Tmp variable for traversal.
	struct NODE* tmp = (*hd);

	//Debug mode output. 
	if (DebugMode == TRUE){
		printf("\nPushing (%d, %d)", pushX, pushY);
	}
    
	//Allocate new node and initialize it's values.
	tmp = (struct NODE*) malloc (sizeof(struct NODE));
	init(&tmp, pushX, pushY);
	
	//Link new node, and update head.
	tmp->next = *hd;
	*hd = tmp;
	
	return;
}

//Remove the top value of the stack.
void pop(stack* hd){
	
	//Assign tmp to top of stack.
	struct NODE* tmp = (*hd);

	//Return if stack is empty, otherwise check for debug.
	if(tmp == NULL){
		return;
	}
	else if (DebugMode == TRUE){
		printf("\nPopping (%d, %d)", tmp->xCord, tmp->yCord);
	}
	
	//Move head up, deallocate tmp. (popping the stack)
	*hd = (*hd)->next;
	free(tmp);
}

//Return the top value of the stack.
void top(stack hd, int* topX, int* topY){
	
	//Check for empty stack.
	if (hd == NULL){
	    return;
	}
	
	//Assign paramaters to the top of the stack.
	*topX = hd->xCord;
	*topY = hd->yCord;	
}

//Clear the stack.
void clear(stack* hd) {
	
	//Check for empty stack.
	if (*hd == NULL){
		return;
	}
	
	//NODE* for keeping track of the next node.
	struct NODE* nextNode;
	
	//Deallocate current node and traverse while next node isn't null.
	while((*hd)->next != NULL){
		nextNode = (*hd)->next;
		free(*hd);
		*hd = nextNode;
	}
	
	//Free the last node/
	free(*hd);
	*hd = NULL;
}

//Print the solution recursively.
void printSolution(stack hd) {
	
	//Return if stack is empty.
	if (hd == NULL){
		return;
	}
	
	//Recursive call, printing current nodes value after return.
	printSolution(hd->next);
	printf("(%d,%d)\n", hd->xCord, hd->yCord);
	
}


int main (int argc, char **argv)
{
	
	maze m1;

	int xpos, ypos;
	int i,j;

	FILE *src;
	
	//Start DebugMode as false.
	DebugMode = FALSE;
	
	//Check command line arguments.
	for (i = 0; i<argc; i++) {
		
		//Check for debug flag.
		if(strcmp(argv[i], "-d") == 0){
			
			//Set DebugMode to true.
			DebugMode = TRUE;
			continue;
		}
		
			/* Try to open the input file. */
		if ( ( src = fopen( argv[i], "r" )) == NULL ){
			printf ( "Can't open input file: %s", argv[i] );
			exit(-1);
		}
		else{
			continue;
		}
	}

	/* verify the proper number of command line arguments were given */
	if(argc < 2) {
		printf("Usage: %s <input file name>\n", argv[0]);
		exit(-1);
	}

	//Int for keeping track of valid lines in file.
	int validLines = 0;
	
	//Read in the size of the maze.
	while (fscanf (src, "%d %d", &m1.xsize, &m1.ysize) != EOF)
	{
		//If invalid size, continue.
		if((m1.xsize == 0) || m1.ysize == 0){
			fprintf( stderr, "\nInvalid size [%d][%d]\n", m1.xsize, m1.ysize);
			continue;
		}
		
		//If valid, increment validLines and break.
		validLines++;
		break;
	}
	
	//Read in the starting position.
	while (fscanf (src, "%d %d", &m1.xstart, &m1.ystart) != EOF)
	{
		//If invalid, continue.
		if((m1.xstart < 1) || (m1.xstart > m1.xsize) || (m1.ystart < 1) || (m1.ystart > m1.ysize)){
			fprintf( stderr, "Invalid starting position (%d, %d)\n", m1.xstart, m1.ystart);
			continue;
		}
		
		//If valid increment and break.
		validLines++;
		break;
	}
	
	//Read in the ending position.
	while (fscanf (src, "%d %d", &m1.xend, &m1.yend) != EOF)
	{
		//If invalid, continue.
		if((m1.xend < 1) || (m1.xend > m1.xsize) || (m1.yend < 1) || (m1.yend > m1.ysize)){
			fprintf( stderr, "Invalid ending position (%d, %d)\n", m1.xend, m1.yend);
			continue;
		}
		
		//If valid increment and break.
		validLines++;
		break;
	}
	
	//Check to see if at least 3 valid lines were inputted.
	if(validLines != 3){
		
		printf("Fewer than 3 valid lines of input were entered \n", argv[0]);
		exit(-1);
	}

	/* print them out to verify the input */
	printf ("\nsize: %d, %d\n", m1.xsize, m1.ysize);
	printf ("start: %d, %d\n", m1.xstart, m1.ystart);
	printf ("end: %d, %d\n", m1.xend, m1.yend);

	//Dynamically Allocate 2D Array.
	m1.arr = (char**) malloc (sizeof(char*) * (m1.xsize+2));
	
	for(i = 0; i < m1.xsize+2; i++){
		m1.arr[i] = (char*) malloc(sizeof(char) * (m1.ysize+2));
	}
	
	/* initialize the maze to empty */
	for (i = 0; i < m1.xsize+2; i++)
		for (j = 0; j < m1.ysize+2; j++)
			m1.arr[i][j] = '.';

	/* mark the borders of the maze with *'s */
	for (i=0; i < m1.xsize+2; i++)
	{
		m1.arr[i][0] = '*';
		m1.arr[i][m1.ysize+1] = '*';
	}
	for (i=0; i < m1.ysize+2; i++)
	{
		m1.arr[0][i] = '*';
		m1.arr[m1.xsize+1][i] = '*';
	}

	/* mark the starting and ending positions in the maze */
	m1.arr[m1.xstart][m1.ystart] = 's';
	m1.arr[m1.xend][m1.yend] = 'e';
	

	/* mark the blocked positions in the maze with *'s */
	while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
	{
		//Continue if trying to block starting/ending position.
		if(((xpos == m1.xstart) && (ypos == m1.ystart)) || ((xpos == m1.xend) && (ypos == m1.yend))){
			continue;
		}
		
		m1.arr[xpos][ypos] = '*';
	}

	/* print out the initial maze */
	printf("\n");
	for (i = 0; i < m1.xsize+2; i++)
	{
		for (j = 0; j < m1.ysize+2; j++)
			printf ("%c", m1.arr[i][j]);
			printf("\n");
	}

	//Mark all unblocked positions in the maze as unvisited.
	for (i = 0; i < m1.xsize+2; i++)
	{
		for (j = 0; j < m1.ysize+2; j++)
			if (m1.arr[i][j] == '.' || m1.arr[i][j] == 'e'){
				m1.arr[i][j] = 'U';
			}
			else if (m1.arr[i][j] == 's'){
				m1.arr[i][j] = 'V';
			}
	}

	//Formatting
	if (DebugMode == TRUE){
		printf("\n*Debug info*");
	}
	
	//Create stack and push the start position.
	stack coordinates = NULL;
	push(&coordinates, m1.xstart, m1.ystart);
	
	//Mark start position as visited.
	m1.arr[m1.xstart][m1.ystart] = 'V';
	
	//Declare variables for storing current coordiantes.
	int currentX;
	int currentY;
	int d = 0;
	
	//Store current coordiantes.
	top(coordinates, &currentX, &currentY);
	
	//Loop while stack isn't empty and top of stack is not the end.
	while((!is_empty(coordinates)) && (m1.arr[m1.xend][m1.yend] != m1.arr[currentX][currentY])){
		
		//If neighbor is unvisted.
		if (m1.arr[currentX+1][currentY] == 'U'){
			
			//Set neighbor to visted, and push onto stack.
			m1.arr[currentX+1][currentY] = 'V';
			push(&coordinates, currentX+1, currentY);
			
			//Update coordinates and continue to next iteration.
			top(coordinates, &currentX, &currentY);
			continue;
			
		}
		else if (m1.arr[currentX-1][currentY] == 'U'){
			
			//Set neighbor to visted, and push onto stack.
			m1.arr[currentX-1][currentY] = 'V';
			push(&coordinates, currentX-1, currentY);
			
			//Update coordinates and continue to next iteration.
			top(coordinates, &currentX, &currentY);
			continue;
			
		}
		else if (m1.arr[currentX][currentY+1] == 'U'){
			
			//Set neighbor to visted, and push onto stack.
			m1.arr[currentX][currentY+1] = 'V';
			push(&coordinates, currentX, currentY+1);
			
			//Update coordinates and continue to next iteration.
			top(coordinates, &currentX, &currentY);
			continue;
			
		}
		else if (m1.arr[currentX][currentY-1] == 'U'){
			
			//Set neighbor to visted, and push onto stack.
			m1.arr[currentX][currentY-1] = 'V';
			push(&coordinates, currentX, currentY-1);
			
			//Update coordinates and continue to next iteration.
			top(coordinates, &currentX, &currentY);
			continue;
			
		}
		else{ //No unvisted neighbors.
		
			//Pop the top of the stack, and update coordiantes.
			pop(&coordinates);
			top(coordinates, &currentX, &currentY);
		}
		
	}
	
	//Formatting
	if (DebugMode == TRUE){
		printf("\n");
	}
	
	//If solution was found, print solutions from stack.
	if (m1.arr[m1.xend][m1.yend] == m1.arr[currentX][currentY]){
		
		printf("\n*Solution*\n");
		printSolution(coordinates);
		printf("\n");
	}
	//Else no solutions exist.
	else{
		printf("\nThe Maze has no solutions. \n\n");
	}
	
	//Deallocate and clear memory from the stack.
	clear(&coordinates);
	
	//Deallocate 2-D array.
	for (i = 0; i < m1.xsize+2; i++){
		free(m1.arr[i]);
	}
	
	free(m1.arr);
}
