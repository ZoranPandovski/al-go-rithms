class node:
    def __init__(self, id, heuristic, f):
        self.id=id
        self.heuristic=heuristic
        self.totalCost=0
        self.f=f
        self.parent=None

    def setParent(self,parent):
        self.parent=parent

    def __lt__(self, other):
        return self.f < other.f

    def __repr__(self):
        #return "node:[id={}, heuristic={}, totalCost={}, cost={}, parent={}]".format(self.id,self.heuristic,self.totalCost,self.cost,self.parent)
        if(self.parent != None):
            return "node:[id={}, parentId={}, f={}, heuristic={}]".format(self.id,self.parent.id,self.f, self.heuristic)
        else:
            return "node:[id={}], f={}, heuristic={}]".format(self.id,self.f, self.heuristic)

    def copy(self):
        """
        Sometimes we need a new copy of a node if you find it again as a neighbor of another node.
        :return:
        """
        return node(self.id,self.heuristic,self.f)