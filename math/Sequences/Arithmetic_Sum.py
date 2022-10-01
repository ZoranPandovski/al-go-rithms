def Sum(a, n, d):
    total = (n * (2 * a + (n - 1) * d)) / 2
    return total

a = int(input("Enter First Number of an A.P Series: : "))
n = int(input("Enter the Total Numbers in this A.P Series: : "))
d = int(input("Enter the Common Difference : "))

total = Sum(a, n, d)
print("\nThe Sum of Arithmetic Progression Series = " , total)