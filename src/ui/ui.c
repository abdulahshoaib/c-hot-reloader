// make a UI that hot-reloads the C program
// when ever there is a re-write in the files

#include "ui/ui.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

void ui_init(void) {
  initscr();
  if (has_colors()) {
    start_color();
  }
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  clear();

  init_pair(2, COLOR_RED, COLOR_BLACK);    // error
  init_pair(4, COLOR_YELLOW, COLOR_BLACK); // header

  attron(COLOR_PAIR(4) | A_BOLD);
  printw("C Hot Reloader - TUI\n");
  printw("=====================\n");
  attroff(COLOR_PAIR(4) | A_BOLD);

  refresh();
}

void ui_render_error(const char *err) {
  attron(COLOR_PAIR(2) | A_BOLD);
  printw("[ERROR] %s\n", err);
  attroff(COLOR_PAIR(2) | A_BOLD);
  refresh();
}

void ui_render_log(const char *msg) {
  attron(A_BOLD);
  printw("[LOG] %s\n", msg);
  attroff(A_BOLD);
  refresh();
}

void ui_render_log_a(const char *msg, const char *arg) {
  attron(A_BOLD);
  printw("[LOG] %s: %s\n", msg, arg);
  attroff(A_BOLD);
  refresh();
}

void ui_render_log_b(const char *msg, const int arg) {
  attron(A_BOLD);
  printw("[LOG] %s: %d\n", msg, arg);
  attroff(A_BOLD);
  refresh();
}

void ui_render_output(char *output) {
  attron(A_BOLD);
  printw("%s\n", output);
  attroff(A_BOLD);
  refresh();
}

void ui_cleanup(void) { endwin(); }

int ui_getinput(void) {
  int ch = getch();
  if (ch == 'q') {
    attron(A_BOLD);
    printw("Exiting...");
    attroff(A_BOLD);
    return -1;
  }
  return 0;
}
