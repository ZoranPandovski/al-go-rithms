#include<stdio.h>
int main(){
	
	//	pyramid 6
	//	    *
	//	   * *
	//	  * * *
	//	 * * * *
	//	* * * * *
	//	r=rows,sp=space,p=pattern,value=1,rows=userinput,c=column

	
	int rows,k;
//	here k is a random variable which is taken for alternative printing by assigning 0 and 1 alternatively
	
	printf("Enter the number of rows for making pyramid : ");
	scanf("%d",&rows);
	for(int r=1;r<=rows;r++){
		
//		type 1 
		
//		for(int sp=1;sp<=rows-r;sp++){
//		printf(" ");
//		}
//		for(int c=1;c<=r;c++){
//		printf("* ");
		
//		type 2
		k=1;
		for(int c=1;c<=2*rows-1;c++){
			if(c>=rows-r+1 && c<=rows+r-1 && k==1){
				printf("*");
				k=0;
			}
			else{
				printf(" ");
				k=1;
			}
		}
	printf("\n");
	}
return 0;
}