doors = [False]*100

for i in range(0,100):
    j = i
    while j < 100:
        doors[j] = not doors[j]
        j += i + 1

for door in range(0,100):
    if doors[door]:
        print("Door "+ str(door+1) + " is open.")

