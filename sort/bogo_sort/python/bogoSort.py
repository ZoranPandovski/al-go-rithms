
from random import shuffle

testAr = [1,3,4,5,2,7,6,9,8]
flag = False
count = 0


while not flag:
    count += 1
    for i in range(len(testAr)):
        if i == len(testAr) - 1:
            flag = True
            print("success", testAr, "run number: ", count)
            break
        if testAr[i] > testAr[i+1]:
            shuffle(testAr)
            print("failure", testAr, "run number: ", count)
            break

