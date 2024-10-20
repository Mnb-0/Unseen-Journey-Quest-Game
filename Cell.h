#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    char data;
    Cell *right, *left, *up, *down;
    bool exit, key, coin, bomb;

    // Constructors
    Cell();
    Cell(char data);

    // Movement functions
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    
    bool checkEdge() const;
};

#endif // CELL_H
