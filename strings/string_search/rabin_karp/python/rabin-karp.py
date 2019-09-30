# Function requires the following arguments:
# text,
# pattern,
# d = number of characters in input alphabet,
# q = a prime number


def rabin_karp_algorithm(text, pattern, d, q):
    n = len(text)
    m = len(pattern)
    h = pow(d, m-1) % q
    p = 0                   # hash value of the pattern
    t = 0                   # hash value of the text
    result = []
    # calculate the hash values for pattern and text
    for i in range(m):
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(text[i])) % q

    # Slide pattern over text
    for s in range(n - m + 1):
        # Check the hash values of the current window of text and pattern
        if p == t:
            # Check for characters one by one
            match = True
            for i in range(m):
                if pattern[i] != text[s+i]:
                    match = False
                    break
            if match:
                result = result + [s]
        # Calculate hash value for next window of text: Remove
        # leading digit, add trailing digit
        if s < n - m:
            t = (t - h * ord(text[s])) % q  # remove letter s
            t = (t * d + ord(text[s+m])) % q  # add letter s+m
            t = (t + q) % q  # make sure that t >= 0
    return "Found pattern at " + str(result) + "."


print(rabin_karp_algorithm("Hello World", "ll", 256, 11))
print(rabin_karp_algorithm("12121212", "12", 256, 11))

