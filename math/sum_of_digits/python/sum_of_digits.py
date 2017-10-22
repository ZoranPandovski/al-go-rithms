def sum_of_digits(n):
    sum = 0;
    for i in str(n):
        sum += int(i)

    return sum

print sum_of_digits(3)  #3
print sum_of_digits(3454332) #24
