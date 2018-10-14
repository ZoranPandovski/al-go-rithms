base= input("Enter base of the pattern")

n = input("For first term, enter power of base ( like 2^x  x=? )")

n2 = input("How many steps to go?")


ary = []

for x in range(n2):
    ary.append(pow(base,n+x))





print ary
