//
// Created by Cobalt Stamey on 11/28/25.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "LogFile.h"
class Controller {
    public:
        Controller() = default;

        /**
         * Main run for the controller.
         */
        void run();
    private:
        /**
         * User control for the car.
         */
        void userControl();

        /**
         * File control for the car.
         */
        static void fileControl();

        /**
         * gets the user choice in INT format
         * @return int: the users choice
         */
        static int getUserChoiceInt();


        /**
         * gets the user choice in CHAR format
         * @return char: the users choice
         */
        static char getUserChoiceChar();

        /**
         * Moves the car based on a direction.
         * @param direction the direction you want to move the car.
         * @param logger
         */
        void moveCar(const char direction, LogFile &logger);
};

#endif //CONTROLLER_H
