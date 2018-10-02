class DisjointSet:
    disjoint = []
    ranking = []

    def __init__(self, n):
        '''
        Initialises a disjoint set of length `n`, starting
        from elements number 0 to number n-1
        '''
        for i in range(n):
            self.disjoint.append(i)
            self.ranking.append(0)


    def disjoint_find(self, value):
        '''
        Find a value in the disjoint set.
        '''
        if(self.disjoint[value] != value):
            self.disjoint[value] = self.disjoint_find(self.disjoint[value])
        return self.disjoint[value]
    
    def disjoint_union(self, x, y):
        '''
        Given x and y as the component of the disjoint set,
        union these two elements together.
        '''
        # Find the position of x and y in the disjoint set
        x_root = self.disjoint_find(x)
        y_root = self.disjoint_find(y)
        # If the ranking of y is higher, then set the disjoint element
        # list of x's root to y's root. 
        if self.ranking[x_root] < self.ranking[y_root]:
            self.disjoint[x_root] = y_root
        # In contradiction, set the disjoint element list of y's root
        # to x's root.
        elif self.ranking[x_root] > self.ranking[y_root]:
            self.disjoint[y_root] = x_root
        # Otherwise, that means x == y. Adjust the disjoint set of x
        # so that it would equal to y. Add the ranking of y by 1 so that
        # we could see later on that once x's root is set followed by
        # y's root.
        else:
            self.disjoint[x_root] = y_root
            self.ranking[y_root] += 1