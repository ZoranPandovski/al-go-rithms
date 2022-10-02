#!/bin/python3

import os
import sys

def timeConversion(s):
    if(s[8]=='P'):
        if(int(s[0:2])==12):
            return s[0:8]
        else:
            t=int(s[0:2])+12
            return str(t)+s[2:8] 
    if(s[8]=='A'):
        if(int(s[0:2])==12):
            t='00'
            return str(t)+s[2:8]
        else:
            return s[0:8]

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = timeConversion(s)
    f.write(result + '\n')
    f.close()
"""
Input
07:05:45PM

Your Output
19:05:45

"""
