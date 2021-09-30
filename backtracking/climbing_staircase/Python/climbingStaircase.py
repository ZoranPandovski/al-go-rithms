
def climbingStaircase(n, k):
    output = []
    steps = []
    helper(output, steps, k, n)
    return output
        
def helper(output, steps, k, left):
    if left == 0:
        output.append(list(steps)) # notice hard copy here
    else:
        for i in range(1, k+1):
            if i <= left:
                steps.append(i)
                helper(output, steps, k, left-i)
                steps.pop()
