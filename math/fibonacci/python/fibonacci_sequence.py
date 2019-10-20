def fib(n):
    '''
    Returns Fibonacci sequence.
    '''
    
    # Edge cases:
    if n < 0:
        raise ValueError('negative index')
    elif n in [0, 1]:
        return n

    # 0th fibonacci
    prevPrev = 0
    # 1st fibonacci
    prev = 1       

    # nth fibonacci
    for _ in range(n - 1):
        current = prev + prevPrev
        prevPrev = prev
        prev = current

    return current
