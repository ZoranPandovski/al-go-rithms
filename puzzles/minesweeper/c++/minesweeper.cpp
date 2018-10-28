// Minesweeper by Jaldhar H. Vyas <jaldhar@braincells.com> Public Domain
//
// Compile as: c++ -std=c++17 -O2 -g -Wall -Wextra -o minesweeper minesweeper.cpp
// Add -DTEST if you want to run the tests instead.
//
#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

using Pos = std::pair<int, int>;

class Cell {
public:
    Cell() : mine_{false}, visible_{false}, flag_{false} {
    }

    void flag() {
        flag_ = true;
    }

    void hide() {
        visible_ = false;
    }

    bool is_flag() {
        return flag_;
    }

    bool is_mine() {
        return mine_;
    }

    bool is_visible() {
        return visible_;
    }

    void place_mine() {
        mine_ = true;
    }

    void show() {
        visible_ = true;
    }

    void unflag() {
        flag_ = false;
    }

private:
    bool mine_;
    bool visible_;
    bool flag_;

};

class Board {
public:
    Board(int size, int mines, unsigned seed = std::random_device{}()) :
    alive_{true}, size_{size}, cells_(size * size), seed_{seed}, rnd_{seed},
    d_(0, size - 1) {
        for (auto i = 0; i < mines; i++) {
            place_mine();
        }
    }

    bool flag(const Pos& pos);

    bool is_playing() {
        return alive_;
    }

    bool is_solved();
    void show(const Pos& pos);

    unsigned seed() const {
        return seed_;
    }

    friend std::ostream& operator<<(std::ostream& out, Board& board);
private:
    Cell& cellAt(const Pos& pos) {
        return cells_[pos.first * size_ + pos.second];
    }

    int  count_surrounding(const Pos& pos);
    std::vector<Pos> get_neighbors(const Pos& pos);
    void place_mine();
    int  remaining_mines();

    bool in_range(int n) {
        return n > -1 && n < size_;
    }

    int size() const {
        return size_;
    }

    bool alive_;
    int size_;
    std::vector<Cell> cells_;
    unsigned seed_;
    std::minstd_rand rnd_;
    std::uniform_int_distribution<int> d_;
};

int Board::count_surrounding(const Pos& pos) {
    auto neighbors = get_neighbors(pos);

    return std::count_if(neighbors.begin(), neighbors.end(),
    [this](Pos& neighbor) -> bool {
        return this->cellAt(neighbor).is_mine();
    });
}

bool Board::flag(const Pos& pos) {
    auto& cell = cellAt(pos);
    if (cell.is_visible()) {
        return false;
    } else {
        if (cell.is_flag()) {
            cell.unflag();
            cell.hide();
        } else {
            if (remaining_mines() < 1) {
                return false;
            }
            cell.flag();
        }
        return true;
    }
}

bool Board::is_solved() {
    return std::all_of(cells_.begin(), cells_.end(),
    [](Cell& cell) -> bool {
        return cell.is_visible() || cell.is_mine();
    });
}

int Board::remaining_mines() {
    auto mines = 0;

    for (auto i = 0, l = size_; i < l; i++) {
        for (auto j = 0; j < l; j++) {
            auto cell = cellAt(Pos(i, j));
            if ( cell.is_mine()) {
                mines++;
            }
            if (cell.is_flag()) {
                mines--;
            }
        }
    }

    return mines;
}

void Board::show(const Pos& pos) {
    auto& cell = cellAt(pos);

    if (!cell.is_visible()) {
        cell.show();

        if (cell.is_mine() && !cell.is_flag()) {
            alive_ = false;
        } else if (!count_surrounding(pos)) {
            auto neighbors = get_neighbors(pos);
            for(auto& neighbor:  neighbors) {
               show(neighbor);
            }
        }
    }
}

std::vector<Pos> Board::get_neighbors(const Pos& pos) {
    std::vector<Pos> neighbors;

    std::vector<Pos> surrounding {
        {-1, -1}, {-1,  0}, {-1,  1},
        {0 , -1},           {0 ,  1},
        {1 , -1}, {1 ,  0}, {1 ,  1}
    };

    for (auto& surr: surrounding) {
        auto new_row = pos.first + surr.first;
        auto new_column = pos.second + surr.second;
        if (in_range(new_row) && in_range(new_column)) {
            neighbors.emplace_back(Pos(new_row, new_column));
        }
    }
 
    return neighbors;
}

void Board::place_mine() {
    Pos pos;
    do {
        pos.first = d_(rnd_);
        pos.second = d_(rnd_);
    } while (cellAt(pos).is_mine());

    cellAt(pos).place_mine();
}

std::ostream& operator<<(std::ostream& out, Board& board) {

    out << "Mines: " << board.remaining_mines() << '\n';

    out << "  ";
    for (auto i = 0, l = board.size(); i < l; i++) {
        out << i;
    }
    out << '\n';

    for (auto i = 0, l = board.size(); i < l; i++) {
        out << i << ' ';
        for (auto j = 0; j < l; j++) {
            Pos pos(i, j);
            auto& cell = board.cellAt(pos);

            if (cell.is_visible()) {
                if (cell.is_mine()) {
                    out << 'M';
                } else {
                    if (auto surr = board.count_surrounding(pos); surr > 0) {
                        out << surr;
                    } else {
                        out << ' ';
                    }
                }
            }

            else if (cell.is_flag()) {
                out << 'F';
            }

            else {
                out << '.';
            }
        }
        out << ' ' << i << '\n';
    }

    out << "  ";
    for (auto i = 0, l = board.size(); i < l; i++) {
        out << i;
    }
    out << '\n';

    return out;
}

struct Input {
    int  row_;
    int  column_;
    bool flag_;
};

void instructions() {
    std::cout 
        << "First, enter the row, followed by the column. To add or "
        << "remove a flag, add \"f\"\nafter the column (for example, 64f "
        << "would place a flag on the 6th row, 4th\ncolumn).\n";
}

void prompt() {
    std::cout << "Enter your move (for help enter \"H\"): ";
}

Input get_move(Board& board) {
    std::string line;
    bool finished = false;
    int row, column;
    bool flag = false;

    while (!finished) {
        prompt();
        getline(std::cin, line);
        if (line[0] == 'H' || line[0] == 'h') {
            instructions();
        } else if (line[0] == 'S' || line[0] == 's') {
            std::cout << "Seed = " << board.seed() << '\n';
        } else {
            if (isdigit(line[0]) && isdigit(line[1])) {
                row = line[0] - '0';
                column = line[1] - '0';
                if (line[2] == 'F' || line[2] == 'f') {
                    flag = true;
                }
                finished = true;
            } else {
                std::cout << "Invalid input. "; 
            }
        }
    }

    return Input{row, column, flag};
}

#ifndef TEST
int main() {

    Board board(10, 9);

    while(board.is_playing() && !board.is_solved()) {
        std::cout << board << '\n';

        auto [row, column, is_flag] = get_move(board);
        if (is_flag) {
            if (!board.flag(Pos(row, column))) {
                std::cout <<
                    "Cannot add flag, cell already visible or no more flags.\n";
            }
        } else {
            board.show(Pos(row, column));
        }
    }

    std::cout << board << '\n';

    if (board.is_solved()) {
        std::cout << "Well done! You solved the board!\n";
    } else {
        std::cout << "Uh oh! You blew up!\n";
    }

    return 0;
}

#else

#include <sstream>

bool test1() {
    std::stringstream image;
    image << "Mines: 9\n" <<
    "  0123456789\n" <<
    "0 .......... 0\n" <<
    "1 .......... 1\n" <<
    "2 .......... 2\n" <<
    "3 .......... 3\n" <<
    "4 .......... 4\n" <<
    "5 .......... 5\n" <<
    "6 .......... 6\n" <<
    "7 .......... 7\n" <<
    "8 .......... 8\n" <<
    "9 .......... 9\n" <<
    "  0123456789\n";
    Board board(10, 9, 1833548985);
 
    std::stringstream output;
    output << board;
 
    return output.str() == image.str();
}

bool test2() {
    std::stringstream image;
    image << "Mines: 9\n" <<
    "  0123456789\n" <<
    "0 ...1  1... 0\n" <<
    "1 ...1  2... 1\n" <<
    "2 1211  1... 2\n" <<
    "3       12.. 3\n" <<
    "4        111 4\n" <<
    "5            5\n" <<
    "6 11211      6\n" <<
    "7 ....211111 7\n" <<
    "8 .......... 8\n" <<
    "9 .......... 9\n" <<
    "  0123456789\n";
     Board board(10, 9, 1833548985);
     board.show(Pos(5, 5));

    std::stringstream output;
    output << board;
 
    return output.str() == image.str();
}

bool test3() {
    Board board(10, 9, 1833548985);
    board.show(Pos(0, 0));
    board.show(Pos(0, 1));
    board.show(Pos(0, 2));
    board.show(Pos(0, 9));
    board.show(Pos(1, 1));
    board.show(Pos(1, 7));
    board.show(Pos(3, 9));
    board.show(Pos(5, 5));
    board.show(Pos(7, 0));
    board.show(Pos(7, 2));
    board.show(Pos(8, 6));
    board.show(Pos(8, 7));
    board.show(Pos(8, 9));
    board.show(Pos(9, 0));
    board.show(Pos(9, 5));
    board.show(Pos(9, 6));
    board.show(Pos(9, 7));
    board.show(Pos(9, 8));
    board.show(Pos(9, 9));

    return board.is_solved();
}

bool test4() {
    Board board(10, 9, 1833548985);
    board.show(Pos(0, 7));

    return !board.is_playing();
}

bool test5() {
    std::stringstream image;
    image << "Mines: 8\n" <<
    "  0123456789\n" <<
    "0 .......F.. 0\n" <<
    "1 .......... 1\n" <<
    "2 .......... 2\n" <<
    "3 .......... 3\n" <<
    "4 .......... 4\n" <<
    "5 .......... 5\n" <<
    "6 .......... 6\n" <<
    "7 .......... 7\n" <<
    "8 .......... 8\n" <<
    "9 .......... 9\n" <<
    "  0123456789\n";
    Board board(10, 9, 1833548985);
    board.flag(Pos(0, 7));
 
    std::stringstream output;
    output << board;
 
    return output.str() == image.str();
}

bool test6() {
    std::stringstream image;
    image << "Mines: 9\n" <<
    "  0123456789\n" <<
    "0 .......... 0\n" <<
    "1 .......... 1\n" <<
    "2 .......... 2\n" <<
    "3 .......... 3\n" <<
    "4 .......... 4\n" <<
    "5 .......... 5\n" <<
    "6 .......... 6\n" <<
    "7 .......... 7\n" <<
    "8 .......... 8\n" <<
    "9 .......... 9\n" <<
    "  0123456789\n";
    Board board(10, 9, 1833548985);
    board.flag(Pos(0, 7));
    board.flag(Pos(0, 7));
 
    std::stringstream output;
    output << board;
 
    return output.str() == image.str();
}

bool test7() {
    Board board(10, 9, 1833548985);
    board.show(Pos(0, 0));
    return board.flag(Pos(0, 0)) == false;
}

bool test8() {
    Board board(10, 9, 1833548985);
    board.flag(Pos(0, 7));
    board.flag(Pos(1, 0));
    board.flag(Pos(1, 2));
    board.flag(Pos(2, 7));
    board.flag(Pos(3, 8));
    board.flag(Pos(7, 1));
    board.flag(Pos(7, 3));
    board.flag(Pos(8, 5));
    board.flag(Pos(8, 8));
 
    return board.flag(Pos(0, 0)) == false;
}

bool test9() {
    std::stringstream image;
    image << "Mines: 0\n" <<
    "  0123456789\n" <<
    "0 .......F.. 0\n" <<
    "1 F.F....... 1\n" <<
    "2 .......F.. 2\n" <<
    "3 ........F. 3\n" <<
    "4 .......... 4\n" <<
    "5 .......... 5\n" <<
    "6 .......... 6\n" <<
    "7 .F.F...... 7\n" <<
    "8 .....F..F. 8\n" <<
    "9 .......... 9\n" <<
    "  0123456789\n";
    Board board(10, 9, 1833548985);
    board.flag(Pos(0, 7));
    board.flag(Pos(1, 0));
    board.flag(Pos(1, 2));
    board.flag(Pos(2, 7));
    board.flag(Pos(3, 8));
    board.flag(Pos(7, 1));
    board.flag(Pos(7, 3));
    board.flag(Pos(8, 5));
    board.flag(Pos(8, 8));

    std::stringstream output;
    output << board;
 
    return output.str() == image.str();
}

bool test10() {
    Board board(10, 9, 1833548985);
    return board.seed() == 1833548985;
}

int main() {
    std::cout << "1  " << (test1() ? "OK" : "NOK") << " output\n"; 
    std::cout << "2  " << (test2() ? "OK" : "NOK") << " show\n"; 
    std::cout << "3  " << (test3() ? "OK" : "NOK") << " hit mine\n"; 
    std::cout << "4  " << (test4() ? "OK" : "NOK") << " solved\n"; 
    std::cout << "5  " << (test5() ? "OK" : "NOK") << " flag\n"; 
    std::cout << "6  " << (test6() ? "OK" : "NOK") << " unflag\n"; 
    std::cout << "7  " << (test7() ? "OK" : "NOK") << " flag in wrong place\n"; 
    std::cout << "8  " << (test8() ? "OK" : "NOK") << " too many flags\n";
    std::cout << "9  " << (test9() ? "OK" : "NOK") << " all mines found\n";
    std::cout << "10 " << (test10() ? "OK" : "NOK") << " seed\n";

    return 0;
}
#endif
