#ifndef STACK_H
#define STACK_H

struct Move
{
    int x;    // x coordinate
    int y;    // y coordinate
    char dir; // direction

    Move(int x, int y, char dir) : x(x), y(y), dir(dir) {}
};

struct Node
{
    Move move;
    Node *next;

    Node(const Move &m) : move(m), next(nullptr) {}
};

// stack to manage undos
class Stack
{
private:
    Node *top;

public:
    Stack();
    ~Stack();

    void push(const Move &move); // add move to stack
    Move pop();                  // undo last move
    bool isEmpty() const;
};

#endif // STACK_H
