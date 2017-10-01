from math import sqrt


class KPoint2D:
    def __init__(self, x: float, y: float):
        self.x=x
        self.y=y
        self.centroid = None

    def distance_to(self,point):
        return sqrt(pow(self.x-point.x,2)+pow(self.y-point.y,2))

    def set_centroid(self,centroid):
        self.centroid=centroid

    def __repr__(self):
        return "KPoint2D:[x={}, y={}, centroid={}]".format(self.x, self.y, self.centroid)

    def __eq__(self, other):
        return isinstance(other, KPoint2D) and self.x==other.x and self.y==other.y and self.centroid == other.centroid



