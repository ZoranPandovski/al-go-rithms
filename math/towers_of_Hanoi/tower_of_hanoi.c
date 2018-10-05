#include <stdio.h> 
int TowerOfHanoi(int n, char from, char to, char aux)
{
	if(n==1)
	{
		printf("Move disk 1 from rod %c to rod %c\n",from,to);
		return 0;
	}
	TowerOfHanoi(n-1,from, aux,to);
	printf("Move disk %d from rod %c to rod %c\n",n,from,to);
	TowerOfHanoi(n-1,aux,to,from);
}
int main() 
{ 
    int n = 4; // Number of disks 
    TowerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
}

/*
Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 3 from rod A to rod B
 Move disk 1 from rod C to rod A
 Move disk 2 from rod C to rod B
 Move disk 1 from rod A to rod B
 Move disk 4 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 2 from rod B to rod A
 Move disk 1 from rod C to rod A
 Move disk 3 from rod B to rod C
 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C

*/
