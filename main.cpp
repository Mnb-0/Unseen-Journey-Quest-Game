#include <iostream>
#include <cstdlib>
#include <ctime>
// #include <ncurses.h>
#include "Cell.h"
using namespace std;

int distance(Cell *start, Cell *end)
{
    //work in progress. BFS or DFS?
}



class Player
{
    Cell *currentCell;
    int score;
    int movesRem;
    int undoRem;
    bool keyFound;

public:
    Player(Cell *start, int level) : currentCell(start), score(0), keyFound(false) 
    {
        if(level == 1)
        {
            movesRem = 10;
            undoRem = 3;
        }
        else if(level == 2)
        {
            movesRem = 15;
            undoRem = 5;
        }
        else if(level == 3)
        {
            movesRem = 20;
            undoRem = 7;
        }
    }

    void moveRight()
    {
        if (currentCell->right != nullptr)
        {
            currentCell = currentCell->right;
            if (currentCell->data == 'C')
            {
                score++;
            }
            movesRem--;
        }
    }

    void moveLeft()
    {
        if (currentCell->left != nullptr)
        {
            currentCell = currentCell->left;
            if (currentCell->data == 'C')
            {
                score++;
            }
            movesRem--;
        }
    }

    void moveUp()
    {
        if (currentCell->up != nullptr)
        {
            currentCell = currentCell->up;
            if (currentCell->data == 'C')
            {
                score++;
            }
            movesRem--;
        }
    }

    void moveDown()
    {
        if (currentCell->down != nullptr)
        {
            currentCell = currentCell->down;
            if (currentCell->data == 'C')
            {
                score++;
            }
            movesRem--;
        }
    }

    void undoMove()
    {
        if (undoRem > 0)
        {
            currentCell = currentCell->up;
            score--;
            movesRem++;
            undoRem--;
        }
    }

    void collectKey()
    {
        keyFound = true;
    }

    void printStats()
    {
        cout << "Score: " << score << endl;
        cout << "Moves Remaining: " << movesRem << endl;
        cout << "Undos Remaining: " << undoRem << endl;
        cout << "Key Found: " << (keyFound ? "Yes" : "No") << endl;
    }
};
class Maze
{
    int size;        // Size of the maze (n x n grid)
    Cell *startUp;   // Top-left corner
    Cell *endUp;     // Top-right corner
    Cell *startDown; // Bottom-left corner
    Cell *endDown;   // Bottom-right corner
    Cell *player;    // Player's position in the maze

public:
    Maze() : size(0), startUp(nullptr), endUp(nullptr), startDown(nullptr), endDown(nullptr), player(nullptr) {}

    // Parameterized constructor
    Maze(int size)
    {
        this->size = size;
        startUp = createMaze();
        player = startUp;
    }

    // Maze is a 2D grid of linked cells
    Cell *createMaze()
    {
        Cell *rowStart = nullptr;
        Cell *prevRow = nullptr;
        Cell *current = nullptr;

        for (int i = 0; i < size; i++)
        {
            Cell *rowHead = nullptr;
            Cell *prevCol = nullptr;

            for (int j = 0; j < size; j++)
            {
                Cell *newCell = new Cell(' ');

                if (j == 0)
                {

                    rowHead = newCell;
                    if (i == 0)
                        startUp = rowHead;
                }

                if (prevCol)
                {

                    prevCol->right = newCell;
                    newCell->left = prevCol;
                }
                prevCol = newCell;

                if (i > 0)
                {

                    current->down = newCell;
                    newCell->up = current;
                    current = current->right;
                }

                if (i == size - 1 && j == size - 1)
                {
                    endDown = newCell;
                }
            }

            prevRow = rowStart;
            rowStart = rowHead;
            current = rowHead;
        }

        return startUp;
    }

    // Insert data at a specific row and column
    void insertCell(int row, int col, char data)
    {
        //travel to specified row & col
        Cell *current = startUp;
        for (int i = 0; i < row; i++)
        {
            if (current->down != nullptr)
                current = current->down;
        }


        for (int j = 0; j < col; j++)
        {
            if (current->right != nullptr)
                current = current->right;
        }
        current->data = data;
        //this was originally going to be a node insertion function but I realized it was not needed
    }

    //visualization
    void printMaze()
    {
        Cell *row = startUp;
        while (row != nullptr)
        {
            Cell *col = row;
            while (col != nullptr)
            {
                cout << col->data << " ";
                col = col->right;
            }
            cout << endl;
            row = row->down;
        }
    }
};

int main()
{
    // initscr(); // Start ncurses mode
    //  printw("Hello!");
    //  refresh();               // Print it on to the real screen
    //  getch();                 // Wait for user input
    // endwin(); // End ncurses mode
    // Main to test maze class
    Maze maze(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            maze.insertCell(i, j, '.');
        }
    }

    maze.printMaze();
    return 0;
}
