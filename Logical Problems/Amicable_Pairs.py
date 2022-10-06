num1 = int(input(""))
num2 = int(input(""))

def sum_of_proper_divisors(a):
    add = 0
    for i in range(1, a):
        if a % i == 0:
            add += i
    return add

amicable_pair_list = []
for i in range(num1, num2, 1):
    num = sum_of_proper_divisors(i)
    if num > i:
        if sum_of_proper_divisors(num) == i:
            amicable_pairs = (i, num)
            amicable_pair_list.append(amicable_pairs)
print(amicable_pair_list)
