

size = int(input("Enter the size of the elements")) #the size for the matrix
array_input = []
for x in range(size):
    array_input.append([int(y) for y in input().split()])
print(array_input)
