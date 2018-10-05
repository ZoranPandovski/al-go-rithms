#!/bin/python3
import sys, string, re
from random import *
from timeit import default_timer as timer
from collections import *

def randstr(N,alphabet=string.ascii_lowercase):
    l=len(alphabet)
    return "".join( alphabet[randint(0,l-1)] for _ in range(N))

def timefunc(func, *args, **kwargs):
    """Time a function. 
    args:
        iterations=1
    Usage example:
        timeit(myfunc, 1, b=2)
    """
    try:
        iterations = kwargs.pop('iterations')
    except KeyError:
        iterations = 1
    elapsed = sys.maxsize
    start = timer()
    for _ in range(iterations):
        result = func(*args, **kwargs)
    elapsed = (timer() - start)/iterations

    print(('{}() : {:.9f}'.format(func.__name__, elapsed)))
    return result

# Python program for Naive Pattern Searching
def searchNaive(txt,pat):
    M = len(pat)
    N = len(txt)
    res=[]
    # A loop to slide pat[] one by one
    for i in range(N-M + 1):
        # For current index i, check for pattern match
        if txt[i:i+M] == pat:
            res.append(i)
    return res

def searchRE(txt,pat):
    M = len(pat)
    N = len(txt)
    res=[m.start() for m in re.finditer('(?=%s)'%(pat), txt)]
    return res


#https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
#lps[i] could also be defined as longest prefix which is also proper suffix.
def computeLPSArray(pat):
    M = len(pat)
    lenp = 0 # lenpgth of the previous longest prefix suffix
    
    lps=[0]*M # lps[0] is always 0
    i = 1
 
    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]==pat[lenp]:
            lenp += 1
            lps[i] = lenp
            i += 1
        else:
            # This is tricky. Consider the example.
            # AAACAAAA and i = 7. The idea is similar 
            # to search step.
            if lenp != 0:
                lenp = lps[lenp-1]
                 # Also, note that we do not increment i here
            else:
#                lps[i] = 0
                i += 1
    return lps

def searchKMP(txt,pat):
    M = len(pat)
    N = len(txt)
    res=[]

    # create lps[] that will hold the longest prefix suffix 
    # values for pattern
    j = 0 # index for pat[]
 
    # Preprocess the pattern (calculate lps[] array)
    lps = computeLPSArray(pat)
 
    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
 
        if j == M:
            res.append(i-j)
            j = lps[j-1]
 
        # mismatch after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    return res

def computeLPSmod(pat):
    M = len(pat)
    lenp = 0 # lenpgth of the previous longest prefix suffix
    
    lps=[0]*M # lps[0] is always 0
    i = 1
    mem=defaultdict(int)

    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]==pat[lenp]:
            lenp += 1
            lps[i] = lenp
            mem[pat[i]] = lenp
            i += 1
        else:
            if lenp != 0:
                #lenp = lps[lenp-1]
                lenp=mem[ pat[i] ]
                i+=1
            else:
#                lps[i] = 0
                i += 1
    return lps

def searchKMPmod(txt,pat):
    M = len(pat)
    N = len(txt)
    res=[]

    # create lps[] that will hold the longest prefix suffix 
    # values for pattern
    j = 0 # index for pat[]
 
    # Preprocess the pattern (calculate lps[] array)
    lps = computeLPSmod(pat)
 
    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
 
        if j == M:
            res.append(i-j)
            j = lps[j-1]
 
        # mismatch after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    return res
if __name__ == "__main__":
    alpha="abc"
    #alpha=string.ascii_lowercase
    #S="AABAABACAADAABAAABAA"
    #P="AAB"
    S=randstr(1000000,alphabet=alpha)
    P=randstr(10,alphabet=alpha)
    rep=1

    print("Len S={}, len P={}, iters={}".format(len(S),len(P),rep))
    res0=timefunc( searchNaive, S, P, iterations=rep)
    print("Found:",len(res0))

    res=timefunc( searchRE, S, P, iterations=rep)
    if(res!=res0): print("Wrong")

    res=timefunc( searchKMP, S, P, iterations=rep)
    if(res!=res0): print("Wrong")

    res=timefunc( searchKMPmod, S, P, iterations=rep)
    if(res!=res0): print("Wrong")

    #print(S)
    #print(P)