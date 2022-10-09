#include<stdio.h>

int XOR_from_1_to_N(int n){
    if(n%4==0)
        return n;
    if(n%4==1)
        return 1;
    if(n%4==2)
        return n+1;
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int ans=XOR_from_1_to_N(n);
    printf("%d",ans);
    return 0;
}

//Time complexity: O(1)
//Space complexity: O(1)
