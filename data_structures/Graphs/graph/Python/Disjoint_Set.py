class Disjoint:
    def __init__(self):
        self.parent=None
        self.rank=0
        self.element=None
        self.e=[]
class Set:
    def __init__(self):
        #self.repre=Disjoint()
        self.repre=None
    def makset(self,x,data):
        self.repre=x
        x.parent=x
        x.rank=0
        x.element=data
    def findset1(self,x):
        if x.parent==x:
            return x
        return self.findset1(x.parent)
    def findset(self,x):
        if x.parent==x:
            return x
        x.parent=self.findset(x.parent)
        return x.parent
    def Union(self,x,y):
        rx=self.findset(x)
        ry=self.findset(y)
        if rx.rank>ry.rank:
            ry.parent=rx
            rx.e.append(ry.element)
        elif rx.rank<ry.rank:
            rx.parent=ry
            ry.e.append(rx.element)
        else:
            ry.e.append(rx.element)
            rx.parent=ry
            ry.rank+=1
def main():
    '''x=Disjoint()
    x.element=1
    y=Disjoint()
    y.element=2
    s=Set()
    s.makset(x,1)
    s.makset(y,2)
    print((s.findset(x)).element)
    s.Union(x,y)
    print((s.findset(x)).element)
    print((s.findset(y)).element)'''
    print("Enter the total no of nodes:")
    n=int(input())
    print("Enter no of edges:")
    e=int(input())
    arr=[Disjoint() for i in range(n)]
    s=Set()
    for i in range(n):
        s.makset(arr[i],i)
    i=0
    while i<e:
        print("enter edges:")
        x,y=map(int,input().split())
        if x<n and y<n:
            s.Union(arr[x],arr[y])
            i+=1
        else:
            print("Invalid edge:")
            i-=1
    for i in range(n):
        print(arr[i].rank)

if __name__ == '__main__':
    main()
