#include <ncurses.h>
#include "Maze.h"
#include "Util.h"

Maze::Maze() : size(0), startUp(nullptr), endDown(nullptr) {}

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

void Maze::initializeMaze()
{
    int playerX = randomNumberGenerator(1, size - 2);
    int playerY = randomNumberGenerator(1, size - 2);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                insertCell(i, j, '#');
            }
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
    createMaze();
    initializeMaze();
    addCoins();
    addBombs();
    addKey();
    addExitDoor();
}

void Maze::placeEntity(char entity, int count)
{
    for (int i = 0; i < count; i++)
    {
        int x = randomNumberGenerator(1, size - 2);
        int y = randomNumberGenerator(1, size - 2);

        if (startUp->data != 'C' && startUp->data != 'P' && startUp->data != 'B' && startUp->data != 'K' && startUp->data != 'E')
        {
            insertCell(x, y, entity);
        }
        else
        {
            i--;
        }
    }
}

void Maze::setCells()
{
    Cell *temp = startUp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(temp->data == 'B')
            {
                temp->bomb = true;
                insertCell(i, j, '.');
            }
            else if(temp->data == 'C')
            {
                temp->coin = true;
            }
            else if(temp->data == 'K')
            {
                temp->key = true;
                insertCell(i, j, '.');
            }
            else if(temp->data == 'E')
            {
                temp->exit = true;
                insertCell(i, j, '.');
            }
        }
    }
}

void Maze::addCoins()
{
    placeEntity('C', 5);
}

void Maze::addBombs()
{
    placeEntity('B', 2);
}

void Maze::addKey()
{
    placeEntity('K', 1);
}

void Maze::addExitDoor()
{
    placeEntity('E', 1);
}

void Maze::insertCell(int row, int col, char data)
{
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

Cell *Maze::getStartUp()
{
    return this->startUp;
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
            mvprintw(y, x, "%c", col->data);
            col = col->right;
            x++;
        }
        row = row->down;
        y++;
    }
    refresh();
}
