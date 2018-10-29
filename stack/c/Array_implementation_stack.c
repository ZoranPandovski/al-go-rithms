/* c program for the array implementation of stack */

#include <stdio.h>
#include <stdlib.h>

#define size 100
int stack[size], top = -1;

void push(int x){

if(top > size-1){

printf("StackOverflow");

}else{
	stack[++top] = x;
	printf("Element inserted:%d \n",x); 
}

}
void pop(){
	if(top < 0){
		printf("StackUnderFlow");
	}
	else{
		printf("Element deleted %d", stack[top]);
		top--;
	}

}
void prints(){
	int i;
	printf("Element of stack are:");
	for(i=0; i<=top;i++){
		printf("%d ",stack[i]);

	}

}

int main(void){


	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
  pop();
	prints();

	return 0;
}
