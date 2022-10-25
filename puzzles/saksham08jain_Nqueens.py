''' DO NOT COPY
CREATED BY SAKSHAM JAIN FOR A EXCERCISE IN THE BOOK THINK LIKE A COMPUTER SCIENTIST (PYTHON )BY ALLEN B DOWNEY
THIS CODE GENERATES 12 UNIQUE SOLUTIONS(ONE FROM EACH OF 12 FAMILIES) OF 8 QUEENS PUZZLE 

INTERPRETATION OF SOLUTIONS:
THE LIST GIVES THE POSITION NO. ON A COLUMN LIKE IF LIST IS[1,0] MEANS 1 ST COLUMN 2ND SQUARE 2ND COLUMN 1 ST SQUARE
'''
def share_diagonal(x0, y0, x1, y1):
    """ Is (x0, y0) on a shared diagonal with (x1, y1)? """
    dy = abs(y1 - y0)        # Calc the absolute y distance
    dx = abs(x1 - x0)        # CXalc the absolute x distance
    return dx == dy          # They clash if dx == dy
def col_clashes(bs, c):
    """ Return True if the queen at column c clashes
         with any queen to its left.
    """
    for i in range(c):     # Look at all columns to the left of c
          if share_diagonal(i, bs[i], c, bs[c]):
              return True

    return False
def has_clashes(the_board):
    """ Determine whether we have any queens clashing on the diagonals.
        We're assuming here that the_board is a permutation of column
        numbers, so we're not explicitly checking row or column clashes.
    """
    for col in range(1,len(the_board)):
        if col_clashes(the_board, col):
            return True
    return False
def main(i):
    import random
    rng = random.Random()   # Instantiate a generator
    solutions=[]
    bd = list(range(i))     # Generate the initial permutation
    num_found = 0
    solutions=[]
    
    rng.shuffle(bd)
    tries=0
    #we limit the number of tries so that we dont get stuck in infinite loop aafter finding all solutions 
    while tries<100000:
        
        tries+=1
        rng.shuffle(bd)
        if not has_clashes(bd):
            if bd not in solutions:
                for jd in family(bd[:]):
                    
                    solutions.append(jd[:])
                print("Found solution {0} in {1} tries.".format(bd, tries))
                num_found+=1
                tries=0
      

#BUGS.......NEED TO WRITE A BUG FREE CODE...PRINT ONLY UNIQUE FAMILY SOLUTION JUST ONCE...
#12 SOLUTIONS ARE REQUIRED TO BE PRINTED....AFTER THAT INFINITE LOOP SHALL KICK IN....
                       
                 

                        
def mirror_Y(the_board):
    newboard=the_board[:]
    newboard.reverse()
    return newboard
def mirror_X(the_board):
    newboard=[]
    for i in the_board:
        temp=len(the_board)-1-i
        newboard.append(temp)
    return newboard

def anti_90(the_board):
    newboard=[]
    for i in range(len(the_board)-1,-1,-1):
        a=the_board.index(i)        
        newboard.append(a)
    return newboard
def family(the_board):
    
    temp=the_board[:]
    fam=[]
    fam.append(the_board)
    for i in range(4):
        temp=anti_90(temp)
        if temp not in fam:
            fam.append(temp)
        if mirror_X(temp) not in fam:
            fam.append(mirror_X(temp))
        if mirror_Y(temp)not in fam:
            fam.append(mirror_Y(temp))
        if mirror_X(mirror_Y(temp)) not in fam:
            fam.append(mirror_X(mirror_Y(temp)))
    return fam
if __name__=='__main__':
    print('--------------------------------------------------------------------------')
    print('Solutions of 6 queens problem ')
    main(6)
    print('--------------------------------------------------------------------------')
    print('Solutions of 8 queens problem ')
    
   
    main(8)
    print('--------------------------------------------------------------------------')
    

