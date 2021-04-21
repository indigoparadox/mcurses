
#ifndef MCURSES_H
#define MCURSES_H

void musleep( int us );
void mvaddch( char c, int x, int y );
void initscr();
void endwin();

#endif /* MCURSES_H */
