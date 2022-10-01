#-------def global 'board' ----------
board = ["-", "-", "-",
         "-", "-", "-",
         "-", "-", "-"]

# Lets us know if the game is over yet
game_still_going = True

# Tells us who the winner is
winner = None

# Counts rounds of play
round = 0

# Tells us who the current player is (X goes first)
current_player = "X"


def game():
    global game_still_going
    while game_still_going:
        playerTurn(current_player)
        gameboard()
        checkWinner()
        flipPlayer()

def gameboard():
    print("\n")
    print(board[0] + " | " + board[1] + " | " + board[2] + "     1 | 2 | 3")
    print(board[3] + " | " + board[4] + " | " + board[5] + "     4 | 5 | 6")
    print(board[6] + " | " + board[7] + " | " + board[8] + "     7 | 8 | 9")
    print("\n")


def playerTurn(player):
    number = input('Podaj miejsce ktore chcesz zaznaczyć: ')
    try:
        number = int(number)
        print(number)
    except:
        print('Podal liczbe nie wyraz!')
        return

    if number <= 9 and number > 0:
        if board[number - 1] == '-':
            board[number - 1]=player
        else:
            print('pole jest zajete!')
    else:
        print('Nie ma takiego pola')

def flipPlayer():
    global current_player
    if current_player == 'X':
        current_player = 'O'
    else:
        current_player = 'X'

def checkWinner():
    rowWinner()
    colsWinner()
    diagonalWinner()


def rowWinner():
    global game_still_going
    global winner
    row_1 = board[0] == board[1] == board[2] != "-"
    row_2 = board[3] == board[4] == board[5] != "-"
    row_3 = board[6] == board[7] == board[8] != "-"

    if row_1 or row_2 or row_3:
        game_still_going = False
    # Return the winner
    if row_1:
        return board[0]
    elif row_2:
        return board[3]
    elif row_3:
        return board[6]
    
def colsWinner():
    global game_still_going
    global winner
    column_1 = board[0] == board[3] == board[6] != "-"
    column_2 = board[1] == board[4] == board[7] != "-"
    column_3 = board[2] == board[5] == board[8] != "-"

    if column_1 or column_2 or column_3:
        game_still_going = False
    # Return the winner
    if column_1:
        return board[0]
    elif column_2:
        return board[1]
    elif column_3:
        return board[2]
def diagonalWinner():
    global game_still_going
    global winner
    diagonal1 = board[0] == board[4] == board[8] != '-'
    diagona2 = board[6] == board[4] == board[0] != '-'




gameboard()

game()



