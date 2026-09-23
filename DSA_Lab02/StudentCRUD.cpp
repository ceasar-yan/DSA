#include <cstddef>
#include <cstdlib>
#include <print>
#include <iostream>
#include <iterator>
#include <pthread.h>

using namespace std;

struct Student {
  int id {};
  string name {};
  string course {};
  int yearLevel {};
};

// Utility Functions 
void clearCin();
char getch();

// Main Functions
Student addStudent();
template<size_t S>
void displayStudents(const Student (&stud)[S]);
template<size_t S>
void updateStudent(Student (&stud)[S]);
template<size_t S>
void deleteStudent(Student (&stud)[S]);

int main() {
  const size_t MAX_SIZE {3};
  Student student[MAX_SIZE] {};
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
          if (currentCount !=  MAX_SIZE) {
            student[currentCount] = addStudent();
            currentCount++;
          } else {
            println("Storage is FULL!");
            char c = getch();
          }
          selected = 0;
          break;

        case 2:
          displayStudents(student);
          println("\n\t\t\t\t       Press any to Proceed!");
          getch();
          selected = 0;
          break;

        case 3:
          if (currentCount != 0) {
            updateStudent(student);
          } else {
            println("Nothing to Update");
            getch();
          }
          selected = 0;
          break;

        case 4:
          if (currentCount != 0) {
            deleteStudent(student);
          } else {
            println("Nothing to Delete");
            getch();
          }
          selected = 0;
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

void clearCin() {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


char getch() {
    char buffer {};
    std::cout << std::flush;
    system("stty -icanon -echo && setterm -cursor off");
    std::cin.get(buffer);
    system("stty sane && setterm -cursor on");
    
    return buffer;
}

Student addStudent() {
  Student buffer {};

  print("Enter ID: ");
  while (!(cin >> buffer.id)) {
    print("No Non-Number \nEnter ID: ");
    clearCin();
  }

  clearCin();
  print("Enter Name: ");
  getline(cin, buffer.name);

  print("Enter Course: ");
  getline(cin, buffer.course);

  print("Enter Year Level: ");
  while (!(cin >> buffer.yearLevel)) {
    print("No Non-Number \nEnter Year Level: ");

    clearCin();
  }
  clearCin();

  return buffer;
}

template<size_t S>
void displayStudents(const Student (&stud)[S]) {
  const size_t size {std::size(stud)};
  int counter {};
  for (int i {0}; i < size; i++) {
    if (stud[i].id != 0 || !stud[i].name.empty()) {
      counter++;
    }
  }
  println("================================================================================================");
  println("|         ID         |                NAME               |        COURSE        |  YEAR LEVEL  |");
  println("================================================================================================");
  if (counter == 0) 
    println("\t\t\t\t\tNo Student Recorded!");
  else {
    for (int i {0}; i < counter; i++) {
      println("| {:<18} | {:<33} | {:<20} | {:<12} |", stud[i].id, stud[i].name, stud[i].course, stud[i].yearLevel);
    }
    println("------------------------------------------------------------------------------------------------");
  }
}

template<size_t S>
void updateStudent(Student (&stud)[S]) {
  const size_t size {std::size(stud)};
  int counter {};
  for (int i {0}; i < size; i++) {
    if (stud[i].id != 0 || !stud[i].name.empty()) {
      counter++;
    }
  }
  
  int id {};
  print("Enter Student ID: ");
  while (!(cin >> id)) {
    print("No Non-Number \nEnter Student ID: ");
    clearCin();
  }
  clearCin();

  int index {};
  bool found {};
  for (int i{0}; i < counter; i++) {
    if (stud[i].id == id) {
      found = true;
      index = i;
      break;
    }
  }

  if (found) {
    do {
      system("clear");
  println("================================================================================================");
  println("|         ID         |                NAME               |        COURSE        |  YEAR LEVEL  |");
  println("================================================================================================");

  
  int sel {};
    println("| {:<18} | {:<33} | {:<20} | {:<12} |", stud[index].id, stud[index].name, stud[index].course, stud[index].yearLevel);
    println("------------------------------------------------------------------------------------------------\n");
    println("What woud you like to update?");
    println("[1] ID \n[2] NAME \n[3] COURSE \n[4] YEAR LEVEL\n[5] EXIT");

    print("selected by choosing the number: ");
    while (!(cin >> sel)) {
      print("No Non-Number \nTry Again: ");
      clearCin();
    }
    clearCin();

    switch (sel) {
      case 1:
        print("Update ID: ");
        while (!(cin >> stud[index].id)) {
          print("No Non-Number \nTry Again: ");
          clearCin();
        }
        clearCin();
        break;

      case 2:
        print("Update NAME: ");
        getline(cin, stud[index].name);
        break;

      case 3:
        print("Update COURSE: ");
        getline(cin, stud[index].course);
        break;

      case 4:
        print("New Year Level: ");
        while (!(cin >> stud[index].yearLevel)) {
          print("No Non-Number \nTry Again: ");
          clearCin();
        }
        clearCin();
        break;

      case 5:
        return;
        break;

      default:
      break;
    }

    } while (true);

  } else {
    println("\nNo ID Match");
    println("Press any to Proceed!");
    getch();

    return;
  }
}

template<size_t S>
void deleteStudent(Student (&stud)[S]) {
  const size_t size {std::size(stud)};
  int counter {};
  for (int i {0}; i < size; i++) {
    if (stud[i].id != 0 || !stud[i].name.empty()) {
      counter++;
    }
  }

  int id {};
  print("Enter Student ID to Delete: ");
  while (!(cin >> id)) {
    print("No Non-Number \nEnter Student ID to Delete: ");
    clearCin();
  }
  clearCin();

  int index {-1};
  bool found {false};
  for (int i{0}; i < counter; i++) {
    if (stud[i].id == id) {
      found = true;
      index = i;
      break;
    }
  }

  if (found) {
    system("clear");
    println("================================================================================================");
    println("|         ID         |                NAME               |        COURSE        |  YEAR LEVEL  |");
    println("================================================================================================");
    println("| {:<18} | {:<33} | {:<20} | {:<12} |", stud[index].id, stud[index].name, stud[index].course, stud[index].yearLevel);
    println("------------------------------------------------------------------------------------------------\n");

    print("Are you sure you want to delete this student? (Y/N): ");
    char confirm {};
    cin >> confirm;
    clearCin();

    if (confirm == 'Y' || confirm == 'y') {
      // Shift elements left to overwrite the deleted student
      for (int i = index; i < counter - 1; i++) {
        stud[i] = stud[i + 1];
      }

      // Reset the last active element to clear leftover duplicate data
      stud[counter - 1] = Student{};

      println("\nStudent deleted successfully!");
      println("\nPress any key to Proceed!");
      getch();
    } else {
      println("\nDeletion canceled.");
      println("\nPress any key to Proceed!");
      getch();
    }

  } else {
    println("\nNo ID Match");
    println("Press any to Proceed!");
    getch();
  }
}
