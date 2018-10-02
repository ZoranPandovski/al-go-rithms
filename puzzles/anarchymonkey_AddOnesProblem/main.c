    #include <stdio.h>
 /* add 1 to all the numbers and print the numbers with the carry included individualy */
    int main()
    {
      int num,testcases,rem;
      int i = 1;
      scanf("%d",&testcases);
      int result,sum=0,carry = 0,lastDigit = 0,value = 0,temp_sum=0,rem2;
      int multiplier = 1;
      while(testcases--)
      {
        scanf("%d",&num);

        while(num!=0)
        {
            rem =  ( num % 10);
            lastDigit = rem+1+carry;
            carry = 0;
            if(lastDigit>10)
            {
                carry++;
                lastDigit = 0;
            }

            sum = sum + (lastDigit)*multiplier;
            multiplier = multiplier*10; // same as pow(10,i);
             num = num / 10;
        }
        printf("%d\n",sum);
        /* RESET THE VALUES TO THE INITIAL CONDITION */
        sum = 0;
        lastDigit = 0;
        multiplier = 1;
        carry = 0;
        /* **************************************** */
      }
    }
