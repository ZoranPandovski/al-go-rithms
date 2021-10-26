# recursive binary search
# return, if present, the position of the searched element
# returns -1 if the element is not present

def recursive_binary_search(n, e, i, j):
    if i > j:
        return -1

    half = (i+j)/2

    if e == n[half]:
       return half

    elif e < n[half]:
       return recursive_binary_search(n, e, i, half-1)

    elif e > n[half]:
       return recursive_binary_search(n, e, half+1, j)


def test():
    a_list = [1,5,7,8,13,17,21,27,33,37,40]
    item = 21
    start = 0
    end = len(a_list)-1
    assert recursive_binary_search(a_list, item, start, end) == 6

if __name__ == "__main__":
    test()
