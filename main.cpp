#include <iostream>
#include <ctime>
#include <ncurses.h>
#include "Cell.h"
#include "Maze.h"
#include "Player.h"
#include "Stack.h"


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
            printw("Invalid level! Please enter 1, 2, or 3: \n");
            refresh();
        }
    }
}

int main()
{
    // Initialize ncurses and the maze
    srand(time(0));
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    Maze maze;
    int level;
    printw("Enter maze level (1, 2, or 3): ");
    refresh();
    maze.levelSet(lvlInput(level));

    Player player;

    maze.printMaze();
    refresh();

    // main game loop for player movement
    int ch;
    Cell *playerCell = maze.findPlayer();

    while ((ch = getch()) != 'q')
    {
        switch (ch)
        {
        case 'w': // Move up
            if (playerCell->up != nullptr)
            {
                playerCell->moveUp();
                playerCell = playerCell->up;
                player.decrementMoves();
            }
            break;
        case 'a': // Move left
            if (playerCell->left != nullptr)
            {
                playerCell->moveLeft();
                playerCell = playerCell->left; 
                player.decrementMoves();       
            }
            break;
        case 's': // Move down
            if (playerCell->down != nullptr)
            {
                playerCell->moveDown();
                playerCell = playerCell->down; 
                player.decrementMoves();       
            }
            break;
        case 'd': // Move right
            if (playerCell->right != nullptr)
            {
                playerCell->moveRight();
                playerCell = playerCell->right; 
                player.decrementMoves();        
            }
            break;
        default:
            break;
        }

        // Check game over conditions
        if (playerCell->isBomb())
        {
            player.setAlive(false); 
            break;                  //end the game
        }

        if (player.getMoves() <= 0)
        {
            //player has used all moves without reaching the exit
            player.setAlive(false);
            break;
        }

        if (playerCell->isExit() && player.hasKeyStatus())
        {
            //player reached exit with the key
            printw("You win! You've reached the exit with the key!\n");
            break;
        }

        clear();
        maze.printMaze();
        refresh();
    }

    if (!player.isAlive() || player.getMoves() <= 0)
    {
        printw("Game Over! You lost.\n");
    }

    endwin();
    return 0;
}
