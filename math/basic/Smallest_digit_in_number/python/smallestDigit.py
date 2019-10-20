'''
Problem: To find the smallest digit in a number.
Author: Aayush Bisen
Date: 02-11-18 07:33
'''


number = int(input("Enter a number: "))
l1 = [int(i) for i in str(number)]
l1.sort()
print(l1[0],"is the smallest digit in the number.")