"""
Input 1:7
Output 1:3

Explaination:
Binary representation of of 7 is "111" and number of set bits(ones) is 3.


Input 1:23
Output 1:4

Explain:
Binary representation of of 7 is "10111" and number of set bits(ones) is 4. 

"""

num=7
count=(bin(num)[2::]).count('1')
print(count)