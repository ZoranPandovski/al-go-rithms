def climbingStaircase(n, k):
    if n == 0:
        return [[]]
    stair = [1] * n
    return findPossible(stair, k)
    
def findPossible(stair, k):
    if len(stair) == 0:
        return [[]]
    if len(stair) == 1:
        return [[1]]
    if len(stair) < k:
        return findPossible(stair, len(stair))
    
    solutions = []
    for i in range(1,k+1):
        results = findPossible(stair[i::],k)
        print(results)
        for result in results:
            solutions.append([i]+result)
    return solutions
