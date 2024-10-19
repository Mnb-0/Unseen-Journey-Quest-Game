#include "Util.h"
#include <cstdlib>

int randomNumberGenerator(int x, int y) {
    return x + rand() % (y - x + 1);
}
