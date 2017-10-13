def fib(n):  # return Fibonacci series up to n from: https://docs.python.org/2/tutorial/controlflow.html
    """Return a list containing the Fibonacci series up to n."""
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result
