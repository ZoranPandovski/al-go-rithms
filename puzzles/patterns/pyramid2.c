#include<stdio.h>
int main(){
	int rows;
	//	pyramid 2 
	//	    1
	//	   1 2
	//	  1 2 3 
	//	 1 2 3 4
	//	1 2 3 4 5 
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput
		printf("Enter number of rows for making pyramid :");
		scanf("%d",&rows);
		for(int r=1;r<=rows;r++){
			for(int sp=rows-r;sp>=0;sp--){
				printf(" ");
			}
			for(int p=1;p<=r;p++){
			printf("%d ",p);
			}
			printf("\n");
			}
		return 0;
}