#include <stdio.h>
#include <iostream>

void printMenu()
{
  std::cout << "Menu: for car" << "\n";
  std::cout << "Which mode would you like to enter?" << "\n";
  std::cout << "(1) Control with computer" << "\n";
  std::cout << "(2) Test with a file " << "\n";
}

int main()
{
  printMenu();

}