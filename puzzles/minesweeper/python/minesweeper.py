
import random

class Cell(object):
    def __init__(self, is_mine, is_visible=False, is_flagged=False):
        self.is_mine = is_mine
        self.is_visible = is_visible
        self.is_flagged = is_flagged

    def show(self):
        self.is_visible = True

    def flag(self):
        self.is_flagged = not self.is_flagged

    def place_mine(self):
        self.is_mine = True


class Board(tuple):
    def __init__(self, tup):
        super().__init__()
        self.is_playing = True

    def mine_repr(self,row_id, col_id):
        cell = self[row_id][col_id]
        if cell.is_visible:
            if cell.is_mine:
                return "M"
            else:
                surr = self.count_surrounding(row_id, col_id)
                return str(surr) if surr else " "
        elif cell.is_flagged:
            return "F"
        else:
            return "X"

    def __str__(self):
        board_string = ("Mines: " + str(self.remaining_mines) + "\n  " +
                        "".join([str(i) for i in range(len(self))]))
        for (row_id, row) in enumerate(self):
            board_string += ("\n" + str(row_id) + " " + 
                             "".join(self.mine_repr(row_id, col_id) for (col_id, _) in enumerate(row)) +
                             " " + str(row_id))
        board_string += "\n  " + "".join([str(i) for i in range(len(self))])
        return board_string

    def show(self, row_id, col_id):
        cell = self[row_id][col_id]
        if not cell.is_visible:
            cell.show()

            if (cell.is_mine and not
                cell.is_flagged):
                self.is_playing = False
            elif self.count_surrounding(row_id, col_id) == 0:
                for (surr_row, surr_col) in self.get_neighbours(row_id, col_id):
                    if self.is_in_range(surr_row, surr_col):
                        self.show(surr_row, surr_col) 

    def flag(self, row_id, col_id):
        cell = self[row_id][col_id]
        if not cell.is_visible:
            cell.flag()
        else:
            print("Cannot add flag, cell already visible.")

    def place_mine(self, row_id, col_id):
        self[row_id][col_id].place_mine()

    def count_surrounding(self, row_id, col_id):
        return sum(1 for (surr_row, surr_col) in self.get_neighbours(row_id, col_id)
                        if (self.is_in_range(surr_row, surr_col) and
                            self[surr_row][surr_col].is_mine))

    def get_neighbours(self, row_id, col_id):
        SURROUNDING = ((-1, -1), (-1,  0), (-1,  1),
                       (0 , -1),           (0 ,  1),
                       (1 , -1), (1 ,  0), (1 ,  1))
        return ((row_id + surr_row, col_id + surr_col) for (surr_row, surr_col) in SURROUNDING)

    def is_in_range(self, row_id, col_id):
        return 0 <= row_id < len(self) and 0 <= col_id < len(self)

    @property
    def remaining_mines(self):
        remaining = 0
        for row in self:
            for cell in row:
                if cell.is_mine:
                    remaining += 1
                if cell.is_flagged:
                    remaining -= 1
        return remaining

    @property
    def is_solved(self):
        return all((cell.is_visible or cell.is_mine) for row in self for cell in row)

def create_board(size, mines):
    board = Board(tuple([tuple([Cell(False) for i in range(size)])
                         for j in range(size)]))
    available_pos = list(range((size-1) * (size-1)))
    for i in range(mines):
        new_pos = random.choice(available_pos)
        available_pos.remove(new_pos)
        (row_id, col_id) = (new_pos % 9, new_pos // 9)
        board.place_mine(row_id, col_id)
    return board

def get_move(board):
    INSTRUCTIONS = ("First, enter the column, followed by the row. To add or "
                    "remove a flag, add \"f\" after the row (for example, 64f "
                    "would place a flag on the 6th column, 4th row). Enter "
                    "your move: ")

    move = input("Enter your move (for help enter \"H\"): ")
    if move == "H":
        move = input(INSTRUCTIONS)

    while not is_valid(move, board):
        move = input("Invalid input. Enter your move (for help enter \"H\"): ")
        if move == "H":
            move = input(INSTRUCTIONS)

    return (int(move[1]), int(move[0]), move[-1] == "f")

def is_valid(move_input, board):
    if move_input == "H" or (len(move_input) not in (2, 3) or
                             not move_input[:1].isdigit() or
                             int(move_input[0]) not in range(len(board)) or
                             int(move_input[1]) not in range(len(board))):
        return False

    if len(move_input) == 3 and move_input[2] != "f":
        return False

    return True

def main():
    SIZE = 10
    MINES = 9
    board = create_board(SIZE, MINES)
    print(board)
    while board.is_playing and not board.is_solved:
        (row_id, col_id, is_flag) = get_move(board)
        if not is_flag:
            board.show(row_id, col_id)
        else:
            board.flag(row_id, col_id)
        print(board)

    if board.is_solved:
        print("Well done! You solved the board!")
    else:
        print("Uh oh! You blew up!")

if __name__ == "__main__":
    main()
