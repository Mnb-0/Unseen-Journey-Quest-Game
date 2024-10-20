#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "DS_B_i232623_Maze.h"
#include "DS_B_i232623_Util.h"

Maze::Maze() : lvl(0),size(0), startUp(nullptr), endDown(nullptr) {}

void Maze::createMaze()
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

            // link horizontally (left-right)
            if (prevCol)
            {
                prevCol->right = newCell;
                newCell->left = prevCol;
            }
            prevCol = newCell;

            // link vertically (up-down)
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

int Maze::getLevel()
{
    return lvl;
}

void Maze::initializeMaze()
{
    int playerX = randomNumberGenerator(1, size - 2);
    int playerY = randomNumberGenerator(1, size - 2);
    int keyX, keyY;

    // key in different location than the player
    do
    {
        keyX = randomNumberGenerator(1, size - 2);
        keyY = randomNumberGenerator(1, size - 2);
    } while (playerX == keyX && playerY == keyY);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                insertCell(i, j, '#'); // wall
            }
            else if (i == playerX && j == playerY)
            {
                insertCell(i, j, 'P'); // player
            }
            else if (i == keyX && j == keyY)
            {
                insertCell(i, j, 'K'); // key
            }
            else
            {
                insertCell(i, j, '.'); // empty
            }
        }
    }
}

void Maze::levelSet(int lvl)
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
        printw("Invalid level\n");
        return;
    }
    this->lvl = lvl;
    createMaze();
    initializeMaze();
    addCoins();
    addBombs();
    addKey();
    addExitDoor();
}

void Maze::place(char entity, int count)
{
    for (int i = 0; i < count; i++)
    {
        int x = randomNumberGenerator(1, size - 2);
        int y = randomNumberGenerator(1, size - 2);

        // ensure the cell is empty
        Cell *current = startUp;
        for (int row = 0; row < x; row++)
            current = current->down;

        for (int col = 0; col < y; col++)
            current = current->right;

        if (current->data != 'C' && current->data != 'P' && current->data != 'B' && current->data != 'K' && current->data != 'E')
        {
            current->data = entity;
        }
        else
        {
            i--; // retry
        }
    }
}

void Maze::addCoins()
{
    place('C', 5); // 5 coins
}

void Maze::addBombs()
{
    place('B', 2); // 2 bombs
}

void Maze::addKey()
{
    place('K', 1); // 1 key
}

void Maze::addExitDoor()
{
    place('E', 1); // 1 exit
}

// insert a cell with specified data into the maze
void Maze::insertCell(int row, int col, char data)
{
    Cell *current = startUp;
    for (int i = 0; i < row; i++)
    {
        current = current->down;
    }
    for (int j = 0; j < col; j++)
    {
        current = current->right;
    }
    current->data = data;
}

Cell *Maze::getStartUp()
{
    return startUp;
}

// Find the player's cell in the maze
Cell *Maze::findPlayer()
{
    Cell *rowHead = startUp;
    while (rowHead != nullptr)
    {
        Cell *colHead = rowHead;
        while (colHead != nullptr)
        {
            if (colHead->data == 'P')
                return colHead;
            colHead = colHead->right;
        }
        rowHead = rowHead->down;
    }
    return nullptr; // Player not found
}

void Maze::printMaze()
{
    Cell *row = startUp;
    int y = 0;
    while (row != nullptr)
    {
        Cell *col = row;
        int x = 0;
        while (col != nullptr)
        {
            mvaddch(y, x, col->data);
            col = col->right;
            x++;
        }
        row = row->down;
        y++;
    }
}

// find the coordinates entities in the maze
void Maze::findEntity(char entity, int &row, int &col)
{
    Cell *rowHead = startUp;
    int currentRow = 0;

    while (rowHead != nullptr)
    {
        Cell *colHead = rowHead;
        int currentCol = 0;

        while (colHead != nullptr)
        {
            if (colHead->data == entity)
            {
                row = currentRow;
                col = currentCol;
                return;
            }
            colHead = colHead->right;
            currentCol++;
        }
        rowHead = rowHead->down;
        currentRow++;
    }

    // if not found, set row and col to -1
    row = -1;
    col = -1;
}

// manhattan distance bw two entities
int Maze::manhattanDistance(char entity1, char entity2)
{
    int row1, col1, row2, col2;

    findEntity(entity1, row1, col1);

    findEntity(entity2, row2, col2);

    // if not found, return -1
    if (row1 == -1 || row2 == -1 || col1 == -1 || col2 == -1)
    {
        return -1;
    }

    return abs(row1 - row2) + abs(col1 - col2);
}
