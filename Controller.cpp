#include "Controller.h"
#include <iostream>

#include "LogFile.h"
#include "UserInterface.h"
#include "Car.h"
#include "Simulator.h"

/**
 * Main car controller class for running the RC cars
 * 
 * Jonathan Lee, Cobalt Stamey
 * TCES 203 A
 * Project 2
 */

/**
 *  Gets the users choice.
 * @return the users choice as a char
 */
char Controller::getUserChoiceChar()
{
    std::cout << "Enter your choice(CHAR): ";
    char choice;

    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        UserInterface::printError("Please enter a valid number.");
        return -1;
    }

    return choice;
}

/**
 * 
 */
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
            // TODO: enter example one.
            break;
        case 2:
            UserInterface::printInfo("Entering Example two");
            // TODO: enter example two.
            break;
        case 3:
            UserInterface::printInfo("Entering Example three");
            // TODO: enter example three.
            break;
        case 4:
            break;
        default:
            UserInterface::printError("Invalid Choice");
        }
    } while (choice != 4);
    UserInterface::printInfo("Exiting File Control mode.");
}

/**
 * 
 */
int Controller::getUserChoiceInt()
{
    std::cout << "Enter your choice (INT): ";
    int choice;

    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        UserInterface::printError("Please enter a valid number.");
        return -1;
    }

    return choice;
}

/**
 * This function allows you to move the car in a specific action.
 * @param action the action you want the car to do.
 * @param logger the log file object.
 * @param currentCar the object of the car that is being moved.
 */
void Controller::carAction(const char action, LogFile &logger, Car &currentCar)
{
    // TODO: Add rotate right/left.
    switch (action)
    {
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
    case 'Q':
        UserInterface::printInfo("Car rotate left.");
        currentCar.applyCommand(MovementCommand::RotateLeft);
        logger.logLeft();
        break;
    case 'E':
        UserInterface::printInfo("Car rotate right.");
        currentCar.applyCommand(MovementCommand::RotateRight);
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
        // TODO: The capture frame needs to be fixed.
        logger.logCamera("CAPTURE TAKEN.");
        currentCar.cameraOn();
        currentCar.cameraOff();
        break;
    case 'X':
        break;
    default:
        std::cout << "\n"
                  << "Invalid action" << "\n";
        break;
    }
}

/**
 * 
 */
void Controller::userControl()
{
    Car currentCar;
    LogFile logger;
    UserInterface::printInfo("Entering User Control mode.");

    char choice;
    do
    {
        UserInterface::printActionMenu();
        choice = getUserChoiceChar();
        Controller::carAction(choice, logger, currentCar);
    } while (choice != 'X');

    UserInterface::printInfo("Exiting User Control mode.");
}

/**
 * 
 */
void Controller::run()
{
    int choice = 0;
    Simulator sim;
    do
    {
        UserInterface::printMainMenu();
        choice = getUserChoiceInt();
        switch (choice)
        {
        case 1:
            userControl();
            break;
        case 2:
            fileControl();
            break;
        case 3:
            sim.start();
            break;
        case 4: break;
        default:
            UserInterface::printError("Invalid Choice");
            break;
        }
    } while (choice != 4);

    UserInterface::printInfo("Exiting Program");
}