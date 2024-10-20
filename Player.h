#ifndef PLAYER_H
#define PLAYER_H

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

    int getMoves() const;
    void decrementMoves();

    bool isAlive() const;
    void setAlive(bool aliveStatus);

    bool hasKeyStatus() const;
    void setKeyStatus(bool status);

    // reset the player's status
    void reset();
};

#endif // PLAYER_H
