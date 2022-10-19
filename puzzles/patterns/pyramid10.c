#include<stdio.h>
int main(){
	
	//	pyramid 5
	//	    *
	//	   ***
	//	  *****
	//	   ***
	//	    *	
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput

	
	int rows,k=0;
	printf("Enter the number of rows for making pyramid (the number must be odd) : ");
	scanf("%d",&rows);
	if(rows%2==0)
	printf("you just entered even number ! :( ");
	else{
	for(int r=1;r<=rows;r++){
		

	r<=(rows+1)/2?k++:k--;

	for(int c=1;c<=(rows+1)/2;c++){
	if(c<=k)
	printf("*");
	else
	printf(" ");
}
		
	printf("\n");
	}
	}
return 0;
}
