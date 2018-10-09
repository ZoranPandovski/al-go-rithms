# Simple Maze Solver

This is a simple maze solver, implementing the "Wall Follower" method to solve a maze.

### Wall Follower method

This method is also known as either the "left-hand" rule or the "right-hand" rule. If the maze is [simply connected](https://en.wikipedia.org/wiki/Simply_connected_space), that is, all its walls are connected together or to the maze's outer boundary, then by keeping one hand in contact with one wall of the maze the solver is guaranteed not to get lost and will reach a different exit if there is one; otherwise, he or she will return to the entrance having traversed every corridor next to that connected section of walls at least once.

### Implementation

The current implementation follows the left side of the walls. The solver is a small robot called "Frank", denoted by `R` on the map, the exit is respectively - `E`. Since we can look the maze from the top, we can orient ourselves by the coordinates - **south**, **west**, **north**, **east**, and **from** (this indicates the previous position from where the robot came - eg. if we are moving to the **west** then we came from the **east**, if we are moving to the south, then we are coming from the **north**).

Here is how the algorithm works:

1. Find where the robot and the exit are.
2. Move the robot to the next position:
   1. If it's coming from the **south** (i.e from the bottom of the maze), then try to go to the **west**.
   2. If there is a wall (denoted by a `#`), then go to the **north**.
   3. If there is a wall as well there, then go to the **east**.
   4. If that fails, then come back from where you came from.
   5. Check if the robot found the exit.
3. Repeat.

---

The **maze** is generated from [here](https://www.thenerdshow.com/amaze.html?rows=10&cols=10&color=FF0000&bgcolor=000000&sz=10px&blank=+&wall=%3Cem%3E%23%3C%2Fem%3E), then it's pasted into a `.txt` file and loaded into the maze solver.

### How to run

Get the source code and some maze (with ASCII characters).

Compile the code

```bash
g++ simple_maze_solver.cpp -o sms
```

Then run the program from a terminal window

```bash
./sms
```
