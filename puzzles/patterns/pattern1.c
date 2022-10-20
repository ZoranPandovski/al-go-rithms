#include<stdio.h>
int main(){
	//	pattern 1
		//	*    
		//	* *
		//  * * *    
		//	r=rows,sp=space,p=pattern,value=1,rows=userinput,c=column
	int rows;
	printf("Enter the number of rows : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		for(int c=1;c<=r;c++){
//			here though this is simple pattern ,there is no need to use if else but for further complex pattern it can be useful
//			and for solving this pattern problems use block graph method 
			if(c<=r)
			printf("* ");
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
