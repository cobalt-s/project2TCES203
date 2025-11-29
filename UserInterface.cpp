//
// Created by Cobalt Stamey on 11/28/25.
//

#include "UserInterface.h"
#include <iostream>

namespace UserInterface {
    void printMainMenu()
    {
        std::cout << "Menu: Car Controller" << "\n";
        std::cout << "Which mode would you like to enter?" << "\n";
        std::cout << "(1) Control with computer" << "\n";
        std::cout << "(2) Test with a file " << "\n";
        std::cout << "(3) Quit" << "\n";
    }
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

    void printError(const std::string& message)
    {
        std::cout << "ERROR: " << message << "\n";
    }

    void printInfo(const std::string& message)
    {
        std::cout << "INFO: " << message << "\n";
    }

}
