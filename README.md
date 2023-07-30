
# C++ Minesweeper

This project is a fun and challenging implementation of the timeless Minesweeper game written in C++. Minesweeper is a single-player puzzle game where the objective is to clear a rectangular grid without detonating any hidden mines. By revealing cells on the board, you'll be provided with numeric hints indicating how many adjacent mines are present, helping you strategically uncover the safe areas.


## Features


- Allow the user to input an integer value N and generate an NxN square board.
- Store the values of each cell in the board within an NxN matrix.
- Generate N random and distinct positions within the matrix and place the "mines" (value -1).
- Fill the remaining cells of the matrix with the number of mines located in their neighboring cells (eight potential positions: above, below, left, right, and the four corners).
- Once the matrix is filled, show the user a representation of the board without revealing its contents.

The game perform the following tasks:
- Request the user to input the coordinates (x, y) of the cell they wish to uncover.
- If the cell contains a mine, the game ends, and the player loses.
- If the cell contains a value greater than zero (i.e., it is adjacent to at least one mine), display that value in the corresponding position on the board.
- If the cell contains a value of zero (a cell with no adjacent mines), reveal the values of this cell and all cells in a straight line (vertical, horizontal, diagonal, and inverse diagonal) in all directions (up, down, left, right) until reaching cells with values greater than zero or reaching the board's edge.
- In the previous step, it is never possible to encounter a mine since doing so would require passing through a cell with a value greater than zero, which would halt the exploration in that direction.
- If the user manages to uncover all cells that do not contain mines, they win the game.
- At the end, always display the contents of the board and a message indicating whether the user won or lost the game.

## Installation

To run this program, you must have a C++ compiler installed on your system.

1. Clone the  repository to your local machine using the command:

```bash
git clone https://github.com/KevinInkjet/C-Minesweeper
```

2. Compile the source code using the following command:

```bash
g++ -o Minesweeper Bscmns.cpp
```

3. Run the program using the command:

```bash
./Minesweeper
```

