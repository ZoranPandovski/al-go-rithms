def PwrSet(arr, n):
    li = []
    for i in range(2**n):
        subs = ""
        for j in range(n):
            if (i & (1 << j)) != 0:
                subs += str(arr[j]) + "|"
        if subs not in li and len(subs) > 0:
            li.append(subs)
    for subs in li:
        arr = subs.split('|')
        for string in arr:
            print(string, end = " ")
        print()
arr = [10, 12, 12]
n = len(arr)
PwrSet(arr, n)
