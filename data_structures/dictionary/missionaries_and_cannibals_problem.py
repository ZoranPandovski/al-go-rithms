shore = {1:['m1','m2','m3','c1','c2','c3'],2:[]}
boat = {1:True,2:False}
boat_cap = 0
boat_hold = []
choice = 'y'
count = 0
glob = 1
def pick():
    print("Pick a person to put on boat/or press enter")
    return input()
def check(person,flag,avail_p):
    if(person in shore[flag] or person == "" or person in boat_hold):
        return True
    else:
        return False
def check_conditions(shore,flag,cflag,boatf):
    num_m = 0
    num_c = 0
    true = 0
    for i in shore[flag]:
        if(i[0] == 'm'):
            num_m = num_m + 1
        else:
            num_c = num_c + 1
    if(num_m < num_c and num_m > 0):
        return False
    else:
        true = 1
    num_m = 0
    num_c = 0
    for i in shore[cflag]+boatf:
        if(i[0] == 'm'):
            num_m = num_m + 1
        else:
            num_c = num_c + 1
    if(num_m < num_c and num_m > 0):
        return False
    elif(true == 1):
        return true
while(choice == 'Y' or choice == 'y'):
    count = 0
    win = 0
    while(count <= 25):
        def again(shore,boat_hold):
            print("People On Shore "+str(flag)+ " are: ")
            print()
            print(shore[flag] + boat_hold)
            shore[flag] = shore[flag] + boat_hold
            avail_p = shore[flag] + boat_hold
            boat_hold =[]
            for i in range(2):
                print("For Person " + str(i+1))
                print()
                person = pick()
                if(i == 0 and person == ""):
                    while(person == ""):
                        print("Boat Cannot Be Empty")
                        person = pick()
                if((not person == "") and person in avail_p):
                    boat_hold.append(person)
                    del avail_p[avail_p.index(person)]
                    del shore[flag][shore[flag].index(person)]
                elif(person not in avail_p and not person == ""):
                    print("Invalid Choice")
                    person = pick()
                    while(not check(person,flag,avail_p)):
                        person = pick()
                if(person == ""):
                    break
                glob = 0
            return boat_hold
        if(boat[1]):
            flag = 1
            cflag = 2
        else:
            flag = 2
            cflag = 1
        if(glob == 1):
            boat_hold = again(shore,boat_hold)
        while(not check_conditions(shore,flag,cflag,boat_hold)):
            print()
            print("** Invalid Move,Try Again **")
            print()
            boat_hold = again(shore,boat_hold)
        print("Sending Boat")
        print()
        avail_p = shore[cflag] + boat_hold
        boat[cflag] = True
        boat[flag] = False
        glob = 1
        if(len(shore[1]) == 0):
            win = 1
            print("Congratulation, You Solved The Problem.")
            break
        count = count + 1
    if(win == 0):
        print()
        print("*** Sorry, Number of moves exceeeded ***")
    print()
    print("Do You Want To Replay? Y/N",end=" ")
    choice = input()
    
    
