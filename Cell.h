//
// Created by Muneeb on 10/16/2024.
//

#ifndef DSA_2_CELL_H
#define DSA_2_CELL_H

class Cell
{
public:
    Cell *right;
    Cell *left;
    Cell *up;
    Cell *down;
    bool bomb;
    bool coin;
    bool key;
    bool exit;
    char data;

    // Constructors
    Cell();
    Cell(char data);

    // Movement methods
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    // Utility method
    bool checkEdge() const;
};

#endif // DSA_2_CELL_H
