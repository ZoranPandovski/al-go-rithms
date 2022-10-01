''' 
Author - Ronak Vadhaiya
Shortest Remaining Time First
'''


def srt(n_process, data):
    print("="*20 + "Shortest remaining time First"+"="*20)
    ind = 0
    start = data[0][0]
    total_service = sum([x[1] for x in data])
    vis = [0]*(n_process)
    ss = [i[1] for i in data]
    tr = dict()
    wt = dict()
    for i in range(100):
        print("P"+str(ind+1), start, start+1)
        start += 1
        data[ind][1] -= 1
        if not data[ind][1]:
            vis[ind] = 1
            tr[ind+1] = start - data[ind][0]
            wt[ind+1] = tr[ind+1] - ss[ind]
        queue = []
        for j in range(n_process):
            if data[j][0] <= start:
                if not vis[j]:
                    queue.append((data[j][1], j))
        queue.sort()
        if not queue:
            break
        ind = queue[0][1]
    ttr, twt = 0, 0
    for i in range(1, n_process+1):
        print("P"+str(i), "TR : ", tr[i], "WT : ", wt[i])
        ttr += tr[i]
        twt += wt[i]
    print("Average TR: ", ttr/float(n_process))
    print("Average TW: ", twt/float(n_process))


if __name__ == "__main__":

    data = []

    n_process = int(input("Number of Process: "))

    for _ in range(n_process):
        arrival_time, service_time, priority = map(
            int, input("Arrival | Service | Priority").split())
        data.append([arrival_time, service_time, priority])

    # sort by arrival time
    data.sort()
    srt(n_process, data)
