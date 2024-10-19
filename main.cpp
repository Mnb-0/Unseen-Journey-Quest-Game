#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <cstdlib>
#include "Maze.h"
#include "Cell.h"
#include "Util.h"

using namespace std;

//start working on move stack

class Player
{
    Cell *playerCurrent;
    Cell *playerPrev; // To make undos easier
    bool hasKey;
    bool alive;
    int score;
    int moves;
    int undos;

public:
    Player(Cell *start = nullptr) : playerCurrent(start), playerPrev(nullptr), hasKey(false), score(false), alive(true), moves(0), undos(0) {}

    void setKey(bool hasKey) { this->hasKey = hasKey; }
    bool getKey() { return this->hasKey; }

    void setScore(int score) { this->score = score; }
    void incrementScore(int score) { this->score += score; }
    int getScore() { return this->score; }

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

    int calculateScore()
    {
        if (int x = getMoves() != 0)
        {
            incrementScore(2 * x);
        }
        return score;
    }

    void movePlayer(char direction)
    {
        playerPrev = playerCurrent;
        switch (toLowerCase(direction))
        {
        case 'w':
            if (playerCurrent->up != nullptr && playerCurrent->up->data != '#')
            {
                playerCurrent = playerCurrent->up;
                decrementMoves();
            }
            break;
        case 'a':
            if (playerCurrent->left != nullptr && playerCurrent->left->data != '#')
            {
                playerCurrent = playerCurrent->left;
                decrementMoves();
            }
            break;
        case 's':
            if (playerCurrent->down != nullptr && playerCurrent->down->data != '#')
            {
                playerCurrent = playerCurrent->down;
                decrementMoves();
            }
            break;
        case 'd':
            if (playerCurrent->right != nullptr && playerCurrent->right->data != '#')
            {
                playerCurrent = playerCurrent->right;
                decrementMoves();
            }
            break;
        default:
            break;
        }
    }
};
int main()
{
    srand(static_cast<unsigned>(time(0)));
    initscr();   // Start ncurses
    noecho();    // Don't echo any keypresses
    curs_set(0); // Hide cursor
    Maze maze;
    maze.levelSet(1);
    maze.printMaze();
    getch();  // Wait for user input
    endwin(); // End ncurses

    return 0;
}
