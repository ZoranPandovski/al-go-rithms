#include<stdio.h>
int main(){
	//	pattern 4
		//	***    
		//	**
		//  * 
		//	r=rows,sp=space,p=pattern,value=1,rows=userinput,c=column
	int rows;
	printf("Enter the number of rows : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		for(int c=1;c<=rows;c++){
			if(c<=rows-r+1)
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}