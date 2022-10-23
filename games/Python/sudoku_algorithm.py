"""
    Algorithm:
            - each row of the board must contain all digits from 0 to 9 (the order doesn't matter)
            - each column of the board must contain all digits from 0 to 9 (again, the order doesn't matter)
            - each of the nine 3x3 "tiles" (we will name them "sub-squares") of the table must contain all digits from 0 to 9.
Test data
    Sample input:
        295743861
        431865927
        876192543
        387459216
        612387495
        549216738
        763524189
        928671354
        154938672
    Sample output:
        Yes.


    Sample input:
        195743862
        431865927
        876192543
        387459216
        612387495
        549216738
        763524189
        928671354
        254938671
    Sample output:
        No
"""

def validate(sudoku_algorithm_opt):
    custom_list = dict.fromkeys(sudoku_algorithm_opt)
    if len(custom_list) == 9:
        return True
    else:
        return False


def sudoku_algorithm(function_input):
    temp_list = []
    flag = False
    #x axis
    for i in range(3):
        for j in range(3):
            temp_list.append(matrix[i][j])
    flag = validate(temp_list)
    temp_list.clear()

    #y axis
    for j in range(3):
        for i in range(3):
           temp_list.append(matrix[i][j])
    flag = validate(temp_list)
    temp_list.clear()

    #Left to Right Diagonal
    for i in range(3):
        for j in range(3):
            if i==j:
                temp_list.append(matrix[i][j])
            else:
                continue
    flag = validate(temp_list)
    temp_list.clear()

    #Right to Left Diagonal
    i=2
    j=2
    while i>=0:
        while j>=0:
            if i==j:
                temp_list.append(matrix[i][j])
                i -= 1
                j -= 1
            else:
                continue
    flag = validate(temp_list)
    temp_list.clear()

    # sub squares:
    # square 1:
    for i in range(3):
        for j in range(3):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 2:
    for i in range(3, 6):
        for j in range(3):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 3:
    for i in range(6, 9):
        for j in range(3):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 4:
    for i in range(3):
        for j in range(3, 6):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 5:
    for i in range(3, 6):
        for j in range(3, 6):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 6:
    for i in range(6, 9):
        for j in range(3, 6):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 7:
    for i in range(3):
        for j in range(6, 9):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 8:
    for i in range(3, 6):
        for j in range(6, 9):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    # square 9:
    for i in range(6, 9):
        for j in range(6, 9):
            temp_list.append(matrix[i][j])
     flag = validate(temp_list)
     temp_list.clear()

    if flag == True:
        print("Matches the sudoku rules")
    else:
        print("Doesn't match with the sudoku rules")


def matrix_config(user_list):
    #initializing the board
    matrix = [[i for i in range(9)] for j in range(9)]
    index = 0
    for i in range(9):
        for j in range(9):
            matrix[i][j] = user_list[index]
            index += 1
    sudoku_algorithm(matrix)


def user_input():
    contents = []
    for i in range(9):
        values = input("Enter the numbers: ")
        duplicates = list(dict.fromkeys(values))
        if (len(duplicates) == len(values)):
            for n in values:
                contents.append(n)
        else:
            print("Invalid Input")
            user_input()
    matrix_config(contents)

user_input()
