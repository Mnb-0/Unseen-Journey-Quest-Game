#include <cstdlib>
#include "Util.h"
#include <ncurses.h>
#include "Player.h"

int randomNumberGenerator(int x, int y)
{
    return x + rand() % (y - x + 1);
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

void abs(int &x)
{
    if (x < 0)
        x = -x;
}
int lvlInput(int level)
{
    while (true)
    {
        char input = getch();
        if (input >= '1' && input <= '3')
        {
            level = input - '0';
            return level;
        }
        else
        {
            printw("Invalid level! Please enter 1, 2, or 3: ");
            refresh();
        }
    }
}

