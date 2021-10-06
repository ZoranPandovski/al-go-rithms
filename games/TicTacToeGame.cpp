#include <bits/stdc++.h>

using namespace std;

string playerX, playerO, turn;
char board[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
int row, column, moves = 0;
char inputSign;

bool checkWinner(char inputSign)
{
    return ((board[0][0] == inputSign && board[0][1] == inputSign && board[0][2] == inputSign) ||
            (board[1][0] == inputSign && board[1][1] == inputSign && board[1][2] == inputSign) ||
            (board[2][0] == inputSign && board[2][1] == inputSign && board[2][2] == inputSign) ||
            (board[0][0] == inputSign && board[1][0] == inputSign && board[2][0] == inputSign) ||
            (board[0][1] == inputSign && board[1][1] == inputSign && board[2][1] == inputSign) ||
            (board[0][2] == inputSign && board[1][2] == inputSign && board[2][2] == inputSign) ||
            (board[0][0] == inputSign && board[1][1] == inputSign && board[2][2] == inputSign) ||
            (board[0][2] == inputSign && board[1][1] == inputSign && board[2][1] == inputSign));
}

void resetBoardState()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '.';
        }
    }
}

bool isBoardFull()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '.')
                return false;

    return true;
}

void printBoardState()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "\t\t" << board[i][j];
        }
        cout << "\n\n";
    }
}

void declareResult()
{
    cout << "\t\t\t\t\t\tRESULTS\n";
    cout << "\t\t\t\t\t--------------------------------\n";
    if (isBoardFull() && !(checkWinner('X') || checkWinner('O')))
    {
        cout << "\t\t\t\t\t\t"
             << "GAME TIED\n";
    }
    else
    {
        if (checkWinner('X'))
            cout << "\t\t\t\t\t\t" << playerX << " WINS!!\n";
        else
        {
            cout << "\t\t\t\t\t\t" << playerO << " WINS!!\n";
        }
    }
    cout << "\t\t\t\t\t--------------------------------\n";
}

void changeBoardState(char inputSing, int r, int c)
{
    if (board[r][c] == '.')
    {
        board[r][c] = inputSign;
    }
    else
    {
        cout << "The Position is already occupied";
        cout << '\n';
        moves--;
    }
}
void playGame()
{
    bool validRow, validColumn;
    do
    {
        if (moves % 2 == 0)
        {
            turn = playerX;
            inputSign = 'X';
        }

        else
        {
            turn = playerO;
            inputSign = 'O';
        }

        if (isBoardFull())
        {
            break;
        }

        else
        {
            cout << "Current Turn: " << turn;
            do
            {
                validRow = true;
                cout << "\n";
                cout << "Enter the row number(0-2): ";
                cin >> row;
                if (row < 0 || row > 2)
                {
                    cout << "\nEnter valid coordinates\n";
                    validRow = false;
                }
            } while (validRow == false);

            do
            {
                validColumn = true;
                cout << "\n";
                cout << "Enter the column number(0-2): ";
                cin >> column;
                if (column < 0 || column > 2)
                {
                    cout << "\nEnter valid coordinates\n";
                    validColumn = false;
                }
            } while (validColumn == false);
            changeBoardState(inputSign, row, column);
            moves++;
            printBoardState();
        }
    } while (!checkWinner(inputSign) && !isBoardFull());
}

void registerPlayers()
{
    do
    {
        cout << "Enter the name of X Player: ";
        getline(cin, playerX);
        cout << "\nEnter the name of O Player: ";
        getline(cin, playerO);
        cout << "\n";
        if (playerX == playerO)
        {
            cout << "Players must have unique names\n";
            cout << "Enter names again\n";
        }
    } while (playerX == playerO);
}

void startGame()
{
    char choice;
    do
    {
        system("cls");
        cout << "\t\t\t\t\t--------------------------------\n";
        cout << "\t\t\t\t\t\tTIC-TAC-TOE GAME\n";
        cout << "\t\t\t\t\t--------------------------------\n";
        registerPlayers();
        printBoardState();
        playGame();
        declareResult();
        cout << "\t\t\t\t\tDO YOU WANT TO PLAY AGAIN? (Y/N): ";
        cin >> choice;
        resetBoardState();
        moves = 0;
    } while (choice != 'n' || choice != 'N');
}

int main()
{
    system("color 03");
    startGame();
    return 0;
}