#ifndef MAZE_H
#define MAZE_H

#include "Cell.h"

class Maze
{
private:
    int size;
    int lvl;
    Cell *startUp, *endDown;

    void createMaze();
    void initializeMaze();
    void addCoins();
    void addBombs();
    void addKey();
    void addExitDoor();
    void place(char entity, int count);
    void insertCell(int row, int col, char data);

public:
    Maze();
    void levelSet(int lvl);
    void printMaze();
    Cell *getStartUp();
    int getLevel();
    int manhattanDistance(char entity1, char entity2);
    void findEntity(char entity, int &row, int &col);
    Cell *findPlayer();
};

#endif // MAZE_H
