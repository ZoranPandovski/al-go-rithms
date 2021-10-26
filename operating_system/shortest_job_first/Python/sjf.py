''' 
Author - Ronak Vadhaiya @ Rac-Ro007
SJF (Shortest Job First) -> SPN
'''
import math


def sjf_spn(n_process, data):
  print("="*20 + "SPN" + "="*20)
  ttr,ttw,tnt = 0,0,0
  queue = [] 
  start = data[0][0]
  total_service = sum([x[1] for x in data])
  vis = [0]*(n_process)
  for i in range(n_process):
    for j in range(i,n_process):
      if data[j][0] <= start: 
        if not vis[j]:
          queue.append((data[j][1],j))
          vis[j] = 1
    queue.sort()
    ind = queue[0][1]
    del queue[0]
    if data[ind][0] >= start :
      start_time = data[ind][0] 
      end_time = data[ind][0] +  data[ind][1]
    else:  
      start_time = start
      end_time = start + data[ind][1]
    process_name = "P"+str(ind+1)
    tr = end_time - data[ind][0]
    wt = start_time - data[ind][0]
    nt = tr / data[ind][1]
    ttr += tr  
    ttw += wt 
    tnt += nt 
    print(process_name,"Start Time: ",start_time,"End Time: ",end_time, "TR : ",tr, "WT : ",wt ,"NT: ",nt)
    start += end_time
  print("Average TR: ",ttr/float(n_process))
  print("Average TW: ",ttw/float(n_process))
  print("Average NT: ",tnt/float(n_process))

if __name__ == "__main__":

    data = []

    n_process = int(input("Number of Process: "))

    for _ in range(n_process):
        arrival_time, service_time, priority = map(
            int, input("Arrival | Service | Priority").split())
        data.append([arrival_time, service_time, priority])

    # sort by arrival time
    data.sort()
    sjf_spn(n_process, data)
