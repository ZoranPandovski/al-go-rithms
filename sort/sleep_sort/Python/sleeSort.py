#!/usr/bin/env python3

import time
import threading

def sleep(i):
    time.sleep(i)
    print(i)

def sleepSort(v):
    for i in range(len(v)):
        newThread = threading.Thread(target=sleep, args=(v[i],))
        newThread.start()

    return None

def main():
    v = [5,2,6,1,4,3]
    sleepSort(v);

if __name__ == "__main__":
    main()
