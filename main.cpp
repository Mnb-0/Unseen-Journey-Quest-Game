#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <cstdlib>
#include "Maze.h"
#include "Cell.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    Maze maze;
    cout << "Enter level:\n";
    int lvl;
    cin >> lvl;

    maze.levelSet(lvl);
    maze.printMaze();

    return 0;
}
