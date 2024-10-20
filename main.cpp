#include <iostream>
#include <ctime>
#include <ncurses.h>
#include "Maze.h"

int main()
{
    srand(time(0));
    initscr();            // ncurses start
    noecho();             // hide typed character
    cbreak();             // disable line buffering
    keypad(stdscr, TRUE); // enable arrow keys

    Maze maze;
    maze.levelSet(3);

    maze.printMaze();
    refresh();

    // Main game loop for player movement
    int ch;
    Cell *playerCell = maze.findPlayer();

    while ((ch = getch()) != 'q') // quit on 'q'
    {
        switch (ch)
        {
        case 'w':
            playerCell->moveUp();
            break;
        case 'a':
            playerCell->moveLeft();
            break;
        case 's':
            playerCell->moveDown();
            break;
        case 'd':
            playerCell->moveRight();
            break;
        default:
            break;
        }

        playerCell = maze.findPlayer();
        clear();
        maze.printMaze();
        refresh();
    }

    endwin(); // end ncurses
    return 0;
}
