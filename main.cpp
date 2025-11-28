/**
 * Main.cpp
 * Author: Cobalt Stamey
 *
 * This is the main program for the file of Project 2.
 */

#include <iostream>
#include <string>

/**
 * Prints the main menu;
 */
void printMenu()
{
  std::cout << "Menu: Car Controller" << "\n";
  std::cout << "Which mode would you like to enter?" << "\n";
  std::cout << "(1) Control with computer" << "\n";
  std::cout << "(2) Test with a file " << "\n";
  std::cout << "(3) Quit" << "\n";
}

/**
 * Prints the action menu.
 */
void printActionMenu()
{
  std::cout << "\nActions" << "\n";
  std::cout << "(L) Left" << "\n";
  std::cout << "(R) Right" << "\n";
  std::cout << "(B) Backward" << "\n";
  std::cout << "(F) Forward" << "\n";
  std::cout << "(S) Stop" << "\n";
  std::cout << "(K) Loop" << "\n";
  std::cout << "(E) Exit to main menu" << "\n";
  std::cout << "Choose an action:" << "\n";
}

/**
 * This function allows you to move the car in a specific direction.
 * @param direction the direction to move the car.
 */
void moveCar(char direction)
{
  switch (direction) {
    case 'L':
      std::cout << "Moving car left" << "\n";
      //TODO: add implementation to this movement.
      break;
    case 'R':
      std::cout << "Moving car right" << "\n";
      //TODO: add implementation to this movement.
      break;
    case 'B':
      std::cout << "Moving car backwards" << "\n";
      //TODO: add implementation to this movement.
      break;
    case 'F':
      std::cout << "Moving car forwards" << "\n";
      //TODO: add implementation to this movement.
      break;
    case 'S':
      std::cout << "Moving car stop" << "\n";
      //TODO: add implementation to this movement.
      break;
    default:
      std::cout << "Invalid action" << "\n";
      break;
  }

}

/**
 * This is the action loop for the car moving.
 * @return 0 if it runs good, 1 if it runs bad.
 */
int actionLoop()
{
  char choice;
  do {
    printActionMenu();
    std::cin >> choice; //TODO: make this safe.

    if (choice == 'K') {
      //might want to change movecar to let you choose how many times that could be fun.
      moveCar('L');
      moveCar('F');
      moveCar('L');
      moveCar('F');
      moveCar('L');
      moveCar('F');
      return 0;
    }else {
      moveCar(choice);
    }
  } while (choice != 'E');

  return 0;
}

/**
 * lets us know if we can read a line.
 */
static bool readLine(std::string &out)
{
  if(!std::getline(std::cin, out))
  {
    std::cout << "\nInput closed. Exiting.\n";
    return false;
  }
  return true;
}

/**
 * Gets the users choice from the terminal.
 * @return the users choice in int form
 */
int getUserChoice() {
  int choice;
  std::cout << "Enter your choice: ";
  if (!(std::cin >> choice)) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return -1;
  }
  return choice;
}

void readFile();

void readFile(std::string &speed, std::string &cameraMode) {
  // std::ifstream config("config.txt");
  // if (!config) {
  //   std::cout << "No configuration file found; using defaults.\n";
  //   return;
  // }
  // std::string line;
  // while (getline(config, line)) {
  //   // Very simple parsing: expect lines like "key=value"
  //   size_t eq = line.find('=');
  //   if (eq == std::string::npos) continue;
  //   std::string key = line.substr(0, eq);
  //   std::string value = line.substr(eq + 1);
  //   if (key == "speed") speed = value;
  //   else if (key == "camera_mode") cameraMode = value;
  // }
}

int main()
{
  int choice;
  do {
    printMenu();
    choice = getUserChoice();
    switch (choice) {
      case 1:
      // control with computer
        printActionMenu();
        break;
      case 2:
      // go from file
        readFile();
        break;
      case 3:
        exit(0); //might change this because apparently its unsafe.
        break;
      default:
        std::cout << "Invalid choice.\n";
    }
  } while (choice != 3);

}
