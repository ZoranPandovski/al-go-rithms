n=int(input('Enter number of queens:'))
def solveNQueens(n):
    # Initialize the board as a 2D list of zeros
    board = [[0 for _ in range(n)] for _ in range(n)]

    def isSafe(row, col):
        # Check if any queens already placed in the same row
        for i in range(col):
            if board[row][i] == 1:
                return False
        
        # Check if any queens already placed in the same upper diagonal
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1
        
        # Check if any queens already placed in the same lower diagonal
        i, j = row, col
        while i < n and j >= 0:
            if board[i][j] == 1:
                return False
            i += 1
            j -= 1
        
        # If no conflicts found, then the position is safe
        return True

    def solveHelper(col):
        # Base case: If all queens are placed, return True
        if col == n:
            return True
        
        # Recursive case: Try placing queen in each row of current column
        for row in range(n):
            if isSafe(row, col):
                board[row][col] = 1
                if solveHelper(col + 1):
                    return True
                board[row][col] = 0
        
        # If no safe position found, backtrack
        return False

    # Call the helper function to solve N-Queens problem
    if solveHelper(0):
        # Print the board
        for row in board:
            print(row)
    else:
        print("No solution exists for N =", n)
solveNQueens(n)
