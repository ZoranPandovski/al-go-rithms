#python code to find the hypotenuse of trinagle

from math import sqrt

print("Enter lengths of the shorter triangle sides - ")

side1 = float(input("side1 : "))
side2 = float(input("side2 : "))
hype = sqrt(side1**2 + side2**2)

print("Length of Hypotenuse : ", hype)
