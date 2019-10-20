import math

def func(x):
    return 2 * math.sin(x) - x**2 / 10

def Parabolic(xL, xU, f):
    x = 1
    xPrevious = 0
    xM = (xL + xU) / 2
    fL = f(xL)
    fM = f(xM)
    fU = f(xU)

    while abs(x - xPrevious) > 3e-8:
        xPrevious = x
        top = (xM - xL) ** 2 * (fM - fU) - (xM - xU) ** 2 * (fM - fL)
        bot = (xM - xL) * (fM - fU) - (xM - xU) * (fM - fL)
        x = xM - 0.5 * (top / bot)

        if fL > fU:
            xU = xM
            fU = fM

        else:
            xL = xM
            fL = fM
        xM = x
        fM = f(x)
    return x

print(Parabolic(1, 3, func))