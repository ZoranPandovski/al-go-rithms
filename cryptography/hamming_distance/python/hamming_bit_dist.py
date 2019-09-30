"""
Determine the bitwise hamming distance, between two equal length strings a and b.
"""
def hamming_bit_dist(a,b):
    if len(a) != len(b):
        raise ValueError("a and b are unequal lengths")
    dist = 0
    for i in range(len(a)):
        dist += ord(a[i]) ^ ord(b[i])
    return dist