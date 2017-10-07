class CountingSort:
    def __init__(self,a):
        self.a = a

    def result(self):
        maxSize = max(self.a)
        presence = [0 for x in range(maxSize+1)]
        for element in self.a:
            presence[element] += 1
        for i in range(1,len(presence)):
            presence[i] = presence[i] + presence[i-1]
        b = [0 for x in range(len(self.a))]
        for i in range(len(self.a)-1,-1,-1):
            b[presence[self.a[i]]-1] = self.a[i]
            presence[self.a[i]] -= 1
        self.a = b
        return self.a
