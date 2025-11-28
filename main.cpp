#include <stdio.h>
#include <iostream>
#include <string>


void printMenu()
{
  std::cout << "Menu: Car Controller" << "\n";
  std::cout << "Which mode would you like to enter?" << "\n";
  std::cout << "(1) Control with computer" << "\n";
  std::cout << "(2) Test with a file " << "\n";
  std::cout << "(3) Quit" << "\n";
  std::cout << "(3) Quit" << "\n";
}

void printActionMenu()
{
  std::cout << "\nActions" << "\n";
  std::cout << "(L) Left" << "\n";
  std::cout << "(R) Right" << "\n";
  std::cout << "(B) Backward" << "\n";
  std::cout << "(F) Forward" << "\n";
  std::cout << "(S) Forward" << "\n";
  std::cout << "(L) Forward" << "\n";
  std::cout << "(E) Exit to main menu" << "\n";
  std::cout << "Choose an action:" << "\n";
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

int main()
{

  while (true)
  {
    printMenu();
  }


}