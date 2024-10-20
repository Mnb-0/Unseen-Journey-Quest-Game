#include <cstdlib>
#include "Util.h"

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
