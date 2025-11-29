//
// Created by Cobalt Stamey on 11/28/25.
//

#include "Controller.h"
#include <iostream>
#include "UserInterface.h"

void Controller::run()
{
    int choice = 0;
    do {
        UserInterface::printMainMenu();
        choice = getUserChoiceInt();

        switch (choice) {
            case 1:
                userControl();
                break;
            case 2:
                fileControl();
                break;
            default:
                UserInterface::printError("Invalid Choice");
                break;
        }
    } while (choice!=3);

    UserInterface::printInfo("Exiting Program");
}

void Controller::userControl()
{
    UserInterface::printInfo("Entering User Control mode.");
    char choice;
    do {
        UserInterface::printActionMenu();
        choice = getUserChoiceChar();
        Controller::moveCar(choice);
    } while (choice != 'E');

    UserInterface::printInfo("Exiting User Control mode.");
}

void Controller::fileControl()
{
    UserInterface::printInfo("Entering File Control mode.");
    //readfile function
}

int Controller::getUserChoiceInt() {
    std::cout << "Enter your choice (INT): ";
    int choice;

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        UserInterface::printError("Please enter a valid number.");
        return -1;
    }

    return choice;
}

char Controller::getUserChoiceChar() {
    std::cout << "Enter your choice(CHAR): ";
    char choice;

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        UserInterface::printError("Please enter a valid number.");
        return -1;
    }

    return choice;
}

/**
 * This function allows you to move the car in a specific direction.
 * @param direction the direction to move the car.
 */
void Controller::moveCar(const char direction)
{
    //TODO: add log file implementation
    //TODO: add movement implementation
    switch (direction) {
        case 'L':
            std::cout << "\n" << "Moving car left" << "\n";
            break;
        case 'R':
            std::cout << "\n" << "Moving car right" << "\n";
            break;
        case 'B':
            std::cout << "\n" << "Moving car backwards" << "\n";
            break;
        case 'F':
            std::cout << "\n" << "Moving car forwards" << "\n";
            break;
        case 'S':
            std::cout << "\n" << "Moving car stop" << "\n";
            break;
        default:
            std::cout << "\n" << "Invalid action" << "\n";
            break;
    }

}


