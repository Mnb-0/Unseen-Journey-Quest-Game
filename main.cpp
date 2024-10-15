#include <ncurses.h>

int main() {
    initscr();               // Start ncurses mode
    printw("Hello, ncurses!"); // Print Hello, World
    refresh();               // Print it on to the real screen
    getch();                 // Wait for user input
    endwin();                // End ncurses mode
    return 0;
}
