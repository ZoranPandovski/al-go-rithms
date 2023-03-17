'''from __future__ import print_function
board = []
size = 8

def danger(row, col):
    """ Return if there is a danger by placing queen in
        a given row, col
    """
    for (i, j) in board:
        if row == i: return True
        if col == j: return True
        if abs(row - i) == abs(col - j): return True

    return False
    
def placequeen(row):
    if row > size:
        print(board)
    else:
        for col in range(1, size + 1):
            if not danger(row, col):
                board.append((row, col))
                placequeen(row + 1)
                board.remove((row,col))

if __name__ == "__main__":
    placequeen(1)'''

#The complexity for above is o(N!)

def solve_n_queens(n):
    if n < 1:
        return 0

    res = []
    dfs(n, 0, 0, 0, 0, [], res)
    return len(res)

def dfs(n, row, cols, left_diagonal, right_diagonal, path, res):
    if row == n:
        res.append(path)
        return

    # Generate a bit mask for valid positions in the row
    valid_positions = ((1 << n) - 1) & (~(cols | left_diagonal | right_diagonal))

    while valid_positions:
        # Get the position of the least significant bit
        pos = valid_positions & (-valid_positions)

        # Remove the least significant bit from the mask
        valid_positions &= valid_positions - 1

        # Calculate the column index of the queen
        col = bin(pos - 1).count('1')

        # Generate the next row state
        new_cols = cols | pos
        new_left_diagonal = (left_diagonal | pos) << 1
        new_right_diagonal = (right_diagonal | pos) >> 1

        # Recurse on the next row
        dfs(n, row+1, new_cols, new_left_diagonal, new_right_diagonal, path+[col], res)

if __name__ == "__main__":
    n = int(input("Enter the size of the board: "))
    count = solve_n_queens(n)
    print("Number of valid solutions for {}-queens problem: {}".format(n, count))

# The complexity for my code is : time complexity of O(2^n) and a space complexity of O(n)