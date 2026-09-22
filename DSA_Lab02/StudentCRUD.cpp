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
void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();

int main() {
  const size_t MAX_SIZE {5};
  Student student[MAX_SIZE];
  int currentCount {0};

  bool exit {false};
  system("clear");

  do {
    system("echo -e \"\e[34m$(figlet 'Student CRUD')\033[0m\"");
  
    exit = true;
  } while (!exit);

  return 0;
}
