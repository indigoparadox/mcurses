
#include "mcurses.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <termios.h>

void musleep( int us ) {
    while( 0 < us ) {
        us--;
    }
}

int getch() {
    fd_set ttys;
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    FD_ZERO( &ttys );
    FD_SET( STDIN_FILENO, &ttys );

    select( STDIN_FILENO + 1, &ttys, NULL, NULL, &timeout );

    if( FD_ISSET( 0, &ttys ) ) {
        return fgetc( stdin );
    } else {
        return 0;
    }
}

void mvaddch( char c, int x, int y ) {
    printf( "\033[%d;%dH", y, x );
    printf( "%c", c );
}

void clear() {
    printf( "\033[2J" );
}

void initscr() {
    struct termios tty_state;
    tcgetattr( STDIN_FILENO, &tty_state );
    tty_state.c_lflag &= ~(ICANON | ECHO);
    tty_state.c_cc[VMIN] = 1;
    tcsetattr( STDIN_FILENO, TCSANOW, &tty_state );
    printf( "\e[?25l" );
}

void endwin() {
    struct termios tty_state;
    tcgetattr( STDIN_FILENO, &tty_state );
    tty_state.c_lflag |= ICANON | ECHO;
    tcsetattr( STDIN_FILENO, TCSANOW, &tty_state );
    printf( "\e[?25h" );
}
