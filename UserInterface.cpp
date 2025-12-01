//
// Created by Cobalt Stamey on 11/28/25.
//

#include "UserInterface.h"
#include <iostream>

namespace UserInterface {
    void printMainMenu()
    {
        std::cout << "\n--CAR CONTROLLER--" << "\n";
        std::cout << "Which mode would you like to enter?" << "\n";
        std::cout << "(1) Control with computer" << "\n";
        std::cout << "(2) Test with examples" << "\n";
        std::cout << "(3) Quit" << "\n";
    }
    void printActionMenu()
    {
        std::cout << "\n--Actions--" << "\n";
        std::cout << "(L) Left" << "\n";
        std::cout << "(R) Right" << "\n";
        std::cout << "(B) Backward" << "\n";
        std::cout << "(F) Forward" << "\n";
        std::cout << "(S) Stop" << "\n";
        std::cout << "(P) Take Picture" << '\n';
        std::cout << "(E) Exit to main menu" << "\n";
    }

    void printExampleMenu()
    {
        std::cout << "\n--Examples--" << "\n";
        std::cout << "(1) Example one" << "\n";
        std::cout << "(2) Example two" << "\n";
        std::cout << "(3) Example three" << "\n";
        std::cout << "(4) Exit" << "\n";
    }

    void printError(const std::string& message)
    {
        std::cout << "\n[ERROR] " << message << "\n";
    }

    void printInfo(const std::string& message)
    {
        std::cout << "\n[INFO] " << message << "\n";
    }

}
