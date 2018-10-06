import random

class Board:
    """
    Board class is used to setup the board 
    """
    def __init__(self, n):
        self.n = n
        self._board = [None] * n

    def status(self):
        return self._board[:]

    def _valid_idx(self, i):
        return 0 <= i < self.n

    def _valid(self, i, j):
        return self._valid_idx(i) and self._valid_idx(j)

    def move(self, i, j):
        if not self._valid(i):
            return
        if j is not None and not self._valid(j):
            return
        self._board[i] = j

    def get(self, i, j):
        if not self._valid(i, j):
            return
        return self._board[i] == j

    def at_row(self, i):
        if not self._valid_idx(i):
            return None
        return self._board[i]

    def print(self):
        for i in range(self.n):
            for j in range(self.n):
                if self.get(i, j):
                    print('X', end='')
                else:
                    print('.', end='')
            print()

    def reachable(self, i, j):
        if not self._valid(i, j):
            return None
        if self._board[i] is not None:
            if self._board[i] != j:
                # Cell (i, j) is reachable by the queen on row i
                # Note that we test that this queen is not on (i, j)!
                return True
        for k in range(self.n):
            # Check that the queen on row `k` cannot attack
            # the cell (i, j)
            if k == i:
                # If we're looking at row `i`, we already did
                # the check above
                continue
            # The queen at row `k` (!= `i`) can attack (i, j)
            #  - via a column if her column index is `j`
            #  - via the first diagonal if her column index is (j+(k-i))
            #    (note that this column index might be invalid because the
            #     first diagonal will be out of the board at row `i`.
            #     This is not a problem since then we are not going to
            #     find at queen at that location!)
            #  - via the second diagonal if her column index is (j-(k-i))
            #    (the same remark applies here)
            if self._board[k] in (j, j+(k-i), j-(k-i)):
                return True

        # We checked all the possible attackes, so the
        # cell is not reachable.
        return False

    def solved(self):
        # A board is solved if...
        for i in range(self.n):
            # 1. there is a queen on each row
            #    (i.e. there are n queens on the board)
            if self._board[i] is None:
                return False
            # 2. queens cannot attack each others.
            if self.reachable(i, self._board[i]):
                return False
        return True

    def shuffle(self):
        for i in range(self.n):
            # On each row, place a queen at random
            self._board[i] = random.randint(0, self.n - 1)

    def cost(self):
        cost = 0
        # For each row `i`, computes the number of queens that can
        # attack the queen Q(i) at row `i` and add this count to the
        # cost. Note that we only consider queens with row index `j`
        # greater than `i` s.t. we do not count twice a pair of
        # attacking queens.
        for i in range(self.n):
            if self._board[i] is None:
                # If there are no queens on row `i`, do nothing
                continue
            for j in range(i + 1, self.n):
                # Otherwise, iterate over all the queens Q(j)with a
                # row index `j` greater than `i`.
                if self._board[i] == self._board[j]:
                    # Q(i) and Q(j) are on the same column, they form
                    # an attacking pair
                    cost += 1
                offset = j - i
                if self._board[i] == self._board[j] - offset:
                    # If Q(i) and Q(j) are on the same upper diagonal,
                    # they form an attacking pair.
                    cost += 1
                if self._board[i] == self._board[j] + offset:
                    # If Q(i) and Q(j) are on the same lower diagonal,
                    # they form an attacking pair.
                    cost += 1
                # The remarks in `reachable()` about the diagonals
                # indices apply here.
        return cost

    def climb(self):
        # Copy the input board state and board cost
        copy   = self.status()
        icost  = self.cost()

        # mcost is going to store the mimimum cost found so far. mcostv
        # is a board for which this cost is reached Initially, the
        # minimum cost is set to the input noard cost.
        mcost  = icost
        mcostv = self.status()

        # For all rows `i`...
        for i in range(self.n):
            # For all columns `j`...
            for j in range(self.n):
                # Move the queen at row `i` to column `j`
                self.move(i, j)
                # If the new board cost is lower than the minimum cost
                # reached so far, record this board as the new minimal
                # board.
                cost = self.cost()
                if cost < mcost:
                    mcost, mcostv = cost, self.status()
        
        if mcost < icost:
            # If mcost < icost, we found a board with a cost stricly
            # smaller then the one of the input board. Store it into
            # `self` and return the minimum cost we found.
            self._board = mcostv
            return mcost

        # Otherwise, we reset the board to its initial state and
        # we return None.
        self._board = copy
        return None

    def solve(self):
        # Shuffle the board
        self.shuffle()
        while True:
            # Try to find a better solution in the neighborhood.
            msr = self.climb()
            # If we fail to find a better solution, reshuffle the
            # board and start again
            if msr is None:
                self.shuffle()
                continue
            # If the score is 0, we found a solution
            if msr == 0:
                return

# --------------------------------------------------------------------
def nqueens1(b, i):
    # `b` is assumed to be solved at rank `i`. There might be a queen
    # at row `i` but this is not mandatory.  we try to progress on the
    # i-th row, moving the queen at row `i` to the right and on the
    # left-most non-reachable cell (on row `i`)

    # Start if the lowest possible column index of this left-most
    # non-reachable cell. It is equal to 0 is there are no queens on
    # row `i`, or to `x+1` where `x` is the column index of the queen
    # on row `i`.
    start = 1 + (-1 if b.at_row(i) is None else b.at_row(i))

    # Clear the queen at row `i`. This is important as we want to
    # clear the row on row `i` if we cannot progress. Not doing this
    # will impear the soundness of `nqueens` below.
    b.move(i, None)

    for j in range(start, b.n):
        if not b.reachable(i, j):
            # If we found a non-reachable call on row `i` whose column
            # index is greater (or equal) than `start`, place a queen
            # on it and return True
            b.move(i, j); return True

    # We failed to find non-reachable cell. We simply return False
    # Now, the board is solved up to rank `i` but there are no queens
    # on row `i`.
    return False

# --------------------------------------------------------------------
def nqueens(b, i):
    # If i >= b.n, the board is solved up to `n`, i.e. it is
    # solved. Hence, we yield it.
    if i >= b.n:
        yield b
    else:
        while True:
            # Otherwise, using `nqueens1`, we try to progress on the
            # i-th row, moving the queen at row `i` to the right and
            # on the left-most non-reachable cell (on row `i`)
            if not nqueens1(b, i):
                break
            # If we progressed on row `i`, we have a board solved at
            # rank `i`. By a recursive call to `nqueens(b,i+1)`, we
            # are going to iterate over all the solution reachable
            # from `b`. Note that `nqueens` is a generator, and python
            # won't automatically re-yield if we simply do a call. We
            # have to do it by hand.

            yield from nqueens(b, i+1)

            # The above statement is equivalent to:
            #
            # for x in nqueens(b, i+1):
            #     yield x

# --------------------------------------------------------------------
def _main():
    b = Board(4)
    for i, j in enumerate([0, 3, 2, 1]):
        b.move(i, j)
    b.print()
    print(b.solved())
    for i, j in enumerate([2, 0, 3, 1]):
        b.move(i, j)
    b.print()
    print(b.solved())
    b = Board(4)
    b.move(0, 0)
    while True:
        b.print()
        print()
        if not nqueens1(b, 1):
            break
    b = Board(4)
    for b2 in nqueens(b, 0):
        b2.print()
        print()
    b = Board(5)
    for i, j in enumerate([0, 0, 1, 2, 4]):
        b.move(i, j)
    print(b.cost())
    b = Board(50)
    b.solve()
    b.print()
    
# --------------------------------------------------------------------
if __name__ == '__main__':
    _main()

            
