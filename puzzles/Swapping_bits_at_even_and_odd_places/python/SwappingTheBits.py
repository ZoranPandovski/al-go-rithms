def swapbits(n):
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)


print(swapbits(10))

# For n = 10, OUTPUT = 5
# For n = 1, OUTPUT = 2
