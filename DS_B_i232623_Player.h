#ifndef PLAYER_H
#define PLAYER_H

#include "DS_B_i232623_Maze.h"
class Player
{
private:
    int score;
    int undos;
    int moves;
    bool alive;
    bool hasKey;

public:
    Player();

    int getScore() const;
    void setScore(int score);

    int getUndos() const;
    void decrementUndos();
    void setUndos(int newUndos);

    int getMoves() const;
    void decrementMoves();

    bool isAlive() const;
    void setAlive(bool aliveStatus);

    bool hasKeyStatus() const;
    void setKeyStatus(bool status);

    // reset the player's status
    void reset();
    void set(Maze &maze);
};

#endif // PLAYER_H
