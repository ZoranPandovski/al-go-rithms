def trap(heights):
    totalWater = 0
    stack = []

    for i in range(len(heights)):
        while len(stack) > 0 and heights[i] > heights[stack[-1]]:
            topIndex = stack.pop()
            if len(stack) == 0:
                break
            prevIndex = stack[-1]
            distance = i - prevIndex - 1
            trappedWater = distance * (min(heights[i], heights[prevIndex]) - heights[topIndex])
            totalWater += trappedWater
        stack.append(i)

    return totalWater
heights = [0,1,0,2,1,0,1,3,2,1,2,1]
print(trap(heights))

