number = 201328361572
maxDigit = -1

# convert number into unique set of digits and iterate over it
for c in set(str(number)):
    # parse back to int and compare vs known max
    i = int(c)
    if i > maxDigit:
        maxDigit = i

print(maxDigit)
# > 8
