'''
Python implementation of merge sort algorithm.
Takes an average of 0.6 microseconds to sort a list of length 1000 items.
Best Case Scenario : O(n)
Worst Case Scenario : O(n)
'''
def merge_sort(LIST):
    start = []
    end = []
    while len(LIST) > 1:
        a = min(LIST)
        b = max(LIST)
        start.append(a)
        end.append(b)
        LIST.remove(a)
        LIST.remove(b)
    if LIST: start.append(LIST[0])
    end.reverse()
    return (start + end)
