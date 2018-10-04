This Function will return the absolute value of the given integer .

The implementation of this function is based on the bit manupilation of the given integer... So lets see how it works:

First : we create an integer and we will call it "sign", the value of this integer is ZERO if the input number "x" is positive and is NEGATIVE ONE if the value of the input integer "x" is negative.
How we are assigning a value to "sign" is simple, we will keep shifting right all the bits in the input integer "x", so for an input of type integer (32 bits) we will shift to the right 31 times so for example :
If the input "x" is equal to 5 ... the binary representation of 5 as a 32 bit signed integer is:
  
    00000000 00000000 00000011 10010001 
       
By shifting to the left 31 times we will get an integer of value = 0 :

    00000000 00000000 00000000 00000000
    
The same for a negative number, for example if the input is -199, the binary represenation will be as follows : 

    11111111 11111111 11111111 00111001

By shifting to the left 31 times we will get an integer of value = -1 : 

    11111111 11111111 11111111 11111111
    
Second : we will add this integer "sign" to our input integer "x", in the case of -199 as the input "x" :

    11111111 11111111 11111111 00111001
    11111111 11111111 11111111 11111111
    ____________________________________
    
    11111111 11111111 11111111 00111000
    
Third : we will xor the result of step number two with the integer "sign" which will give us +199 as the end result:

    11111111 11111111 11111111 00111000
    11111111 11111111 11111111 11111111
    ____________________________________
    
    00000000 00000000 00000000 11000111
    
For a positive integer "x" we will follow the same procedure except for the value of the integer "sign" which will be 0.
    
VOILA ... There you have it the absolute value of any integer without the use of the built in function "abs()" or the use of any if statements.
