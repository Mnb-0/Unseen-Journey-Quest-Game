#include "DS_B_i232623_Player.h"
#include "DS_B_i232623_Maze.h"

Player::Player() : score(0), undos(3), moves(10), alive(true), hasKey(false) {}

// setters and getters

int Player::getScore() const
{
    return score;
}

void Player::setScore(int newScore)
{
    score = newScore;
}

int Player::getUndos() const
{
    return undos;
}

void Player::setUndos(int newUndos)
{
    undos = newUndos;
}

void Player::decrementUndos()
{
    if (undos > 0)
    {
        undos--;
    }
}

int Player::getMoves() const
{
    return moves;
}

void Player::decrementMoves()
{
    if (moves > 0)
    {
        moves--;
    }
}

bool Player::isAlive() const
{
    return alive;
}

void Player::setAlive(bool aliveStatus)
{
    alive = aliveStatus;
}

bool Player::hasKeyStatus() const
{
    return hasKey;
}

void Player::setKeyStatus(bool status)
{
    hasKey = status;
}

// reset the player's status
void Player::reset()
{
    score = 0;
    undos = 3;
    moves = 10;
    alive = true;
    hasKey = false;
}

void Player::set(Maze &maze)
{
    score = 0;
    alive = true;
    hasKey = false;
    if (maze.getLevel() == 1)
    {
        undos = 6;
        moves = maze.manhattanDistance('P', 'E') + 6 + maze.manhattanDistance('K', 'E');
    }
    else if (maze.getLevel() == 2)
    {
        undos = 4;
        moves = maze.manhattanDistance('P', 'E') + 2 + maze.manhattanDistance('K', 'E');
    }
    else if (maze.getLevel() == 3)
    {
        undos = 0;
        moves = maze.manhattanDistance('P', 'E') + maze.manhattanDistance('K', 'E');
    }
}