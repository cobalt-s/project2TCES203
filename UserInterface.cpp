//
// Created by Cobalt Stamey on 11/28/25.
//

#include "UserInterface.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

/**
 * An extra namespace for creating the user interface of the controller/simulator
 * 
 * Jonathan Lee, Cobalt Stamey
 * TCES 203 A
 * Project 2
 */
namespace UserInterface
{
    /**
     * Print out the main menu choices
     */
    void printMainMenu()
    {
        std::cout << "\n=====CAR CONTROLLER=====" << "\n";
        std::cout << "Which mode would you like \nto enter?" << "\n";
        std::cout << "(1) Control with computer" << "\n";
        std::cout << "(2) Test with examples" << "\n";
        std::cout << "(3) Open Simulator" << "\n";
        std::cout << "(4) Exit program." << "\n";
        std::cout << "========================" << "\n";
    }

    /**
     * Display the action menu for the RC car.
     */
    void printActionMenu()
    {
        std::cout << "\n"
                  << std::string(20, '=') << "ACTION MENU" << std::string(20, '=') << std::endl;
        std::cout << "(L) Left" << "\n";
        std::cout << "(R) Right" << "\n";
        std::cout << "(Q) Rotate Left" << "\n";
        std::cout << "(E) Rotate Right" << "\n";
        std::cout << "(B) Backward" << "\n";
        std::cout << "(F) Forward" << "\n";
        std::cout << "(S) Stop" << "\n";
        std::cout << "(P) Take Picture" << '\n';
        std::cout << "(X) Exit to main menu" << "\n";
        std::cout << std::string(51, '=') << std::endl;
    }

    /**
     * Display the various examples for running the RC car.
     */
    void printExampleMenu()
    {
        std::cout << "\n--Examples--" << "\n";
        std::cout << "(1) Example one" << "\n";
        std::cout << "(2) Example two" << "\n";
        std::cout << "(3) Example three" << "\n";
        std::cout << "(4) Exit to main menu." << "\n";
        std::cout << std::string(12, '-') << std::endl;
    }

    /**
     * Display an error message if something goes wrong with an RC car.
     */
    void printError(const std::string &message)
    {
        for (int i = 0; i < 1; i++)
        {
            std::cout << " " << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "\n[ERROR] " << message << "\n";
    }

    /**
     * Display some information regarding an RC car.
     */
    void printInfo(const std::string &message)
    {
        std::cout << "[INFO] " << message << "\n";
        for (int i = 0; i < 1; i++)
        {
            std::cout << " " << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

}
