import random
from itertools import cycle
import matplotlib.pyplot as plt

from k_means.python.model.k_point import KPoint2D


def create_initial_centroids(k, points=None, max_x=None, max_y=None):
    """
    Use a means to place the centroids. We place them randomly but you can also place them one by one by averaging x,y
    positions and then place the next one as far away as possible.
    :param k: amount of clusters
    :param points: for averaging if needed
    :return:
    """
    print(k)
    centroids = []
    if not points:
        for i in range(0, k):
            point = KPoint2D(random.randint(0, max_x), random.randint(0, max_y))
            centroids.append(point)

    return centroids


def k_means(k, points, max_x=800, max_y=800):
    """
    Find k center points for the given points. Points are expected to be in 0,max_x and 0,max_y
    :param k: number of partitions
    :param points: list of KPoint2D
    :param max_x: maximum value we want for the centroid initializing
    :param max_y: maximum value we want for the centroid initializing
    :return: centroids, points with centroids
    """
    centroids = create_initial_centroids(k, max_x=max_x, max_y=max_y)
    print(centroids)

    iterate = True
    centroidsChanged = False
    c = 0
    while iterate:
        print("iteration... {}".format(c))
        c += 1
        iterate = False
        # assign centroids
        for i in range(0, len(points)):
            centroid_distances = [(centroid, points[i].distance_to(centroid)) for centroid in centroids]
            # assign centroid with the lowest distance to the current node
            local_min = min([dist[1] for dist in centroid_distances])
            nearest = [centroid[0] for centroid in centroid_distances if centroid[1] == local_min]
            points[i].set_centroid(nearest.pop())
            # print("n={}".format(nearest))
        # update centroids
        for j in range(0, len(centroids)):
            # fetch all children of this centroid
            children=[point for point in points if point.centroid == centroids[j]]
            # if there are children currently
            if(len(children)>0):
                # average the x and y positions and set the centroid to the avg (placing them in the middle of their children)
                avg_x = sum([point.x for point in children]) / len(children)
                avg_y = sum([point.y for point in children]) / len(children)
                if abs(centroids[j].x - avg_x) > 0 or  abs(centroids[j].y - avg_y) > 0:
                    centroids[j].x = avg_x
                    centroids[j].y = avg_y
                    # reiterate if something changes
                    iterate=True

    return centroids, points


def test(max_x, max_y):
    points = []
    k = 3
    max_x = 1000
    max_y = 1000
    for i in range(0, 500):
        points.append(KPoint2D(random.randint(0, max_x), random.randint(0, max_y)))

    centroids, points = k_means(k, points, max_x=max_x, max_y=max_y)

    size = 4
    cycol = cycle('bgrcmk')

    for j in range(0, len(centroids)):
        c = next(cycol)
        children = [point for point in points if point.centroid == centroids[j]]
        print("centroid={}; children count={}".format(centroids[j], len(children)))

        if (len(children) > 0):
            x = [c.x for c in children]
            y = [c.y for c in children]
            # plot children
            plt.scatter(x, y, marker='.', color=c)
        # plot centroid
        plt.scatter(centroids[j].x, centroids[j].y, marker='D', color=c, edgecolors='black')

    plt.show()


test(800, 800)
