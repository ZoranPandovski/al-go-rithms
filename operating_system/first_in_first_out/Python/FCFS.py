''' 
Author - Ronak Vadhaiya
FCFS
'''
import math


def FCFS(n_process, data):
    ttr, ttw = 0, 0
    print("="*20 + "FCFS" + "="*20)
    tr = data[0][1]
    wt = 0
    ttr += tr
    prev = data[0][0] + data[0][1]
    print("P1", "Start Time: ", data[0][0], "End Time: ",
          data[0][0]+data[0][1], "TR : ", tr, "WT : ", wt)
    for i in range(1, n_process):
        process_name = "P"+str(i+1)
        if data[i][0] >= prev:
            start_time = data[i][0]
            end_time = data[i][0] + data[i][1]
        else:
            start_time = prev
            end_time = prev + data[i][1]
        tr = end_time - data[i][0]
        wt = start_time - data[i][0]
        ttr += tr
        ttw += wt
        print(process_name, "Start Time: ", start_time,
              "End Time: ", end_time, "TR : ", tr, "WT : ", wt)
        prev = end_time
    print("Average TR: ", ttr/float(n_process))
    print("Average TW: ", ttw/float(n_process))


if __name__ == "__main__":

    data = []

    n_process = int(input("Number of Process: "))

    for _ in range(n_process):
        arrival_time, service_time, priority = map(
            int, input("Arrival | Service | Priority").split())
        data.append([arrival_time, service_time, priority])

    # sort by arrival time
    data.sort()
    FCFS(n_process, data)
