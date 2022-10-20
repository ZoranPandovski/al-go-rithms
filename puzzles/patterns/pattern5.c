#include<stdio.h>
int main(){
	//	pattern 3
		//	0    
		//	01
		//  024
		//	0369
		//	0481216	 	 
		//	r=rows,sp=space,p=pattern,value=1,rows=userinput,c=column
	int rows,p=0;
	printf("Enter the number of rows : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		for(int c=1;c<=rows-1;c++){
			if(c<=r){
			printf("%d ",p*(c-1));
			}
			else 
			printf(" ");
		}
		p=p+1;
		printf("\n");
	}
	return 0;
}