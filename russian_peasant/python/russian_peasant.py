def russian_peasant(a,b):
    x = a
    y = b
    z = 0
    while x > 0:
        if x % 2 == 1:
            z = z + y
        y = y << 1
        x = x >> 1

    return z


def test():
    assert russian_peasant(5,15) == 75


if __name__ == "__main__":
	test()