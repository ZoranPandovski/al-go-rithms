
class Point:

    def __init__(self, x, y):
        self._cluster = 0 # Not classified yet
        self._visited = False
        self._x = x
        self._y = y
    
    def get_cluster(self):
        return self._cluster

    def set_cluster(self, cluster):
        self._cluster = cluster
        
    def get_values(self):
        return (self._x, self._y)
    
    def is_visited(self):
        return self._visited

    def visit(self):
        self._visited = True

# Point.py
