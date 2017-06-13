def binary_search(list, num):
    found = False
    first = 0
    last = len(list) - 1
    while first <= last and not found:
        middle = (first + last)//2
        if list[middle] == num:
            found = True
        elif list[middle] < num:
            first = middle + 1
        else:
            last = middle - 1

    return found


def test():
    list = [2, 3, 7, 8, 78, 99, 102, 5555]
    item = 3
    assert binary_search(list, item) == True


if __name__ == '__main__':
    test()
