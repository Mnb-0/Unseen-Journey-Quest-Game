#include "Cell.h"

Cell::Cell()
{
    right = nullptr;
    left = nullptr;
    up = nullptr;
    down = nullptr;
    exit = key = coin = bomb = false;
    data = '.';
}

Cell::Cell(char data)
{
    right = nullptr;
    left = nullptr;
    up = nullptr;
    down = nullptr;
    exit = key = coin = bomb = false;
    this->data = data;
}

// right cell
void Cell::moveRight()
{
    if (right != nullptr && right->data != '#') // prevent out of bounds move
    {
        right->data = 'P';
        data = '.';
    }
}

// left cell
void Cell::moveLeft()
{
    if (left != nullptr && left->data != '#') // prevent out of bounds move
    {
        left->data = 'P';
        data = '.';
    }
}

// up cell
void Cell::moveUp()
{
    if (up != nullptr && up->data != '#') // prevent out of bounds move
    {
        up->data = 'P';
        data = '.';
    }
}

void Cell::moveDown()
{
    if (down != nullptr && down->data != '#') // prevent out of bounds move
    {
        down->data = 'P';
        data = '.';
    }
}

// check if the cell is an edge cell
bool Cell::checkEdge() const
{
    return right == nullptr || left == nullptr || up == nullptr || down == nullptr;
}

bool Cell::isBomb() const
{
    return bomb;
}

bool Cell::isExit() const
{
    return exit;
}

bool Cell::isKey() const
{
    return key;
}