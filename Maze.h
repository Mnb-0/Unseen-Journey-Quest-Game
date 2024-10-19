#ifndef MAZE_H
#define MAZE_H

#include "Cell.h"

class Maze {
    int size;
    Cell *startUp;
    Cell *endDown;

public:
    Maze();
    void createMaze();
    void initializeMaze();
    void levelSet(int lvl);
    void placeEntity(char entity, int count);
    void addCoins();
    void addBombs();
    void addKey();
    void addExitDoor();
    void insertCell(int row, int col, char data);
    void printMaze();
};

#endif
