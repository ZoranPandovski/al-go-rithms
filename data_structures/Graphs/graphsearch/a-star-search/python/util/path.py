
class path:
    def __init__(self,source,destination,cost):
        """
        Described a path from a node to another node including its cost.
        :param source: from this node
        :param destination:  to this node
        :param cost: cost to travel the path
        """
        self.source=source
        self.destination=destination
        self.cost=cost

    def __repr__(self):
        return "path:[source={}, destination={}, cost={}]".format(self.source,self.destination,self.cost)
