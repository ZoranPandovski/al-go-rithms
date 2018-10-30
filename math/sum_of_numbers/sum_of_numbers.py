def sum_of_numbers_iterative(n):
    the_sum=0
    for i in range(n):
        the_sum += (i+1)
    return the_sum
print(sum_of_numbers_iterative(5))

#Too high a number give:
#RecursionError: maximum recursion depth exceeded in comparison
