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
		
//		type 1 
		//we can also do this by introducing a new variable k which increases upto half pyramd and then decreases
r<=(rows+1)/2?k++:k--;

for(int c=1;c<=rows;c++){
	if(c>=(rows+1)/2-k+1 && c<=(rows+1)/2+k-1)
	printf("*");
	else
	printf(" ");
}
		
//		type 2
//		for(int c=1;c<=rows;c++){
//			if(r<=(rows+1)/2){
//			if(c>=(rows+1)/2-r+1 && c<=(rows+1)/2+r-1)
//			printf("*");
//			else
//			printf(" ");
//			}
//			else{
//				if(c>=r-(rows+1)/2+1 && c<=rows-(r-(rows+1)/2)){
//					printf("*");
//				}
//				else
//				printf(" ");
//			}
			
//	}
	printf("\n");
	}
	}
return 0;
}

