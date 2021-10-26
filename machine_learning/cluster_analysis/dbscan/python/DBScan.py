from cluster.dbscan.Point import Point
from math import sqrt


class DBScan:

    def __init__(self, points, eps, min_points):
        """
        DBScan is initialized by passing a list of points, the eps, and
        a minimum number of points per cluster.

        Args:
             param1: The dataset of points to be analyzed
             param2: The eps neighborhood of a point
             param3: The minimum number of elements per cluster.
         """

        self._points = points
        self._clusters = 0 # initial clusters
        for point in self._points:
            if point.is_visited():
                continue
            point.visit()
            neighbors_point = self.find_neighbours(point, eps)
            if len(neighbors_point) < min_points:
                point.set_cluster(-1) # a noise point
            else:
                self._clusters = self._clusters + 1
                self.expand_cluster(point, neighbors_point,
                                    self._clusters, eps, min_points)

    def expand_cluster(self, point, neighbors_points,
                                    cluster, eps, min_points):
        """
        This method is resposible for expanding the neighbors of a point.

        Args:
            param1: Point itself
            param2: The actual cluster being of that points
            param3: The eps neighborhood of a point
            param4: The minimum number of elements per cluster
        """

        point.set_cluster(cluster)
        for p in neighbors_points:
            if not p.is_visited():
                p.visit()
                neighbors_p = self.find_neighbours(p, eps)
                if len(neighbors_p) >= min_points:
                    neighbors_points.extend(neighbors_p)
            if p.get_cluster() == 0:
                p.set_cluster(cluster)

    def find_neighbours(self, point, eps):
        """
        This method is resposible for finding the neighbors of a points.
        The metric being used is the Euclidean distance.

        Args:
            param1: Point itself
            param2: The eps neighborhood of a point
        """

        x, y = point.get_values()
        neighbors = []
        for p in self._points:
            m, n = p.get_values()
            distance = ((m - x) * (m - x) + (n - y) * (n - y))
            distance = sqrt(distance)
            if distance <= eps:
                neighbors.append(p)
        return neighbors

    def get_clusters(self):
        """
        This method is resposible for returning the clusters found, and their
        respective elements.
        """

        clusters = [[] for i in range(0, self._clusters)]
        for point in self._points:
            if (point.get_cluster() != -1):
                clusters[point.get_cluster() - 1].append(point)
        return clusters

# DBScan.py
