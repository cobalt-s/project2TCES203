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
            case 3:
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
    int choice;
    do
    {
        UserInterface::printExampleMenu();
        choice = getUserChoiceInt();
        switch (choice)
        {
            case 1:
            UserInterface::printInfo("Entering Example one");
            //TODO: enter example one.
            break;
            case 2:
            UserInterface::printInfo("Entering Example two");
            //TODO: enter example two.
            break;
            case 3:
            UserInterface::printInfo("Entering Example three");
            //TODO: enter example three.
            break;
        case 4:
            break;
        default:
            UserInterface::printError("Invalid Choice");
        }
    }
    while (choice != 4);
    UserInterface::printInfo("Exiting File Control mode.");
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

/**
 *  Gets the users choice.
 * @return the users choice as a char
 */
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
 * @param currentCar the object of the car that is being moved.
 */
void Controller::moveCar(const char direction, LogFile &logger, Car &currentCar)
{
    //TODO: Add rotate right/left.
    switch (direction) {
        case 'L':
            UserInterface::printInfo("Car strafe left.");
            currentCar.applyCommand(MovementCommand::StrafeLeft);
            logger.logLeft();
            break;
        case 'R':
            UserInterface::printInfo("Car strafe right");
            currentCar.applyCommand(MovementCommand::StrafeRight);
            logger.logRight();
            break;
        case 'B':
            UserInterface::printInfo("Moving Car Backward");
            currentCar.applyCommand(MovementCommand::MoveBackward);
            logger.logBack();
            break;
        case 'F':
            UserInterface::printInfo("Moving forward");
            currentCar.applyCommand(MovementCommand::MoveForward);
            logger.logForward();
            break;
        case 'S':
            UserInterface::printInfo("Car stopped");
            currentCar.applyCommand(MovementCommand::Stop);
            logger.logStop();
            break;
    case 'P':
            UserInterface::printInfo("Photo taken.");
            //TODO: The capture frame needs to be fixed.
            logger.logCamera("CAPTURE TAKEN.");
            currentCar.cameraOn();
            currentCar.cameraOff();
    case 'E':
        break;
        default:
            std::cout << "\n" << "Invalid action" << "\n";
            break;
    }

}


