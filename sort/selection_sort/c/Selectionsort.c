//selection sorting in C Programming
//This is beginner friendly selection sorting as it has just a simple for loop used
#include<stdio.h>
#include<stdlib.h>

int i,n;

void input();//function prototype
void display(int b[20]);//function prototype
void sorting(int c[20]);//function prototype

int main(){
    input();
    return 0;
}

void input(){
    int a[20];
    printf("Enter the total numbers you want to enter\t");
    scanf("%d",&n);
    printf("Enter the numbers you want to enter\t");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The entered numbers are:\n");
    display(a);
    sorting(a);
}

void display(int b[20]){
    for(i=0;i<n;i++){
        printf("%d\t",b[i]);
    }
}

void sorting(int c[20]){
    int j,temp;
    //selection sorting algorithm for ascending order
    for(i=0;i<(n-1);i++){
        for(j=i+1;j<n;j++){
            if(c[i]>c[j]){
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }//if-close
        }//j loop
    }//i loop
    printf("\nThe result after sorting in ascending order is:\n");
    display(c);

    //selection sorting algorithm for descending order
    for(i=0;i<(n-1);i++){
        for(j=i+1;j<n;j++){
            if(c[i]<c[j]){
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }//if-close
        }//j loop
    }//i loop
    printf("\nThe result after sorting in descending order is:\n");
    display(c);
}




