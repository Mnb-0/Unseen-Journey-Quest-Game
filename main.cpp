#include <iostream>
#include <ncurses.h>

using namespace std;

class Cell
{
public:
    Cell *right;
    Cell *left;
    Cell *up;
    Cell *down;
    char data;
/* data used to represent different items:
 * '.' - empty space
 * '#' - wall
 * 'P' - player
 * 'B' - bomb
 * 'E' - exit
 * 'C' - coin
 */
    Cell()
    {
        right = nullptr;
        left = nullptr;
        up = nullptr;
        down = nullptr;
        data = '.';
    }

    Cell(char data)
    {
        right = nullptr;
        left = nullptr;
        up = nullptr;
        down = nullptr;
        this -> data = data;
    }

    void moveRight()
    {
        if(right != nullptr)
        {
            data = '.';
            right -> data = 'P';
        }
    }

    void moveLeft()
    {
        if(left != nullptr)
        {
            data = '.';
            left -> data = 'P';
        }
    }

    void moveUp()
    {
        if(up != nullptr)
        {
            data = '.';
            up -> data = 'P';
        }
    }

    void moveDown()
    {
        if(down != nullptr)
        {
            data = '.';
            down -> data = 'P';
        }
    }

    bool checkEdge() const
    {
        if(right == nullptr || left == nullptr || up == nullptr || down == nullptr)
        {
            return true;
        }
        return false;
    }


};

int main()
{
    initscr(); // Start ncurses mode
    // printw("Hello!");
    // refresh();               // Print it on to the real screen
    // getch();                 // Wait for user input
    endwin(); // End ncurses mode
    return 0;
}
