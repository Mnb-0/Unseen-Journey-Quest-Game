#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cell.h"
#include <ncurses.h>
using namespace std;

int randomNumberGenerator(int, int); // Generates a random number between x and y

class Maze
{
    int size;
    Cell *startUp;
    Cell *endDown;

public:
    Maze() : size(0), startUp(nullptr), endDown(nullptr) {}

    // maze creation and linking
    void createMaze()
    {
        startUp = nullptr;
        Cell *prevRow = nullptr;

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

                // Link horizontally (left-right)
                if (prevCol)
                {
                    prevCol->right = newCell;
                    newCell->left = prevCol;
                }
                prevCol = newCell;

                // Link vertically (up-down)
                if (i > 0 && prevRow)
                {
                    Cell *above = prevRow;
                    for (int k = 0; k < j; k++)
                        above = above->right;

                    above->down = newCell;
                    newCell->up = above;
                }
            }

            prevRow = rowHead;
        }
    }

    void initializeMaze()
    {
        // Randomly place the player
        int playerX = randomNumberGenerator(1, size - 2);
        int playerY = randomNumberGenerator(1, size - 2);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // Set walls on edges
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                {
                    insertCell(i, j, '#');
                }
                // Set the player starting position
                else if (i == playerX && j == playerY)
                {
                    insertCell(i, j, 'P');
                }
                else
                {
                    insertCell(i, j, '.');
                }
            }
        }
    }

    void levelSet(int lvl)
    {
        switch (lvl)
        {
        case 1:
            size = 10;
            break;
        case 2:
            size = 15;
            break;
        case 3:
            size = 20;
            break;
        default:
            cout << "Invalid level\n";
            return;
        }

        createMaze(); // Initialize the maze grid
        initializeMaze();
        addCoins(); // Add coins to the maze
        addBombs(); // Add bombs to the maze
    }

    void addCoins()
    {
        // Arrays to store x y coordinates of coins
        int coinLocX[5];
        int coinLocY[5];

        for (int i = 0; i < 5; i++)
        {
            // no coins at spawn point
            coinLocX[i] = randomNumberGenerator(1, size - 2);
            coinLocY[i] = randomNumberGenerator(1, size - 2);
            // put coins at coordinates if coin already not there
            if (startUp->data != 'C' && startUp->data != 'P' && startUp->data != 'B')
            {
                insertCell(coinLocX[i], coinLocY[i], 'C');
            }
            else
            {
                i--;
            }
        }
    }

    void addBombs()
    {
        int bombLocX[4];
        int bombLocY[4];

        for (int i = 0; i < 4; i++)
        {
            // no bombs at spawn point
            bombLocX[i] = randomNumberGenerator(1, size - 2);
            bombLocY[i] = randomNumberGenerator(1, size - 2);

            if (startUp->data != 'C' && startUp->data != 'P' && startUp->data != 'B')
            {
                insertCell(bombLocX[i], bombLocY[i], 'B');
            }
            else
            {
                i--;
            }
        }
    }

    // Insert data at a specific row and column
    void insertCell(int row, int col, char data)
    {
        // travel to specified row & col
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
    }

    // visualization
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
    srand(static_cast<unsigned>(time(0)));
    Maze maze;
    cout << "Enter level:\n";
    int lvl;
    cin >> lvl;
    maze.levelSet(lvl);
    maze.printMaze();

    return 0;
}

int randomNumberGenerator(int x, int y)
{
    return x + rand() % (y - x + 1);
}