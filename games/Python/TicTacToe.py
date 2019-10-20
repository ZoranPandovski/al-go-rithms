import random

 #to print out the board
def drawBoard (board):
    print ('   |   |')
    print (' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print ('   |   |')
    print ('------------')
    print ('   |   |')
    print (' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print ('   |   |')
    print ('------------')
    print ('   |   |')
    print (' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print ('   |   |')
    
def inputPlayerLetter():
    letter = ''
    while not (letter == 'X' or letter == 'O'):
        print('What do you want: X or O?')
        letter = input().upper()
        
    if letter == 'X':
        return ['X','O']
    else: 
        return ['O','X']
        
def firstTurn():
    if random.randint(0,1) == 0:
        return 'computer'
    else:
        return 'player'
        
def playAgain():
    print ('Do you want to play again?')
    return input().lower().startswith('y')  
    
def makeMove(board , letter , move):
    board[move] = letter
    
def winner(bo,le):
    return ((bo[7]==le and bo[8]==le and bo[9]==le) or
    (bo[4]==le and bo[5]==le and bo[6]==le) or
    (bo[1]==le and bo[2]==le and bo[3]==le) or 
    (bo[7]==le and bo[4]==le and bo[1]==le) or 
    (bo[8]==le and bo[5]==le and bo[2]==le) or 
    (bo[9]==le and bo[6]==le and bo[3]==le) or 
    (bo[9]==le and bo[5]==le and bo[1]==le) or 
    (bo[7]==le and bo[5]==le and bo[3]==le))
    
def getBoardCopy(board):
    dupeBoard = []
    
    for i in board:
        dupeBoard.append(i)
        
    return dupeBoard
    
def isSpaceFree(board, move):
    return board[move] == ' '
    
def getPlayerMove(board):
    
    move = ' '
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not isSpaceFree(board,int(move)):
        print ('What is your next move? (1-9)')
        move = input()
    return int (move)
    
def chooseRandomMoveFromList (board,movesList):
    possibleMoves = []
    for i in movesList:
        if isSpaceFree(board,i):
            possibleMoves.append(i)
        
    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None
    
def getComputerMove(board,computerLetter):
    
    if computerLetter == 'X':
        playerLetter == 'O'
    else:
        playerLetter == 'X'
    
    #to check if we can the next move    
    for i in range(1,10):
        copy = getBoardCopy(board)
        if isSpaceFree(copy,i):
            makeMove(copy, computerLetter , i)
            if winner(copy, computerLetter):
                return i
    
    #to check if player can win in their next move and block them
    for i in range(1,10):
        copy = getBoardCopy(board)
        if isSpaceFree(copy,i):
            makeMove(copy, playerLetter , i)
            if winner(copy, playerLetter):
                return i
            
    #try to take one of the corners if they are free
    move = chooseRandomMoveFromList (board, [1, 3, 7, 9])
    if move != None:
        return move
        
    #try to take the centre, if it is free
    if isSpaceFree(board, [5]):
        return 5
    
    #move on one of the sides
    return chooseRandomMoveFromList (board, [2, 4, 6, 8])
    
def isBoardFull (board):
    #return true if every space is full, otherwise false
    for i in range(1, 10):
        if isSpaceFree(board, i):
            return False
    return True        
    
    
print ('Welcome to Tic Tac Toe')

while True:
    #reset the board
    theBoard = [' '] * 10
    playerLetter, computerLetter = inputPlayerLetter()
    turn = firstTurn()
    print ('The ' + turn + ' will go first. ')
    gameIsPlaying = True
    
    while gameIsPlaying:
        if turn == 'player':
            #Player's turn
            drawBoard(theBoard)
            move = getPlayerMove(theBoard)
            makeMove (theBoard , playerLetter , move)
            
            if winner (theBoard, playerLetter):
                drawBoard(theBoard)
                print('You have won the game!!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    drawBoard(theBoard)
                    print('The game is a Tie!!')
                    break
                else:
                    turn = 'computer'
                
        else:
            #Computer's turn
            move = getComputerMove(theBoard, computerLetter)
            makeMove(theBoard, computerLetter, move)
            
            if winner(theBoard, computerLetter):
                drawBoard(theBoard)
                print('The computer has won!! You lose!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    drawBoard(theBoard)
                    print('The game is a Tie!!')
                    break
                else:
                    turn = 'player'
                    
    if not playAgain():
        break