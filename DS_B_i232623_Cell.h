#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    char data;
    Cell *right, *left, *up, *down;
    bool exit, key, coin, bomb;

    // constructors
    Cell();
    Cell(char data);

    // movement functions
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    bool checkEdge() const;
    bool isBomb() const;
    bool isExit() const;
    bool isKey() const;
};

#endif // CELL_H
