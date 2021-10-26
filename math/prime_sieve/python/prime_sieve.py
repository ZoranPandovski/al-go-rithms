from __future__ import print_function
limit = int(input("enter limit: "))
for prime in range(2, limit + 1):
        if all(prime % i != 0 for i in range(2, prime)):
                print(prime)
