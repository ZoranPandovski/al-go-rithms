class EightQueens:
    def __init__(self, size=8):
        self.size = size
        self.columns = []
        
    def place_queen(self, row, column):
        for r, c in enumerate(self.columns):
            if c == column or r - c == row - column or r + c == row + column:
                return False
        self.columns.append(column)
        return True
    
    def solve(self):
        solutions = []
        def backtrack(row=0):
            if row == self.size:
                solutions.append(list(self.columns))
            else:
                for column in range(self.size):
                    if self.place_queen(row, column):
                        backtrack(row + 1)
                        self.columns.pop()
        backtrack()
        return solutions
