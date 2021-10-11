def needmatrix(need,maximum,allocated):
	for i in range(len(processes)):
		for j in range(R):
			need[i][j] = maximum[i][j] - allocated[i][j]


def safestate(processes,available,maximum,allocated):
	need = [[0 for j in range(R)] for i in range(len(processes))]
	needmatrix(need,maximum,allocated)
	finish = [0 for i in range(len(processes))]
	s_sequence = [0 for i in range(len(processes))]
	work = [i for i in available]

	count = 0
	while(count<len(processes)):
		found = False
		for p in range(len(processes)):
			if(finish[p]==0):
				executing = True
				for j in range(R):
					if(need[p][j]>work[j]):
						executing = False
						break
				if(j==R-1 and executing):
					for k in range(R):
						work[k] += allocated[p][k]
					s_sequence[count] = p
					count +=1
					finish[p] =1
					found = True

		if(found==False):
			print("System is not is safestate\n")
			return False
			exit()
	print("<<<<<<System is in safe state>>>>>>\n")
	print(f"<<<<<Safe Sequence: {s_sequence}>>>>>>")



# # available instances of resources
# available = [2,1,3]
# # maximum resources needed by processes
# maximum = [
# 	[3,5,3],
# 	[3,2,2],
# 	[4,0,2],
# 	[2,2,2],
# 	[4,3,3]
# ]
# # resources allocated to processes
# allocated = [
# 	[0,1,0],
# 	[2,0,0],
# 	[3,0,2],
# 	[2,1,1],
# 	[0,2,2]
# ]

P = int(input("Give number of processes -> "))
R = int(input("Give number of resources -> "))
processes = [i for i in range(P)]
max_r = [int(i) for i in input("Give the maximum available for each resources ->").split()]

print("\nGive the already allocated resources for each process")
allocated = [[int(i) for i in input(f"Process <{j}> -> ").split()] for j in range(P)]

print("\nGive the maximum resources for each process")
maximum = [[int(i) for i in input(f"Process <{j}> : ").split()] for j in range(P)]
tallocated = [0] * R
for i in range(P):
    for j in range(R):
        tallocated[j] += allocated[i][j]
print(f"\ntotal allocated resources : {tallocated}")
available = [max_r[i] - tallocated[i] for i in range(R)]
for num in available: 
    if num < 0:
        print("The allocation is more than the given number of resources")
        exit(0)
print(f"total available resources : {available}\n")
safestate(processes,available,maximum,allocated)
# P, R = 3,1

# def needmatrix(need,maximum,allocated):
# 	for i in range(len(processes)):
# 		for j in range(R):
# 			need[i][j] = maximum[i][j] - allocated[i][j]

# def safestate(processes,available,maximum,allocated):
# 	need = [[0 for j in range(R)] for i in range(len(processes))]
# 	needmatrix(need,maximum,allocated)
# 	finish = [0 for i in range(len(processes))]
# 	s_sequence = [0 for i in range(len(processes))]
# 	work = [i for i in available]

# 	count = 0
# 	while(count<len(processes)):
# 		found = False
# 		for p in range(len(processes)):
# 			if(finish[p]==0):
# 				for j in range(R):
# 					if(need[p][j]>work[j]):
# 						break
# 				if(j==R-1):
# 					for k in range(R):
# 						work[k] += allocated[p][k]
# 					s_sequence[count] = p
# 					count +=1
# 					finish[p] =1
# 					found = True

# 		if(found==False):
# 			print("System is not is safestate\n")
# 			return False
# 			exit()
# 	print("System is in safestate\n")
# 	print(f"Safe Sequence: {s_sequence}")

# processes = [i for i in range(P)]

# # available instances of resources
# available = [2]
# # maximum resources needed by processes
# maximum = [
# 	[10],
# 	[4],
# 	[9],

# ]
# # resources allocated to processes
# allocated = [
# 	[5],
# 	[2],
# 	[3],

# ]


# safestate(processes,available,maximum,allocated)
# while(1):
# 	x = input("Add another process (y/n): ")
# 	if(x=='y'):
# 		t = int(input("Enter pid: "))
# 		processes += [t]
# 		maxm = list(map(int,input("Enter maximum resources needed: ").split(',')))
# 		allo = list(map(int,input("Enter allocated resources: ").split(',')))
# 		maximum.append(maxm)
# 		allocated.append(allo)
# 		safestate(processes,available,maximum,allocated)
# 	else:
# 		break
