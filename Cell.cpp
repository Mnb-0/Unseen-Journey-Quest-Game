//
// Created by Muneeb on 10/16/2024.
//

#include "Cell.h"
// Default constructor
Cell::Cell()
{
    right = nullptr;
    left = nullptr;
    up = nullptr;
    down = nullptr;
    exit = key = coin = bomb = false;
    data = '.';
    
}

// Constructor with character parameter
Cell::Cell(char data)
{
    right = nullptr;
    left = nullptr;
    up = nullptr;
    down = nullptr;
    exit = key = coin = bomb = false;
    this->data = data;
}

// Move player to the right cell
void Cell::moveRight()
{
    if (right != nullptr)
    {
        data = '.';
        right->data = 'P';
    }
}

// Move player to the left cell
void Cell::moveLeft()
{
    if (left != nullptr)
    {
        data = '.';
        left->data = 'P';
    }
}

// Move player to the up cell
void Cell::moveUp()
{
    if (up != nullptr)
    {
        data = '.';
        up->data = 'P';
    }
}

// Move player to the down cell
void Cell::moveDown()
{
    if (down != nullptr)
    {
        data = '.';
        down->data = 'P';
    }
}

// Check if the cell is at an edge
bool Cell::checkEdge() const
{
    if (right == nullptr || left == nullptr || up == nullptr || down == nullptr)
    {
        return true;
    }
    return false;
}