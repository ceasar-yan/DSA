#include "StudentCRUD.hpp"
#include <cstddef>
#include <cstdlib>
#include <print>
#include <ncurses.h>

using namespace std;

int main() {
  bool exit {false};
  const size_t MAX_SIZE {50};
  Student student[MAX_SIZE];

  int currentCount {};

  const size_t MAX_OPT {5};
  string options[MAX_OPT] {"ADD Student", "Display Students", "Update Student", "Delete Student", "Exit"};
  int hover {0};
  int selected {0};
  int nav {};

  const string TITLE[] {
" ____  _             _            _      ____ ____  _   _ ____",
"/ ___|| |_ _   _  __| | ___ _ __ | |_   / ___|  _ \\| | | |  _ \\",
"\\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| | |   | |_) | | | | | | |",
" ___) | |_| |_| | (_| |  __/ | | | |_  | |___|  _ <| |_| | |_| |",
"|____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|  \\____|_| \\_\\___/|____/",
  };


  // String NCURSES
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  while (!exit) {
    clear();
    refresh();

    for (const auto &i : TITLE) {
      printw("%s\n", i.c_str());
    }
    printw("\n");

    for (int i {0}; i < MAX_OPT; i++) {
      if (i == hover) {
        attron(COLOR_PAIR(1));
        printw("==> %s <==\n", options[i].c_str());
        attroff(COLOR_PAIR(1));
      } else 
        printw(" %s \n", options[i].c_str());
    }

    attron(COLOR_PAIR(2));
    printw("\nUse 'J' & 'K' for Navigation");
    attroff(COLOR_PAIR(2));

    nav = getch();
    if ((nav == 'j' || nav == 'J') && hover != 4) ++hover;
    if ((nav == 'k' || nav == 'K') && hover != 0) --hover;
    if (nav == '\n' || nav == '\r') selected = hover + 1;
    if (nav == '\n' || nav == '\r' || nav == KEY_ENTER) selected = hover +1;
    
    switch (selected) {
      case 1: 
        break;
      case 2: 
        break;
      case 3: 
        break;
      case 4: 
        break;
      case 5: 
        print("Exit Success!\n");
        exit = true;
        break;
      default: 
        selected = 0;
        break;
    }
  }

  endwin();
  return 0;
}
