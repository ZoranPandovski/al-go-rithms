# Author: thisHermit

def flip(v: list, end, start):

    i = start
    j = end - 1
    while (i <= j):
        v[i], v[j] = v[j], v[i]
        i += 1
        j -= 1

def pancake_sort(v: list, end, start):

    biggest = start

    if end >= start:
        for i in range(start + 1, end):
            if (v[i] > v[biggest]):
                biggest = i
        flip(v, end, biggest)
        print(biggest,"")
        flip(v, end, start)
        print(start, "")

    if not ordenando(v, start, end):
        pancake_sort(v, end, start + 1)

def ordenando(v: list, start, end):
    for i in range(start, end):
        if(v[i] < v[i + 1]):
            return False
    return True

def main():

    input_array = [5, 4, 3, 2, 1]
    sorted_array = input_array.copy()

    pancake_sort(sorted_array, len(sorted_array), 0)

    assert sorted(input_array), sorted_array
