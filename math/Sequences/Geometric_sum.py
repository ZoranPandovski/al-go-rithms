n = int(input("Enter total numbers : "))
a = int(input("Enter first number : "))
r = int(input("Enter common ratio : "))

prev_term = a
sum_gp = a
for i in range(n):
  ith_term = r * prev_term
  prev_term = ith_term
  sum_gp = sum_gp + ith_term
print("The Sum of GP = " , sum_gp)
