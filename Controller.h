#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "LogFile.h"
#include "Car.h"
class Controller {
    public:
        Controller() = default;

        /**
         * Main run for the controller.
         */
        static void run();

        /**
        * gets the user choice in INT format
        * @return int: the users choice
        */
        static int getUserChoiceInt();
    private:
        /**
         * User control for the car.
         */
        static void userControl();

        /**
         * File control for the car.
         */
        static void fileControl();



        /**
         * gets the user choice in CHAR format
         * @return char: the users choice
         */
        static char getUserChoiceChar();

        /**
         * Moves the car based on a action.
         * @param action the direction you want to move the car.
         * @param logger
         * @param currentCar
         */
        static void carAction(const char action, LogFile &logger, Car &currentCar);
};

#endif //CONTROLLER_H
