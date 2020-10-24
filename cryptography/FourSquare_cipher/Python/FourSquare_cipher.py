from __future__ import print_function
def Divider(inp):      #generates the string in the necessary format
    inp=inp.upper()
    str=""
    for i in inp:
        if i==' ':
            continue
        else:
            str+=i
    if len(str)%2==1:
        str+='X'
    return str

def Key(key):      #key generator according to two input keys
    key=key.upper()
    fin=[]
    store=[chr(x) for x in range(65,91)]
    for i in key:
        if i in store:
            fin.append(i)
            store.remove(i)

    for i in store:
        if not i=='J':
            fin.append(i)
    
    store=[fin[i: i+5] for i in range(0,(len(fin)),5)]

    return store

def index2D(lst,val):
    for i in range(len(lst)):
        if lst[i]==val:
            return i

def Foursquare():
    output=""
    Inp=input()
    Inp=Divider(Inp)

    temp11=[chr(x) for x in range(65,91) if not chr(x)=='J']
    temp22=[chr(x) for x in range(65,91) if not chr(x)=='J']

    
    block11=[temp11[i: i+5] for i in range(0,(len(temp11)-5),5)]
    block22=[temp22[i: i+5] for i in range(0,(len(temp22)-5),5)]

    key1=input()
    key2=input()
    block12=Key(key1)
    block21=Key(key2)
    
    for i in range(0,len(Inp)-1,2):
        getx1=index2D(temp11,Inp[i])/5
        gety1=index2D(temp11,Inp[i])%5

        getx2=index2D(temp22,Inp[i+1])/5
        gety2=index2D(temp22,Inp[i+1])%5
    
        output=output+block12[getx1][gety2]+block21[getx2][gety1]
    print(output)

Foursquare();
