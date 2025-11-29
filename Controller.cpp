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
        choice = getUserChoice();

        switch (choice) {
            case 1:
                userControl();
                break;
            case 2:
                fileControl();
                break;
            case 3:
                UserInterface::printInfo("Invalid Choice");
                break;
            default:
                UserInterface::printError("Invalid Choice");
                break;
        }
    } while (choice!=3);
}

void Controller::userControl()
{
    UserInterface::printInfo("Entering User Control mode.");
    UserInterface::printActionMenu();
    // need to add more
}

void Controller::fileControl()
{
    UserInterface::printInfo("Entering File Control mode.");

}

int Controller::getUserChoice() {
    std::cout << "Enter your choice: ";
    int choice;

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        UserInterface::printError("Please enter a valid number.");
        return -1;  // Forces main loop to show error
    }

    return choice;
}


// /**
//  * This is the action loop for the car moving.
//  * @return 0 if it runs good, 1 if it runs bad.
//  */
// int actionLoop()
// {
//     char choice;
//     do {
//         printActionMenu();
//         choice = getUserChoice();
//
//         if (choice == 'K') {
//             //might want to change movecar to let you choose how many times that could be fun.
//
//             //this is a loop for the car.
//             moveCar('L');
//             moveCar('F');
//             moveCar('L');
//             moveCar('F');
//             moveCar('L');
//             moveCar('F');
//             moveCar('S');
//             return 0;
//         }else {
//             moveCar(choice);
//         }
//     } while (choice != 'E');
//
//     return 0;
// }


// /**
//  *
//  * @param speed
//  * @param cameraMode
//  */
// void readConfigFile(std::string &speed, std::string &cameraMode) {
//     std::ifstream config("config.txt");
//     if (!config) {
//         std::cout << "No configuration file found; using defaults.\n";
//         return;
//     }
//     std::string line;
//     while (getline(config, line)) {
//         // Very simple parsing: expect lines like "key=value"
//         size_t eq = line.find('=');
//         if (eq == std::string::npos) continue;
//         std::string key = line.substr(0, eq);
//         std::string value = line.substr(eq + 1);
//         if (key == "speed") speed = value;
//         else if (key == "camera_mode") cameraMode = value;
//     }
// }

// char getUserChoiceChar() {
//     char choice;
//     std::cout << "Enter your choice: ";
//
//     if (!(std::cin >> choice)) {
//         std::cin.clear();
//         std::cin.ignore(10000, '\n');
//         return '\0';
//     }
//
//     std::cin.ignore(10000, '\n');
//     return choice;
// }

// /**
//  * This function allows you to move the car in a specific direction.
//  * @param direction the direction to move the car.
//  */
// void moveCar(const char direction)
// {
//     switch (direction) {
//         case 'L':
//             std::cout << "Moving car left" << "\n";
//             //TODO: add implementation to this movement.
//             break;
//         case 'R':
//             std::cout << "Moving car right" << "\n";
//             //TODO: add implementation to this movement.
//             break;
//         case 'B':
//             std::cout << "Moving car backwards" << "\n";
//             //TODO: add implementation to this movement.
//             break;
//         case 'F':
//             std::cout << "Moving car forwards" << "\n";
//             //TODO: add implementation to this movement.
//             break;
//         case 'S':
//             std::cout << "Moving car stop" << "\n";
//             //TODO: add implementation to this movement.
//             break;
//         default:
//             std::cout << "Invalid action" << "\n";
//             break;
//     }
//
// }