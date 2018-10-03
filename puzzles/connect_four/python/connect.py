def play(n=None):
    if n is None:
        while True:
            try:
                n = int(input('Input the grid size: '))
            except ValueError:
                print('Invalid input')
                continue
            if n <= 0:
                print('Invalid input')
                continue
            break

    grids = [[0]*n for _ in range(n)]
    user = 1
    print('Current board:')
    print(*grids, sep='\n')
    while True:
        user_input = get_input(user, grids, n)
        place_piece(user_input, user, grids)
        print('Current board:')
        print(*grids, sep='\n')

        if (check_won(grids, user, n) or
                check_won(zip(*grids), user, n) or
                diagcheck_won(grids, user, n) or
                diagcheck_won(grids[::-1], user, n)):
            print('Player', user, 'has won')
            return

        if not any(0 in grid for grid in grids):
            return

        user = 2 if user == 1 else 1


def get_input(user, grids, n):
    instr = 'Input a slot player {0} from 1 to {1}: '.format(user, n)
    while True:
        try:
            user_input = int(input(instr))
        except ValueError:
            print('invalid input:', user_input)
            continue
        if 0 > user_input or user_input > n+1:
            print('invalid input:', user_input)
        elif grids[0][user_input-1] != 0:
            print('slot', user_input, 'is full try again')
        else:
            return user_input-1


def place_piece(user_input, user, grids):
    for grid in grids[::-1]:
        if not grid[user_input]:
            grid[user_input] = user
            return


def check_won(grids, user, n):
    return any(all(cell == user for cell in grid) for grid in grids)


def diagcheck_won(grids, user, n):
    return all(grids[x][x] == user for x in range(n))


if __name__ == '__main__':
    play()
