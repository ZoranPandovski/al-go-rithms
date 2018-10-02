import numpy as np

def createSquare(size):
    """Creates an N x N magic square
    
    In a magic square, every row, column, and diagonal add up to the same number.
    
    @param size The size of the magic square
    @return A boolean representing if the square was created or not
    """
    
    # The size must be odd
    if size % 2 == 0:
        print('Size must be odd')
        return False

    # Initialize with zeros
    magic_square = np.zeros((size,size), dtype=int)

    n = 1
    i, j = 0, size//2

    while n <= size**2:
        magic_square[i, j] = n
        n += 1
        newi, newj = (i - 1) % size, (j + 1) % size
        if magic_square[newi, newj]:
            i += 1
        else:
            i, j = newi, newj

    print(magic_square)
    return True

def runTests():
    # Test cases
    assert createSquare(3) is True
    assert createSquare(5) is True
    assert createSquare(6) is False
    assert createSquare(4) is False

runTests()
