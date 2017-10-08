class RadixSort:
    def __init__(self,a):
        self.a = a

    def result(self):
        maxElement = max(self.a)
        exp = 1
        while int(maxElement/exp) > 0:
            self.countingsort(exp)
            exp *= 10
        return self.a

    def countingsort(self,exp):
        position = [0]*(10)
        b = [0]*(len(self.a))
        for i in range(len(self.a)):
            index = int(self.a[i]/exp)
            position[index%10] += 1
        for i in range(1,10):
            position[i] += position[i-1]
        for i in range(len(self.a)-1,-1,-1):
            index = int(self.a[i]/exp)
            b[position[index%10]-1] = self.a[i]
            position[index%10] -= 1
        self.a = b
