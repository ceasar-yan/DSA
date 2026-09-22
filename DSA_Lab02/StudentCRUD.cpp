#include <cstddef>
#include <cstdlib>
#include <print>
#include <iostream>

using namespace std;

struct Student {
  int id {};
  string name {};
  string course {};
  int yearLevel {};
};

// Function Declaration
char getch();
void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();

int main() {
  const size_t MAX_SIZE {5};
  Student student[MAX_SIZE];
  int currentCount {0};

  const size_t MAX_OPT {5}; 
  string opt[MAX_OPT] {"Add Student", "Display Students", "Update Student", "Delete Student", "Exit"};
  int hover {};
  int selected {};

  bool exit {false};
  system("clear");

  // UI LOOP
  do {
    system("echo -e \"\e[34m$(figlet 'Student CRUD')\033[0m\"");
    if (selected == 0) {
      for (int i {0}; i < MAX_OPT; i++) {
        if (i == hover) println("👉 {} 👈", opt[i]);
        else println(" {} ", opt[i]);
      }

      // vim up and down navigation
      println("\nNote: use 'J' & 'K' to Navigate Up and Down");
      char nav = getch();
      if ((nav == 'j' || nav == 'J') && (hover != MAX_OPT -1))
        ++hover;
      else if ((nav == 'k' || nav == 'K') && (hover != 0))
        --hover;
      else if (nav == '\n' || nav == '\r') 
        selected = hover +1;

    } else {
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
          println("Exited Successfully!");
          exit = true;
          break;

        default:
          selected = 0;
          break;
      }
    }
    system("clear");
  
    // exit = true;
  } while (!exit);

  return 0;
}

char getch() {
    char buffer {};
    std::cout << std::flush;
    system("stty -icanon -echo && setterm -cursor off");
    std::cin.get(buffer);
    system("stty sane && setterm -cursor on");
    
    return buffer;
}
