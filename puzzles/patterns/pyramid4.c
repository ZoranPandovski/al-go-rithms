#include<stdio.h>
int main(){
	int rows,pattern=1;
	//	pyramid 4
	//	    1
	//	   2 3
	//	  4 5 6 
	//	 7 8 9 10 
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput
 	// this programme is suitable only for upto 4 row ! then after pyramid obtained will not proper 	
		printf("Enter number of rows for making pyramid :");
		scanf("%d",&rows);
		for(int r=1;r<=rows;r++){
			for(int sp=rows-r;sp>=0;sp--){
				printf(" ");
			}
			for(int p=1;p<=r;p++){
			printf("%d ",pattern);
			pattern=pattern+1;
			}
			printf("\n");
			}
		return 0;
}