def karatsuba(a, b):
    if (a < 10) or (b < 10):
        return a * b
    else:
        if (a > b):
            m = pow(10, len(str(a))/2)
        else:
            m = pow(10, len(str(b))/2)
        x1, x2 = divmod(a, m)
        y1, y2 = divmod(b, m)

        z0 = karatsuba(x1, y1)
        z1 = karatsuba(x2, y2)
        z3 = karatsuba((x1+x2), (y1+y2)) - z0 - z1
        return (z0 * pow(m, 2) + z1 + (z3 * m))
