#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

class robot
{
private:
    size_t x, y;

public:
    robot();
    robot(int x, int y, std::string previous = "south");

    bool try_north(std::vector<std::string> &maze);
    bool try_east(std::vector<std::string> &maze);
    bool try_south(std::vector<std::string> &maze);
    bool try_west(std::vector<std::string> &maze);

    size_t get_x() const;
    size_t get_y() const;
    void set_x(size_t x);
    void set_y(size_t y);

    std::string previous;
};

robot::robot() : x(0), y(0), previous("south")
{}

robot::robot(int x, int y, std::string previous) : x(x), y(y), previous(previous)
{}

bool robot::try_north(std::vector<std::string> &maze)
{
    return maze[get_y() - 1][get_x()] != '#' ? true : false;
}

bool robot::try_east(std::vector<std::string> &maze)
{
    return maze[get_y()][get_x() + 1] != '#' ? true : false;
}

bool robot::try_south(std::vector<std::string> &maze)
{
    return maze[get_y() + 1][get_x()] != '#' ? true : false;
}

bool robot::try_west(std::vector<std::string> &maze)
{
    return maze[get_y()][get_x() - 1] != '#' ? true : false;
}

inline size_t robot::get_x() const
{
    return x;
}

inline size_t robot::get_y() const
{
    return y;
}

inline void robot::set_x(size_t x)
{
    this->x = x;
}

inline void robot::set_y(size_t y)
{
    this->y = y;
}

void display(std::vector<std::string> &maze)
{
    for (auto &line : maze)
    {
        std::cout << line << std::endl;
    }
}

/*
  Load an ascii maze into a string of vectors.
  This allows to access the map like a simple 2D array.
*/
std::vector<std::string> load_maze(std::string path)
{
    std::ifstream map(path.c_str());
    std::string line;
    std::vector<std::string> fl_map;
    if (map.is_open())
    {
        while (std::getline(map, line))
        {
            fl_map.push_back(line);
        }
        map.close();
    }
    else
    {
        std::cout << "Could not open file " << path << std::endl;
        exit(1);
    }
    return fl_map;
}

/*
  Manually input an ascii maze.
*/
std::vector<std::string> input_map()
{
    int rows;
    std::vector<std::string> fl_map;
    std::cout << "Enter map row size: ";
    std::cin >> rows;
    std::cout << "Enter the map" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        fl_map.push_back(line);
    }
    return fl_map;
}

std::vector<int> find(std::vector<std::string> &maze, char element)
{
    std::vector<int> xy;
    for(std::vector<int>::size_type y = 0; y != maze.size(); y++) {
        if (maze[y].find(element) != std::string::npos)
        {
            xy.push_back(maze[y].find(element));
            xy.push_back(y);
            break;
        }
    }
    return xy;
}

std::string decideWhereToMove(std::vector<std::string> &maze, robot &r)
{
    if (r.previous == "south")
    {
        if (r.try_west(maze))
        {
            return "west";
        }
        else if (r.try_north(maze))
        {
            return "north";
        }
        else if (r.try_east(maze))
        {
            return "east";
        }
    }
    else if (r.previous == "west")
    {
        if (r.try_north(maze))
        {
            return "north";
        }
        else if (r.try_east(maze))
        {
            return "east";
        }
        else if (r.try_south(maze))
        {
            return "south";
        }
    }
    else if (r.previous == "east")
    {
        if (r.try_south(maze))
        {
            return "south";
        }
        else if (r.try_west(maze))
        {
            return "west";
        }
        else if (r.try_north(maze))
        {
            return "north";
        }
    }
    else if (r.previous == "north")
    {
        if (r.try_east(maze))
        {
            return "east";
        }
        else if (r.try_south(maze))
        {
            return "south";
        }
        else if (r.try_west(maze))
        {
            return "west";
        }
    }
    return r.previous;
}

/*
  Since this is a vector of strings, first we specify `y` - the vertical position,
  then we specify `x` - the horizontal one. That's why we have the coordinates flipped like yx.
*/
void solve(std::vector<std::string> &maze, robot &r, size_t end_y, size_t end_x)
{
    bool solved = false;
    while (!solved)
    {
        display(maze);

        std::string go_to = decideWhereToMove(maze, r);

        // For every direction the robot goes, switch the characters on the map.
        if (go_to == "south")
        {
            maze[r.get_y() + 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curr_y = r.get_y();
            r.set_y(curr_y + 1);
            r.previous = "north";
        }
        else if (go_to == "west")
        {
            maze[r.get_y()][r.get_x() - 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curr_x = r.get_x();
            r.set_x(curr_x - 1);
            r.previous = "east";
        }
        else if (go_to == "north")
        {
            maze[r.get_y() - 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curr_y = r.get_y();
            r.set_y(curr_y - 1);
            r.previous = "south";
        }
        else if (go_to == "east")
        {
            maze[r.get_y()][r.get_x() + 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curr_x = r.get_x();
            r.set_x(curr_x + 1);
            r.previous = "west";
        }

        if (r.get_y() == end_y && r.get_x() == end_x)
        {
            solved = true;
        }

        // Control how fast the "animation goes"
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        printf("\033c");
    }
}

int main()
{
    // Load a txt map that is a maze in ascii characters.
    // The robot should be denoted by a character - R, the exit by - E
    std::vector<std::string> maze = load_maze("maze.txt");
    std::vector<int> pos = find(maze, 'R');
    std::vector<int> end = find(maze, 'E');

    robot r(pos[0], pos[1]);

    solve(maze, r, end[1], end[0]);

    std::cout << "Solved!" << std::endl;

    return 0;
}
