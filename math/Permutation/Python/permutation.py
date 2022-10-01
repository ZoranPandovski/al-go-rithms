def permutation(lst):
    # If lst is empty then there are no permutations
    if len(lst) == 0:
        return []

        # If there is only one element in lst then, only
    # one permuatation is possible
    if len(lst) == 1:
        return [lst]

        # Find the permutations for lst if there are
    # more than 1 characters

    l = []  # empty list that will store current permutation

    # Iterate the input(lst) and calculate the permutation
    for i in range(len(lst)):
        m = lst[i]

        # Extract lst[i] or m from the list.  remLst is
        # remaining list
        remLst = lst[:i] + lst[i + 1:]

        # Generating all permutations where m is first
        # element
        for p in permutation(remLst):
            l.append([m] + p)
    return l


# Driver program to test above function
i=input()
data = list('i')
for p in permutation(data):
    print(p)