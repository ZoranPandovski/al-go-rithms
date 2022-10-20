#include<stdio.h>
int main(){
	
	//	pyramid 5
	//	    *
	//	   ***
	//	  *****
	//	 *******
	//	*********
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput

	
	int rows;
	printf("Enter the number of rows for making pyramid : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		
//		type 1 
//	for(int sp=1;sp<=rows-r;sp++){
//		printf(" ");
//	}
//	for(int c=1;c<=2*r-1;c++){
//		printf("*");
		
//		type 2
		for(int c=1;c<=2*rows-1;c++){
			if(c>=rows-r+1 && c<=rows+r-1)
			printf("*");
			else
			printf(" ");
			
	}
	printf("\n");
	}
return 0;
}