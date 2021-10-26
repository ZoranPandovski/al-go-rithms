# encoding utf-8

def triangle_checker(a, b, c):
    return a + b > c and a + c > b and b + c > a


print(triangle_checker(3, 3, 3))
print(triangle_checker(3, 4, 5))
print(triangle_checker(6, 9, 15))