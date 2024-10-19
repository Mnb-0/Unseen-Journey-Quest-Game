#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <cstdlib>
#include "Maze.h"
#include "Cell.h"

using namespace std;

class Player
{
    Cell *playerCurrent;
    Cell *playerPrev; // To make undos easier
    bool hasKey;
    bool score;
    bool alive;
    int moves;
    int undos;

public:
    Player(Cell *start=nullptr) : playerCurrent(start), playerPrev(nullptr), hasKey(false), score(false), alive(true), moves(0), undos(0) {}

    void setKey(bool hasKey) { this->hasKey = hasKey; }
    bool getKey() { return this->hasKey; }

    void setScore(bool score) { this->score = score; }
    void incrementScore() { this->score += 20; }
    bool getScore() { return this->score; }

    void setAlive(bool alive) { this->alive = alive; }
    bool getAlive() { return this->alive; }

    void setMoves(int moves) { this->moves = moves; }
    void incrementMoves() { this->moves++; }
    void decrementMoves() { this->moves--; }
    int getMoves() { return this->moves; }

    void setUndos(int undos) { this->undos = undos; }
    void incrementUndos() { this->undos++; }
    void decrementUndos() { this->undos--; }
    int getUndos() { return this->undos; }


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
