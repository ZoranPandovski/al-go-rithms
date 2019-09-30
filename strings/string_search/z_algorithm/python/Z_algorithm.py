#!/bin/python3
import sys, string
from random import *
from timeit import default_timer as timer


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


#res=timefunc( searchKMP, S, P, iterations=rep)
#if(res!=res0): print("Wrong")

def getZ_naive(S):
    N=len(S)
    Z=[0]*N
    for i in range(1,N):
        k=0
        while( i+k<N and S[i+k]==S[k]):
            k+=1
        Z[i]=k
    return Z

#int L = 0, R = 0;
#for (int i = 1; i < n; i++) {
#  if (i > R) {
#    L = R = i;
#    while (R < n && s[R-L] == s[R]) R++;
#    z[i] = R-L; R--;
#  } else {
#    int k = i-L;
#    if (z[k] < R-i+1) z[i] = z[k];
#    else {
#      L = i;
#      while (R < n && s[R-L] == s[R]) R++;
#      z[i] = R-L; R--;
#    }
#  }
#}

def getZ_0(S):
    N=len(S)
    Z=[0]*N
    L,R=0,0
    for i in range(1,N):
        if i>R:
            L=R=i
            while R<N and S[R-L]==S[R]:
                R+=1
            Z[i]=R-L
            R-=1
        else:
            k=i-L
            if Z[k]<R-i+1:
                Z[i]=Z[k]
            else:
                L=i
                while R<N and S[R-L]==S[R]:
                    R+=1
                Z[i]=R-L
                R-=1
    return Z


#from rookie rank 4, dna
#not optimal....
def getZ_1(S):
    N=len(S)
    Z=[0]*N
    L,R=-1,-1
    for i in range(N):
        if i<R:
            Z[i]=min(R-i, Z[i-L])
        while i+Z[i]<N and S[Z[i]]==S[i+Z[i]]:
            Z[i]+=1
        if i+Z[i]>R:
            L=i
            R=i+Z[i]
    Z[0]=0 #due to it=N as result
    return Z

#void z_func(string s){
#    int n = s.length();
#    int z[n];
#    z[0] = 0;
#
#    for (int i = 1, l = 0, r = 1; i < n; i++, r = i < r ? r : i)
#        for (z[i] = min(r - i, z[i - l]); i + z[i]<n && s[i + z[i]] == s[z[i]]; z[i]++, r = i + z[i], l = i);
#
#    for (int i = 0; i < n; i++)
#        cout << z[i] << " ";
#}
def getZ_2(S):
    N=len(S)
    Z=[0]*N
    i=1
    L=0
    R=1
    while i<N:
        Z[i]=min(R-i,Z[i-L])
        while i+Z[i]<N and S[i+Z[i]]==S[Z[i]]:
            Z[i]+=1
            R=i+Z[i]
            L=i
        i+=1
        if i>=R:
            R=i
    return Z


if __name__ == "__main__":
    alpha="AB"
    #alpha=string.ascii_lowercase
    S = randstr(30,alphabet=alpha)
    #S=['A']*10000
    rep=1

    print(S)

    res0=timefunc( getZ_naive, S, iterations=rep)
    print(res0)

    res=timefunc( getZ_0, S, iterations=rep)
    print(res0==res)

    res=timefunc( getZ_1, S, iterations=rep)
    print(res0==res)

    res=timefunc( getZ_2, S, iterations=rep)
    print(res0==res)
