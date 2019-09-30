import os
from colorama import init, deinit, Fore, Back, Style
clear = lambda: os.system('cls')
clear()
 
init()
 
colors = [Fore.BLACK, Fore.WHITE, Fore.WHITE + Style.BRIGHT, Fore.RED + Style.DIM, Style.BRIGHT + Fore.GREEN, Fore.YELLOW, Fore.BLUE, Fore.MAGENTA, Fore.CYAN, Fore.RED + Style.BRIGHT, Fore.BLUE + Style.BRIGHT, Fore.MAGENTA + Style.BRIGHT, Fore.YELLOW + Style.BRIGHT]
 
# Shapes
shapes = [    
    { "variations":
        ("OOOO\n" # L
         "O..."),
      "used": False },
   
    { "variations":
        ("..OO\n" # N
         "OOO."),
      "used": False },
   
    { "variations":
        ("OOO\n" # P
         ".OO"),
      "used": False },
   
    { "variations":
        ("OOO\n" # T
     ".O.\n"
     ".O."),
      "used": False },
   
    { "variations":
        ("O.O\n" # U
         "OOO"),
      "used": False },
   
    { "variations":
        ("O..\n" # V
     "O..\n"
     "OOO"),
      "used": False },
   
    { "variations":
        ("..O\n" # W
         ".OO\n"
         "OO."),
      "used": False },
   
    { "variations":
        (".O.\n" # X
         "OOO\n"
         ".O."),
      "used": False },
   
    { "variations":
        ("OOOO\n" # Y
        ".O.."),
      "used": False },
   
    { "variations":
        ("OO.\n" # Z
         ".O.\n"
         ".OO"),
      "used": False },
     
    { "variations":
        ("OOOOO"),
      "used": False
    }, # I
   
    { "variations":
        (".OO\n" # F
         "OO.\n"
         ".O."),
      "used": False }
]
 
# Interpret shape strings above
 
for i in range(0, len(shapes)):
    variations = []
 
    shape = shapes[i]["variations"].split("\n")
 
    # Turn the list of strings of the shape into list of lists of 0's and 1's representing shape
    for j in range(0, len(shape)):
        shape[j] = list(shape[j])
 
        shape[j] = [0 if c == "." else 1 for c in shape[j]]
 
    mirror = [list(reversed(row)) for row in shape]
 
    for _ in range(0, 4):
        shape = [list(elem) for elem in zip(*shape[::-1])] # Rotate clockwise
        mirror = [list(elem) for elem in zip(*mirror[::-1])]
 
        if not shape in variations:
            variations.append(shape)
       
        if not mirror in variations:
            variations.append(mirror)
 
    shapes[i]["variations"] = variations
 
input_string = input("Enter width and height in format 'w h'. Only multiples of 5 work.: \n").split(" ")
width = int(input_string[0])
height = int(input_string[1])
pieces_needed = (width * height) / 5
board = [[0 for i in range(0, width)] for j in range(0, height)]
num_steps = 0
 
def print_board():
    global num_steps
 
    for r in board:
        s = ""
        for c in r:
            s += colors[c] + "██" + Style.RESET_ALL
       
        print(s + Style.RESET_ALL + "|")
 
    print("----------------------------")
    print(num_steps)
 
def try_place_shape(shape, x, y, id, adj):
    if y + len(shape) > height or x + len(shape[0]) > width:
        return False
 
    foundAdj = False
 
    for j, r in enumerate(shape):
        by = y + j
 
        for i, c in enumerate(r):
            bx = x + i
 
            if c == 1:
                if board[by][bx] > 0:
                    return False
                elif adj and not foundAdj: # Some shapes may not touch another when placed in their spot. It's useless to place those
                    if bx > 0 and board[by][bx - 1] > 0:
                        foundAdj = True
                    elif bx + 1 < width and board[by][bx + 1] > 0:
                        foundAdj = True
                    elif by > 0 and board[by - 1][bx] > 0:
                        foundAdj = True
                    elif by + 1 < height and board[by + 1][bx] > 0:
                        foundAdj = True
                    else:
                        foundAdj = False
 
    if adj and not foundAdj:
        return False
 
    for j, r in enumerate(shape):
        by = y + j
        for i, c in enumerate(r):
            bx = x + i
 
            if c == 1:
                board[by][bx] = id
 
    # Check for impossible areas. Done in one scan by combining areas it sees above with area's it's created by traveling from left to right
    areas = {}
    combines = {}
    ai = -1
 
    for j, r in enumerate(board):
        for i, c in enumerate(r):
            if c == 0:
                left = 1
                up = 1
 
                if i > 0:
                    left = board[j][i - 1]
                if j > 0:
                    up = board[j - 1][i]
                elif i == 0 and j == 0:
                    areas[ai] = 1
                    board[j][i] = ai
                    ai -= 1
                    continue
               
                if left < 0 and up < 0:
                    if left == up:
                        areas[left] += 1
                    else:
                        areas[left] += 1
                        combines[left] = up
                   
                    board[j][i] = left
                elif left < 0:
                    areas[left] += 1
                    board[j][i] = left
                elif up < 0:
                    areas[up] += 1
                    board[j][i] = up
                else:
                    ai -= 1
                    areas[ai] = 1
                    board[j][i] = ai
   
    # Reset our math
    for j, r in enumerate(board):
        for i, c in enumerate(r):
            if c < 0:
                board[j][i] = 0
 
    # Combine all areas      
    for key, value in combines.items():
        v = value # Sometimes chains of areas may exist
        while v in combines:
            v = combines[v]
 
        areas[v] += areas[key]
        del areas[key]
 
    # Check if any areas are "cutoff". This is a slight optimization that sometimes prevents the contuation of a search that has an obvious "hole" that can only be filled by
    # an already used piece
    if len(areas) > 1:
        remove_shape(shape, x, y)
        return False
 
    # If the area left is not a multiple of 5, then it is unsolvable.
    for key, value in areas.items():
        if value < 5 or value % 5 != 0:
            remove_shape(shape, x, y)
            return False
   
    return True
 
def remove_shape(shape, x, y):
    for j, r in enumerate(shape):
        for i, c in enumerate(r):
            if c == 1:
                board[y + j][x + i] = 0
 
solution_stack = []
 
# It's safe to use a recursive search because the max depth we can go is 12.
def recursive_search():
    global num_steps
   
    for i, shape in enumerate(shapes):
        if shape["used"]:
            continue
 
        for j, variation in enumerate(shape["variations"]):
            for x in range(0, width):
                for y in range(0, height):
                    if try_place_shape(variation, x, y, i + 1, len(solution_stack) != 0):
                        shape["used"] = True
                        solution_stack.append({ "shape": variation, "x": x, "y": y})
                        num_steps += 1
 
                        print_board()
                        clear()
 
                        if len(solution_stack) == pieces_needed:
                            return True
                        elif recursive_search():
                            return True
                        else:
                            shape["used"] = False
                            solution_stack.pop()
                            remove_shape(variation, x, y)
 
recursive_search()
print_board()
 
input()
deinit()