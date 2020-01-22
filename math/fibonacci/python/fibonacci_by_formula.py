import math

# The code below calculates N-th fibonacci number by O(1)
# Such speed is achieved by using the Binet's formula which is
# fib(n) = (phi^n - psi^n) / sqrt(5)
# where
# phi = (1 + sqrt(5)) / 2 and psi = (1 - sqrt(5)) / 2
# But in code we compute fib(n) as
# fib(n) = round(phi^n) / sqrt(5)
# because when n -> inf: abs(psi^n) -> 0
# When n is small this formula is innacurate because
# we are computing in double and float and they aren't the exact values that we have in Math
# Because of the same reasons we may have slightly innacurate values with small n.

def fib(n):
	phi = (1 + math.sqrt(5)) / 2
	return int(round(phi**n / math.sqrt(5)))

n = 50
print(fib(50))
