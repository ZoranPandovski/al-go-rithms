#include<stdio.h>

int main(){
	int rows;
//	pyramid 1 
//	    1
//	   2 2
//	  3 3 3 
//	 4 4 4 4
//	5 5 5 5 5 
//	r=rows,sp=space,p=pattern,value=1,rows=userinput
	printf("Enter number of rows for making pyramid :");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		for(int sp=rows-r;sp>=0;sp--){
			printf(" ");
		}
		for(int p=1;p<=r;p++){
		printf("%d ",r);
		}
		printf("\n");
	}
	return (0);
}