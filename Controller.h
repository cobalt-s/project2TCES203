//
// Created by Cobalt Stamey on 11/28/25.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
    public:
        Controller() = default;
        void run();
    private:
        // user gets to control the car.
        void userControl();
        // a test file controls the car.
        static void fileControl();
        // helps with getting the menu choice.
        static int getUserChoiceInt();

        static char getUserChoiceChar();

        void moveCar(char direction);
};

#endif //CONTROLLER_H
