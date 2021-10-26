

# The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 
# Queen can move in verticaly, horizontaly and dialgonaly in chess. This problem is solved using depth first search 
# and backtracking.The logic is to place queens one by one in different columns, starting from leftmost column. 
# When the queen is placed, check if it satisfies all the conditions. 
# If it satisfies then go ahead otherwise backtrack to the previous step. Do these steps until we get to last 
# column to get the answer.


# Time Complexity:
# when we assign a location of the queen in the first column, we have n options, 
# after that, we only have n-1 options as we can't place the queen in the same row as the first queen,
# then n-2 and so on. Thus, the worst-case complexity is still upper bounded by O(n!).The time complexity will be O(N!)


# Space Complexity:
# As the program only uses a board which is given by default. So the space complexity of program will be O(1).




''' Utility function to initialize board of N size '''
def initBoard(N):
    board = []
    for j in range(N):
        temp = []
        for i in range(N):
            temp.append(0)
        board.append(temp)
    return board


''' Function to print answer '''
def printAnswer(board, N):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end = " ")
        print()


''' Check if board is valid or not'''
def isValid(board, row, column):
    # If there is one present in same row then it is not valid
    for i in range(column):
        if board[row][i] == 1:
            return False

    i = row
    j = column

    # Check values of 1 on upper left diagonal
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i = row
    j = column

    # Check values of 1 on lower left diagonal
    while i < N and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    # If there are no 1's present in same diagonal or same column then placing queen is valid
    return True

''' Main function which contains logic of generate and test solution'''
def solve_generate_test_util(board, N, column):

    #Base condition to return from recursion
    #If it goes until last column then the result must be true
    if column >= N:
        return True
    
    for i in range(N):
        # Function to check if placing queen at particular point is valid
        if isValid(board, i, column):
            
            #Consider there is solution from this column
            board[i][column] = 1

            # Try to place queen in next column
            if solve_generate_test_util(board, N, column + 1):
                return True
            
            #If not possible to generate solution
            # make cell 0 again
            board[i][column] = 0
    
    return False


'''Base function to solve n queens problems using generate and test'''
def solve_generate_test(N):
    board = initBoard(N)

    if solve_generate_test_util(board, N, 0):
        print("\nSolution using Generate and test algorithm: ")
        printAnswer(board,N)
        print()



if __name__ == "__main__":
    N = int(input('Enter the size of board: '))
    solve_generate_test(N)
