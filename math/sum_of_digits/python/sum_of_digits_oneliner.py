import sys

def sum_of_digits(n):
    return sum(int(x) for x in list(str(n)))

if __name__ == '__main__':
    print(sum_of_digits(sys.argv[1]))
