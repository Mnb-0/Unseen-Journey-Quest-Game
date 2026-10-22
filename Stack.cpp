#include "Stack.h"

Stack::Stack() : top(nullptr) {}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

void Stack::push(const Move &move)
{
    Node *newNode = new Node(move);
    newNode->next = top; // linkingh new node to the previous top
    top = newNode;       // update top
}

Move Stack::pop()
{
    if (isEmpty())
    {
        return Move(-1, -1, ' '); // stack is empty
    }
    Node *temp = top;
    Move poppedMove = temp->move;
    top = top->next;
    delete temp;
    return poppedMove;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}
