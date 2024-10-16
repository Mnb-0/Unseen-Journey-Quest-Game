#include <iostream>
#include <ncurses.h>
#include "Cell.h"
using namespace std;

class Maze
{
    int size;
    Cell* startUp;
    Cell* endUp;
    Cell* startDown;
    Cell* endDown;
    Cell* player;
    
    
    public:
    
    Maze(): size(0), startUp(nullptr), endUp(nullptr), startDown(nullptr),endDown(nullptr),player(nullptr) {}
    
    //Maze is a multi-dimensional linked list of cells
    Maze(int size)//Initializes maze
    {
        this->size = size;
        //Established the maze using four pointers at four corners of the maze
        //Can travel in all four directions
        startUp->right = endUp;
        endUp->left = startUp;
        startUp->down = startDown;
        endUp->down = endDown;
        startDown->right = endDown;
        endDown->left = startDown;
        startDown->up = startUp;
        endDown->up = endUp;
        player = startUp;
    }

    //Insert a cell with data at a specific row and column
    void insertCell(int row, int col, char data)
    {
        Cell* temp = new Cell(data);
        Cell* current = startUp;
        for(int i = 0; i < row; i++)
        {
            current = current->down;
        }
        for(int i = 0; i < col; i++)
        {
            current = current->right;
        }
        //Have to add links
        temp->right = current->right;
        temp->left = current;
        current->right->left = temp;
        current->right = temp;
    }
};

int main()
{
    //initscr(); // Start ncurses mode
    // printw("Hello!");
    // refresh();               // Print it on to the real screen
    // getch();                 // Wait for user input
    //endwin(); // End ncurses mode

    return 0;
}
