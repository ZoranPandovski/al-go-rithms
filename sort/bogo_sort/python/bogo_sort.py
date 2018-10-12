from random import randrange


def bogosort(lst):
    # Helper that returns a shuffled version of the list
    def shuffle(l):
        out = [None for x in range(len(l))]
        for item in l:
            r = randrange(0, len(l))
            while out[r] is not None:
                r -= 1
            out[r] = item
        return out

    # Helper that returns true if each element is smaller or equal than the previous
    def isinorder(l):
        for index in range(1,len(l)):
            if l[index-1] > l[index]:
                return False
        return True

    # Shuffle until in order
    while not isinorder(lst):
        lst = shuffle(lst)
        print("lst: ", lst)  # Uncomment to print lists tried

    # Finally in order
    return lst

def test():
	list = [14,37,22,84,2,31]
	sorted_list = bogosort(list)
	assert (sorted_list == sorted(list)) == True

if __name__ == "__main__":
    test()
    print(bogosort([1, 2, 3]))
    print(bogosort([3, 2, 1]))
    print(bogosort([2, 3, 1]))
    print(bogosort([2, 6, 1, 5, 7, 4, 3]))
    print(bogosort(['c', 'a', 'b']))
    print(bogosort([randrange(0,13) for i in range(13)]))  # Will take a long time (probably)

