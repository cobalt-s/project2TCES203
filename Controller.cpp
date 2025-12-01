//
// Created by Cobalt Stamey on 11/28/25.
//

#include "Controller.h"
#include <iostream>
#include "LogFile.h"
#include "UserInterface.h"
#include "Car.h"

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
    Car currentCar;
    LogFile logger;
    UserInterface::printInfo("Entering User Control mode.");

    char choice;
    do {
        UserInterface::printActionMenu();
        choice = getUserChoiceChar();
        Controller::moveCar(choice, logger, currentCar);
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
 * @param logger the log file object.
 * @param currentCar
 */
void Controller::moveCar(const char direction, LogFile &logger, Car &currentCar)
{
    //TODO: Add rotate right/left.
    switch (direction) {
        case 'L':
            std::cout << "\n" << "Moving car left" << "\n";
            currentCar.applyCommand(MovementCommand::StrafeLeft);
            logger.logLeft();
            break;
        case 'R':
            std::cout << "\n" << "Moving car right" << "\n";
            currentCar.applyCommand(MovementCommand::StrafeRight);
            logger.logRight();
            break;
        case 'B':
            std::cout << "\n" << "Moving car backwards" << "\n";
            currentCar.applyCommand(MovementCommand::MoveForward);
            logger.logBack();
            break;
        case 'F':
            std::cout << "\n" << "Moving car forwards" << "\n";
            currentCar.applyCommand(MovementCommand::MoveForward);
            logger.logForward();
            break;
        case 'S':
            std::cout << "\n" << "Moving car stop" << "\n";
            currentCar.applyCommand(MovementCommand::Stop);
            logger.logStop();
            break;
        default:
            std::cout << "\n" << "Invalid action" << "\n";
            break;
    }

}


