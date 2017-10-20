def levenshtein(first, second):
    n1 = len(first)
    n2 = len(second)
    t = [0] * (n2 + 1)
    for i in range(0,n2):
        t[i] = i
    for i in range(0,n1):
        t[0] = i + 1
        corner = i
        for j in range(0,n2):
            upper = t[j + 1]
            if (first[i] == second[j]):
                t[j + 1] = corner
            else:
                t[j + 1] = min(t[j], min(upper,corner)) + 1
            corner = upper
    return t[n2]

def test():
    print(levenshtein('levenshtein','meilenstein'))
    print(levenshtein('github','bitbucket'))

if __name__ == '__main__':
    test()
