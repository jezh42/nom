/*********************************
 *    nom.c: NOM version 1.0.0   *
 *      Jeremy Hamann            *
 *********************************/

/* Version 1.0.0 - Cherry : NOM sends a cherry sliding across the screen */

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "nom.h"

int add_cherry(int x);
int my_mvaddstr(int y, int x, char *str);

int my_mvaddstr(int y, int x, char *str) {
  for ( ; x < 0; ++x, ++str)
    if (*str == '\0')  return ERR;
  for ( ; *str != '\0'; ++str, ++x)
    if (mvaddch(y, x, *str) == ERR)  return ERR;
  return OK;
}

int main(int argc, char *argv[]) {
  int x;

  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, TRUE);
  leaveok(stdscr, TRUE);
  scrollok(stdscr, FALSE);

  for (x = COLS - 1; ; --x) {
    if (add_cherry(x) == ERR) break;
    getch();
    refresh();
    usleep(40000);
  }

  mvcur(0, COLS - 1, LINES - 1, 0);
  endwin();

  return 0;
}

int add_cherry(int x) {

  static char *nom[CHERRYHEIGHT + 1] =
      {CHERRY1, CHERRY2, CHERRY3, CHERRY4, CHERRY5, CHERRY6, CHERRY7, CHERRY8,
       CHERRY9, CHERRY10, CHERRY11, CHERRY12, CHERRY13, CHERRY14, CHERRY15,
       CHERRY16, CHERRY17, CHERRY18, CHERRY19, CHERRY20, CHERRY21};

  int i, y;

  if (x < - CHERRYLENGTH)  return ERR;
  
  y = LINES / 5;

  for (i = 0; i <= CHERRYHEIGHT; ++i) {
    my_mvaddstr(y + i, x, nom[i]);
  }

  return OK;
}
