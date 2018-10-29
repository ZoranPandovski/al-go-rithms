import math

def D(xU, xL):
    r = 0.61803
    return r * (xU - xL)

def func(x):
    return 2 * math.sin(x) - (x * x) / 10.0

def GoldenSection(xL,  xU, f):
    d = D(xU, xL)
    x1 = xL + d
    x2 = xU - d
    f1 = f(x1)
    f2 = f(x2)

    while abs(x1 - x2) > 3E-8:
        if (f1 > f2):
            xL = x2
            x2 = x1
            f2 = f1

            d = D(xU, xL)
            x1 = xL + d
            f1 = f(x1)
        else:
            xU = x1
            x1 = x2
            f1 = f2
            d = D(xU, xL)
            x2 = xU - d
            f2 = f(x2)
    print(x1, f(x1))

GoldenSection(0, 3, func)