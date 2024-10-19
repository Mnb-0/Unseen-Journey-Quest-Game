#include "Util.h"
#include <cstdlib>

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