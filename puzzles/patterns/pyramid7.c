#include<stdio.h>
int main(){
	
	//	pyramid 7
//	* * * * * * * * *
//	* * * *   * * * *
//	* * *       * * *
//	* *           * *
//	*               *
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput

	
	int rows;
	printf("Enter the number of rows for making pyramid : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		

		for(int c=1;c<=(2*rows)-1;c++){
			if(c<=(rows-r+1) || c>=(rows+r-1))
			printf("* ");
			else
			printf("  ");
			
	}
	printf("\n");
	}
return 0;
}