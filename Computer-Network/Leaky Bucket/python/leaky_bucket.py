'''
sample input1: 

avg_arrival_rate=100
bucket_capacity=150
avg_transmission_rate=90
maximum_data=1000 

sample input2:
avg_arrival_rate=100
bucket_capacity=150
avg_transmission_rate=90
maximum_data=100
'''

import random
import numpy as np

def possion_distribution(x):
    ex=np.exp(-x)
    num=0
    p=1
    while(1):
        p=p*random.random()
        num+=1
        if(p<ex):
            break
    return(num)

avg_arrival_rate=int(input("Enter the Avrage arrival rate : "))
bucket_capacity=int(input("Enter Bucket Capacity : "))
avg_transmission_rate=int(input("Enter the Avrage Transmission rate : "))
maximum_data=int(input("Enter the maximum data : "))
x=0
y=maximum_data
filed_bucket=0
i=1

while(maximum_data>=0):
    new_packet=possion_distribution(avg_arrival_rate)
    filed_bucket=filed_bucket+new_packet
    if(maximum_data>avg_transmission_rate):
        print(f"\n\n*** After {i} Sec ****\n")
        i+=1
        print(f"new tokens Genrated(arrival) : {new_packet}")
        if(filed_bucket<=bucket_capacity):
            if(filed_bucket-avg_transmission_rate>=0):
                filed_bucket-=avg_transmission_rate
                x=x+avg_transmission_rate
            else:
                x+=filed_bucket
                filed_bucket=0
            print(f"Packet in Buffer storage : {filed_bucket}")
        else:
            x=x+(filed_bucket-bucket_capacity)+avg_transmission_rate
            print(f"Lost token :",(filed_bucket-bucket_capacity))
            filed_bucket=bucket_capacity
            filed_bucket-=avg_transmission_rate
            print(f"Buffer storage : {filed_bucket}")
    maximum_data=maximum_data-new_packet

print(f"\n\n*** After {i} Sec ****\n")
if(filed_bucket>bucket_capacity):
    print(f"Lost token :",(filed_bucket-bucket_capacity))
    filed_bucket=bucket_capacity
print(f"new tokens Genrated(arrival) : {new_packet}")
print(f"Packet in Buffer storage : {(filed_bucket+x)-y}")

