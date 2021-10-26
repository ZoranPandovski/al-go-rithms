#include <stdio.h>

int set_kth_bit(int num, int k){
	/* Left shift 1, n times and perform bitwise OR with num */
	return (1 << k) | num;
}

int main()
{
    int num, k, newNum;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to set */
    printf("Enter nth bit to set: ");
    scanf("%d", &k);

    newNum =  set_kth_bit(num, k);

    printf("Number before setting %d bit: %d (in decimal)\n", k, num);
    printf("Number after setting %d bit: %d (in decimal)\n",  k, newNum);

    return 0;
}
