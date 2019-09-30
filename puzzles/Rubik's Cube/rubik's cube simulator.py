import os, time, re, sys
clear = lambda: os.system('cls')

locations1D = {} #The entire cube is stored in a 1 dimensional array that simulates each physical piece with 1-3 sides (center, corner, or edge)
# Origin - UFR, White-Green-Red
# Sides of corners go counterclockwise (0 top, 1 front, 2 right)

pieces = {"UFR", "UFL", "UBL", "UBR", "DFR", "DFL", "DBL", "DBR", "UF", "UL", "UB", "UR", "FR", "FL", "BL", "BR", "DF", "DL", "DB", "DR", "U", "F", "R", "L", "B", "D"}

# Every move contains defitions for what piece goes where and how each one gets rotated relative to the UFR corner.
moves = {
    "R": {"rotations": { 1: ["UFR", "DBR"], -1: ["UBR", "DFR"], 0: ["UR", "FR", "DR", "BR"] }, "movements": {"UFR": "UBR", "UBR": "DBR", "DBR": "DFR", "DFR": "UFR", "UR": "BR", "BR": "DR", "DR": "FR", "FR": "UR"}},
    "U": {"rotations": { 0: ["UFR", "UFL", "UBL", "UBR", "UF", "UR", "UB", "UL"] }, "movements": {"UFR": "UFL", "UFL": "UBL", "UBL": "UBR", "UBR": "UFR", "UF": "UL", "UL": "UB", "UB": "UR", "UR": "UF"}},
    "F": {"rotations": { -1: ["UFR", "DFL"], 1: ["DFR", "UFL", "UF", "FR", "DF", "FL"] }, "movements": {"UFR": "DFR", "DFR": "DFL", "DFL": "UFL", "UFL": "UFR", "UF": "FR", "FR": "DF", "DF": "FL", "FL": "UF"}},
    "L": {"rotations": { -1: ["UFL", "DBL"], 1: ["UBL", "DFL"], 0: ["UL", "FL", "DL", "BL"] }, "movements": {"UFL": "DFL", "DFL": "DBL", "DBL": "UBL", "UBL": "UFL", "UL": "FL", "FL": "DL", "DL": "BL", "BL": "UL"}},
    "B": {"rotations": { 1: ["UBR", "DBL", "UB", "BR", "DB", "BL"], -1: ["DBR", "UBL"] }, "movements": {"UBR": "UBL", "UBL": "DBL", "DBL": "DBR", "DBR": "UBR", "UB": "BL", "BL": "DB", "DB": "BR", "BR": "UB"}},
    "D": {"rotations": { 0: ["DFR", "DFL", "DBL", "DBR", "DF", "DR", "DB", "DL"] }, "movements": {"DFR": "DBR", "DBR": "DBL", "DBL": "DFL", "DFL": "DFR", "DF": "DR", "DR": "DB", "DB": "DL", "DL": "DF"}},
    "M": {"rotations": { 1: ["UF", "UB", "DF", "DB"] }, "movements": { "UF": "DF", "DF": "DB", "DB": "UB", "UB": "UF", "U": "F", "F": "D", "D": "B", "B": "U"}},
    "E": {"rotations": { 1: ["FR", "FL", "BL", "BR"] }, "movements": { "FR": "BR", "BR": "BL", "BL": "FL", "FL": "FR", "F": "R", "R": "B", "B": "L", "L": "F"}},
    "S": {"rotations": { 1: ["UR", "DR", "DL", "UL"] }, "movements": { "UR": "DR", "DR": "DL", "DL": "UL", "UL": "UR", "U": "R", "R": "D", "D": "L", "L": "U"}}
}

rotations = {
    "x": ["R", "M'", "L'"],
    "x'": ["R'", "M", "L"],
    "y": ["U", "E'", "D'"],
    "y'": ["U'", "E", "D"],
    "z": ["F", "S", "B'"],
    "z'": ["F'", "S'", "B"]
}

# Used for drawing corners based off of where they are on the cube
faceDefinitions = {
    "UFR": "UFR", "UFL": "ULF", "UBL": "UBL", "UBR": "URB", "DFR": "DRF", "DBR": "DBR", "DFL": "DFL", "DBL": "DLB"
}

class bcolors:
    GREEN = '\u001b[42m'
    WHITE = '\u001b[47;1m'
    RED = '\u001b[41m'
    YELLOW = '\u001b[48;5;226m'
    ORANGE = '\u001b[48;5;202m'
    BLUE = '\u001b[44m'
    BLACK = '\u001b[40m'

class Cube:
    @staticmethod
    def getFaceColor(face, smallDisplay, physicalSide):
        toReturn = ""

        if face == "U":
            toReturn = bcolors.WHITE + physicalSide
        elif face == "F":
            toReturn = bcolors.GREEN + physicalSide
        elif face == "R":
            toReturn = bcolors.RED + physicalSide
        elif face == "L":
            toReturn = bcolors.ORANGE + physicalSide
        elif face == "B":
            toReturn = bcolors.BLUE + physicalSide
        elif face == "D":
            toReturn = bcolors.YELLOW + physicalSide
        else:
            toReturn = bcolors.WHITE + "X"

        if not smallDisplay:
            return toReturn * 3
        else:
            return toReturn * 2

    @staticmethod
    def isSolved():
        for loc in locations1D.values():
            if loc.id != loc.piece.id or loc.piece.rotation != 0:
                return False
        
        return True

    @staticmethod
    def reset():
        for loc in locations1D.values():
            loc.piece = None
            loc.setPiece(Piece(loc.id))

    @staticmethod
    def move(move):
        if len(move) == 2 and move[1] == "'":
                moveData = {v:k for k,v in moves[move[0].upper()]["movements"].items()} # Swap keys and values of movement data... In effect this is moving in the opposite direction
        else:
            moveData = moves[move[0].upper()]["movements"]

        rotations = moves[move[0].upper()]["rotations"]
        toMove = []
        rots = {}

        for key, corners in rotations.items():
            for c in corners:
                rots[c] = key
            
        for key, movement in moveData.items():
            origin = Location.getLocation(key)
            target = Location.getLocation(movement)
            toMove.append({"piece": origin.piece, "origin": origin, "target": target})

        for movement in toMove:
            piece = movement["piece"]

            movement["target"].setPiece(piece)

            if piece.type == "CORNER" or piece.type == "EDGE":
                piece.rotate(rots[movement["origin"].id])
        
        if move == "r'" or move == "l":
            Cube.move("M")
        elif move == "r" or move == "l'":
            Cube.move("M'")
        elif move == "u" or move == "d'":
            Cube.move("E'")
        elif move == "u'" or move == "d":
            Cube.move("E")
        elif move == "f" or move == "b'":
            Cube.move("S")
        elif move == "f'" or move == "b":
            Cube.move("S'")

class Location:
    def __init__(self, id):
        self.id = id
        self.piece = None

        locations1D[id] = self

    def setPiece(self, piece):
        self.piece = piece
        piece.location = self
        return self

    @staticmethod
    def getLocation(id):
        if id in locations1D:
            return locations1D[id]

        return None

class Piece:
    def __init__(self, id):
        self.location = None
        self.id = id
        self.rotation = 0

        if (len(id) == 1):
            self.type = "CENTER"
        elif (len(id) == 2):
            self.type = "EDGE"
        elif (len(id) == 3):
            self.type = "CORNER"

    def rotate(self, amount):
        if self.type == "CORNER":
            self.rotation = (self.rotation + amount) % 3
        elif self.type == "EDGE":
            self.rotation = (self.rotation + amount) % 2

    #side is the side of the individual cubie you are looking for. It is then offset based off of rotation to give you the color you are looking for.
    #smallDisplay and physicalSide are used for cube rendering. They are purely for asthetic purposes
    def getColor(self, side, smallDisplay, physicalSide):
        if self.type == "CORNER":
            return Cube.getFaceColor(faceDefinitions[self.id][(side + self.rotation) % 3], smallDisplay, physicalSide)
        elif self.type == "EDGE":
            return Cube.getFaceColor(self.id[(side + self.rotation) % 2], smallDisplay, physicalSide)
        elif self.type == "CENTER":
            return Cube.getFaceColor(self.id, smallDisplay, physicalSide)

def printCube():
    s = (
        "\n"
        "      -UBL0-UB0-UBR0\n"
        "    -UL0-U0-UR0+UBR1\n"
        "  -UFL0-UF0-UFR0+UR1+BR1\n"
        "~UFL2~UF1~UFR1+UFR2+R0+DBR2\n"
        "~FL0~F0~FR0+FR1+DR1\n"
        "~DFL1~DF1~DFR2+DFR1\n"
    )

    for pieceId in pieces:
        if pieceId not in s:
            continue

        piece = Location.getLocation(pieceId).piece

        for i in range(0, 3):
            if len(pieceId) <= i:
                break

            s = re.sub('[-](' + pieceId + ')[' + str(i) + ']', piece.getColor(i, False, "-") + bcolors.BLACK, s)
            s = re.sub('[~](' + pieceId + ')[' + str(i) + ']', piece.getColor(i, False, "~") + bcolors.BLACK, s)
            s = re.sub('[+](' + pieceId + ')[' + str(i) + ']', piece.getColor(i, True, "+") + bcolors.BLACK, s)
    print(s)

for pieceId in pieces:
    Location(pieceId).setPiece(Piece(pieceId))

clear()         
printCube()

while True:
    s = input("").replace("(", "").replace(")", "")
    clear()

    if s == "exit":
        break
    elif s == "reset":
        Cube.reset()
        clear()
        printCube()
        continue

    movesToMake = s.split()

    time.sleep(0.1)

    for m in movesToMake:
        if len(m) == 3:
            m = m[0] + m[1] # Remove prime at end of double move, it screws it up!

        currentMoveList = []
        doubleMove = len(m) == 2 and m[1] == "2"

        if m[0] in "xyz":
            currentMoveList += rotations[m] if not doubleMove else (rotations[m[0]] + ["wait"] + rotations[m[0]])
        else:
            currentMoveList.append(m)

        for move in currentMoveList:
            clear()
            if move == "wait":
                printCube()
                time.sleep(0.2)
                clear()
                continue

            if len(move) == 2 and move[1] == "2":
                Cube.move(move[0])
                printCube()
                time.sleep(0.1)
                clear()
                Cube.move(move[0])
            else:
                Cube.move(move)

        printCube()

        if Cube.isSolved():
            print("Solved!")
        else:
            print(" ")

        time.sleep(0.3)

