'''
    Union find is a disjoint set data structure normally used for two purpose:
    Find (connected components) 
    Union (join two subsets into a single set) 
'''

class UnionFind:
    def __init__(self, n: int) -> None:
        self._parents = list(range(0, n)) # initally each node is its own parent 
        self._ranks = [1 for _ in range(n)]   
    
    def find(self, u: int) -> int: 
        """
            The find() operation traverses up from u to find root.
            make found root parent so we don't have to treverse all intermediate nodes again.
        """
        while u != self._parents[u]: 
            self._parents[u] = self.find(self._parents[u])
            u = self._parents[u]
        return u

    def connected(self, u: int, v: int) -> bool:
        """
            Return True If u and v are connected (have same root)
        """
        return self.find(u) == self.find(v)
    
    def union(self, u: int, v: int) -> bool:
        """
            Return True If already connected otherwise False
            Connect node u and v.
            To connect nodes, Assign new parents based on their ranking.
            Hihger ranking root became the parent of lower ranking root 
        """
        root_u, root_v = self.find(u), self.find(v)
        if root_u == root_v:
            return True # Already connected because they have same root 
        if self._ranks[root_u] > self._ranks[root_v]:
            self._parents[root_v] = root_u         
        elif self._ranks[root_v] > self._ranks[root_u]:
            self._parents[root_u] = root_v
        else:
            self._parents[root_u] = root_v
            self._ranks[root_v] += 1
        return False 


# Time complexity
# Find: log(N)
# Union: log(N)
def test():
    arr = [0,1,2,3,4,5]

    union_find = UnionFind(len(arr))

    union_find.union(0, 1);
    #  1 2 3 4 5
    #  /
    #  0
    # parents = [1, 1, 2, 3, 4, 5]
    # ranks = [1, 2, 1, 1, 1, 1]


    union_find.union(1,2)
    #  1 3 4 5
    #  /\
    #  0 2
    # parents = [1, 1, 1, 3, 4, 5]
    # ranks = [1, 2, 1, 1, 1, 1]

    assert(union_find.connected(0, 2) == True)
    assert(union_find.connected(1, 2) == True)
    assert(union_find.connected(5, 4) == False)


    union_find.union(4,5)
    #  1  5  3
    #  /\  \
    #  0 2  4
    # parents = [1, 1, 1, 3, 5, 5]
    # ranks = [1, 2, 1, 1, 1, 2]

    assert(union_find.connected(5, 4) == True)
    assert(union_find.connected(0, 4) == False)


    union_find.union(1,4)
    #   5  3
    #  / \
    #  1  4
    # /\
    # 0 2 
    # parents = [1, 5, 1, 3, 5, 5]
    # ranks = [1, 2, 1, 1, 1, 3]

    assert(union_find.connected(0, 4) == True)
    # After above check , parents will look like this
    # parents = [5, 5, 1, 3, 5, 5]

    assert(union_find.connected(3, 4) == False)
    assert(union_find.connected(2, 3) == False)

if __name__ == "__main__":
    test()