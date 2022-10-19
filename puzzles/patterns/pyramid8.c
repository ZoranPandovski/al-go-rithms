#include<stdio.h>
int main(){
	int rows,pattern=1;
	//	pyramid 4
	//	     1
	//	   1 2 1
	//	 1 2 3 2 1
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput
 	// this programme is suitable only for upto 9 row ! then after pyramid obtained will not proper 


	
		printf("Enter number of rows for making pyramid :");
		scanf("%d",&rows);
		for(int r=1;r<=rows;r++){
			int pattern=1;
			for(int c=1;c<=2*rows-1;c++){
				if(c>=rows-r+1 && c<=rows+r-1){
				
					printf("%d ",pattern);
					
//					here we are using ternary operator similarly we can also use if else statement here
					c<rows?pattern++:pattern--;
				}
				else{
					printf("  ");
					}
				
				
			}
			printf("\n");
			}
		return 0;
}