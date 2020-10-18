print("Enter the number of process: ")
n = int(input())

Allocation = []
Max = []
Need = []

# take inputs of Allocation
print('Allocation Matrix')
for i in range(n):
    theinputs = []
    for j in range(3):
        x = int(input())
        theinputs.append(x)
    Allocation.append(theinputs)

# take inputs of Max
print('Claim Matrix')
for i in range(n):
    theinputs = []
    for j in range(3):
        x = int(input())
        theinputs.append(x)
    Max.append(theinputs)

# find the Need

for i in range(n):
    theinputs = []
    for j in range(3):
        x = Max[i][j] - Allocation[i][j]
        theinputs.append(x)
    Need.append(theinputs)

# print(Need)

# take input of A,B,C at t0 time
print('Enter Resources:')
A = int(input())
B = int(input())
C = int(input())
# getting Available at t0 time

Available = []

x = 0
for i in range(n):
    x += Allocation[i][0]
x = A - x
Available.append(x)

x = 0
for i in range(n):
    x += Allocation[i][1]
x = B - x
Available.append(x)

x = 0
for i in range(n):
    x += Allocation[i][2]
x = C - x
Available.append(x)

# print(Available)

Work = Available

# take input for request
print('Initial Available Vector')
request = []
for i in range(3):
    x = int(input())
    request.append(x)

# All finish is Zero at the initial

Finish = []
for i in range(n):
    Finish.append(0)


Sequence = []

for i in range(n):
    for j in range(n):
        if(Finish[j] == 0):
            if(Need[j][0] <= Work[0] and Need[j][1] <= Work[1] and Need[j][2] <= Work[2]):
                Work[0] += Allocation[j][0]
                Work[1] += Allocation[j][1]
                Work[2] += Allocation[j][2]
                Finish[j] = 1
                Sequence.append(j+1)
                print("Process", j+1, "executed")
                print('Available Matrix: ', Work)

# print(Finish)

tag = 0

for i in range(n):
    if(Finish[i] == 0):
        tag = 1
        break

if(tag == 0):
    print("Granted!")
    print("The Process Sequence: ")
    print(Sequence)
else:
    print("Deadlock in the System!!!")
