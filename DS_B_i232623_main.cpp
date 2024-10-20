#include <iostream>
#include <ctime>
#include <ncurses.h>
#include "DS_B_i232623_Cell.h"
#include "DS_B_i232623_Maze.h"
#include "DS_B_i232623_Player.h"
#include "DS_B_i232623_Stack.h"
#include "DS_B_i232623_Util.h"

// function to display the player's current status
void displayStatus(Player &player)
{
    mvprintw(21, 0, "Key Status: %s", player.hasKeyStatus() ? "Obtained" : "Not Obtained");
    mvprintw(22, 0, "Remaining Moves: %d", player.getMoves());
    mvprintw(23, 0, "Undos Left: %d", player.getUndos());
    mvprintw(24, 0, "Score: %d", player.getScore());
}

int main()
{
    // initialize ncurses and the maze
    srand(static_cast<unsigned int>(time(0)));
    initscr();            // initialize the screen
    noecho();             // don't echo key presses
    cbreak();             // disable line buffering
    keypad(stdscr, TRUE); // enable keypad
    clear();              // clear the screen at the beginning

    Maze maze;
    int level;
    printw("Enter maze level (1, 2, or 3): ");
    refresh();
    maze.levelSet(lvlInput(level));

    Player player;
    player.set(maze);

    // main game loop for player movement
    int ch;
    Cell *playerCell = maze.findPlayer();

    clear();
    maze.printMaze();
    displayStatus(player);
    refresh();

    while ((ch = getch()) != 'q')
    {
        Cell *nextCell = nullptr;

        switch (ch)
        {
        case 'w': // Move up
            if (playerCell->up != nullptr && playerCell->up->data != '#')
            {
                nextCell = playerCell->up;
                playerCell->moveUp();
                playerCell = nextCell;
                player.decrementMoves();
            }
            break;
        case 'a':                                                             // Move left
            if (playerCell->left != nullptr && playerCell->left->data != '#') // Check if the next cell is not a wall
            {
                nextCell = playerCell->left;
                playerCell->moveLeft();
                playerCell = nextCell;
                player.decrementMoves();
            }
            break;
        case 's':                                                             // Move down
            if (playerCell->down != nullptr && playerCell->down->data != '#') // Check if the next cell is not a wall
            {
                nextCell = playerCell->down;
                playerCell->moveDown();
                playerCell = nextCell;
                player.decrementMoves();
            }
            break;
        case 'd':                                                               // Move right
            if (playerCell->right != nullptr && playerCell->right->data != '#') // Check if the next cell is not a wall
            {
                nextCell = playerCell->right;
                playerCell->moveRight();
                playerCell = nextCell;
                player.decrementMoves();
            }
            break;
        default:
            break;
        }

        // player collects a coin
        if (playerCell->coin)
        {
            player.setScore(player.getScore() + 2);
            player.setUndos(player.getUndos() + 1);
            playerCell->coin = false;
        }

        // game over conditions after moving
        if (playerCell->isBomb())
        {
            player.setAlive(false);
            break; // End the game
        }

        if (player.getMoves() <= 0)
        {
            // all moves without reaching the exit
            player.setAlive(false);
            break;
        }

        if (playerCell->isExit() && player.hasKeyStatus())
        {
            // reached exit with the key
            clear();
            printw("You win! You've reached the exit with the key!\n");
            break;
        }

        clear();
        maze.printMaze();

        // player status
        displayStatus(player);

        refresh();
    }

    // Game Over message if the player is not alive or out of moves
    clear();
    if (!player.isAlive() && player.getMoves() > 0)
    {
        printw("Game Over! You hit a bomb.\n");
    }
    else if (player.getMoves() <= 0)
    {
        printw("Game Over! You ran out of moves.\n");
    }

    refresh();
    getch(); // wait for input before exitting
    endwin();
    return 0;
}
