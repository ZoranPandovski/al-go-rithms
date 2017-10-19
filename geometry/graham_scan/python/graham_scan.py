#!/usr/bin/env python

import Tkinter as tk
from random import random

def make_a_right_turn(a, b, c):
    """Going from a to b to c involves a right turn?"""

    u = (c[0] - b[0], c[1] - b[1])
    v = (a[0] - b[0], a[1] - b[1])

    cross_product = u[0] * v[1] - u[1] * v[0]

    return cross_product < 0

def graham_scan(points):
    """Calculate convex hull using Graham's Scan"""

    points.sort()

    upper_convex_hull = points[0:2]

    for point in points[2:]:
        while len(upper_convex_hull) > 1 and not make_a_right_turn(upper_convex_hull[-2], upper_convex_hull[-1], point):
            upper_convex_hull.pop()
        upper_convex_hull.append(point)

    lower_convex_hull = points[-1:-3:-1]

    for point in points[-3::-1]:
        while len(lower_convex_hull) > 1 and not make_a_right_turn(lower_convex_hull[-2], lower_convex_hull[-1], point):
            lower_convex_hull.pop()
        lower_convex_hull.append(point)

    return upper_convex_hull + lower_convex_hull[1:-1]

def test(n, width, height):
    """Test Graham's Scan algorithm with random points and draw the result"""

    points = [(random() * width, random() * height) for _ in range(n)]

    convex_hull = graham_scan(points)

    # UI stuff
    master = tk.Tk()

    canvas = tk.Canvas(master, width=width, height=height)
    canvas.pack()

    canvas.create_polygon(*[coord for point in convex_hull for coord in point], outline='blue', width=2, fill='')

    for (x, y) in points:
        canvas.create_oval(x-1, y-1, x+1, y+1, fill='black')

    tk.mainloop()

if __name__ == "__main__":
    test(50, 640, 480)
