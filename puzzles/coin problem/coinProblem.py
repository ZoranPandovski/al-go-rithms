
# Python 3 program to find
# minimum number of steps
# to collect stack of coins

# recursive method to collect
# coins from height array l to
# r, with height h already
# collected
def minStepsRecur(height, l, r, h):

    # if l is more than r,
    # no steps needed
    if l >= r:
        return 0;

    # loop over heights to
    # get minimum height index
    m = l
    for i in range(l, r):
        if height[i] < height[m]:
            m = i

    # choose minimum from,
    # 1) collecting coins using
    # all vertical lines (total r - l)
    # 2) collecting coins using
    # lower horizontal lines and
    # recursively on left and
    # right segments
    return min(r - l,
            minStepsRecur(height, l, m, height[m]) +
            minStepsRecur(height, m + 1, r, height[m]) +
            height[m] - h)

# method returns minimum number
# of step to collect coin from
# stack, with height in height[] array
def minSteps(height, N):
    return minStepsRecur(height, 0, N, 0) 
