"""
Determine the hamming distance, at the character level, between two equal length strings a and b.
"""
def hamming_char_dist(a,b):
    if len(a) != len(b):
        raise ValueError("a and b are unequal lengths")
    dist = 0
    for i in range(len(a)):
        if(a[i] != b[i]):
            dist += 1
    return dist