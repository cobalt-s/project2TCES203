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
        void fileControl();
        // helps with getting the menu choice.
        int getUserChoice();
};

#endif //CONTROLLER_H
