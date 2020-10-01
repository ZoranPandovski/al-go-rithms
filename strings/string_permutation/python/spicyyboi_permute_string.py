"""
Gives all permutations of a string given as user input.

Example:
    Input: Please enter the string: test
    Output:
        t
        e
        te
        s
        ts
        es
        tes
        t
        tt
        et
        tet
        st
        tst
        est
        test
"""


def permute(string):
    """Iterable yielding all permutations of a string"""
    length = len(string)
    powers = [2**i for i in range(length)]

    for i in range(2**length):
        rval = ""
        for p, st in zip(powers, string):
            if i & p:
                rval += st
        if rval != "":
            yield rval


inp = input("Please enter the string: ")

for s in permute(inp):
    print(s)
