#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>
#include "Car.h"
#include "Motor.h"
#include "UserInterface.h"
#include "Controller.h"

/**
 * Simulator for an RC Car's functionality by running it through a 2D grid.
 * 
 * Jonathan Lee, Cobalt, Stamey
 * Project 2
 * TCES 203 A
 */

// Size of the "map" shown in the console.
static const int MAP_WIDTH  = 21;
static const int MAP_HEIGHT = 21;

/**
 * Convert world coordinates (x, y) to map indices.
 * We assume the world origin (0,0) is at the center of the map.
 */
void worldToMap(double x, double y, int& outRow, int& outCol)
{
    int centerRow = MAP_HEIGHT / 2;
    int centerCol = MAP_WIDTH / 2;

    // y grows "up", rows grow "down", so row decreases when y increases.
    outRow = centerRow - static_cast<int>(std::round(y));
    outCol = centerCol + static_cast<int>(std::round(x));
}

/**
 * Draw a simple ASCII map with the car at its current position.
 */
void drawMap(const Car& car)
{
    int carRow = 0;
    int carCol = 0;
    worldToMap(car.getX(), car.getY(), carRow, carCol);

    // Clear screen (simple portable trick).
    std::cout << "\x1B[2J\x1B[H";

    std::cout << "Mecanum Car Visualizer\n";
    std::cout << "----------------------\n";
    std::cout << "Pose: (x = " << car.getX()
              << ", y = " << car.getY()
              << ", heading = " << car.getHeadingDeg() << " deg)\n";

    Motor fl = car.getFrontLeftMotor(); //TO
    Motor fr = car.getFrontRightMotor();
    Motor rl = car.getRearLeftMotor();
    Motor rr = car.getRearRightMotor();

    std::cout << "Motors: \n";
    std::cout << "  " << fl.getName() << "  speed = " << fl.getSpeedPercent()
              << "  enabled = " << (fl.isEnabled() ? "yes" : "no") << "\n";
    std::cout << "  " << fr.getName() << "  speed = " << fr.getSpeedPercent()
              << "  enabled = " << (fr.isEnabled() ? "yes" : "no") << "\n";
    std::cout << "  " << rl.getName() << "  speed = " << rl.getSpeedPercent()
              << "  enabled = " << (rl.isEnabled() ? "yes" : "no") << "\n";
    std::cout << "  " << rr.getName() << "  speed = " << rr.getSpeedPercent()
              << "  enabled = " << (rr.isEnabled() ? "yes" : "no") << "\n";

    std::cout << "\nMap Legend: C = car, . = empty\n\n";

    for (int row = 0; row < MAP_HEIGHT; ++row) {
        for (int col = 0; col < MAP_WIDTH; ++col) {
            if (row == carRow && col == carCol) {
                std::cout << 'C';
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

/**
 * Simple scripted demo path for the car.
 */
void runDemoPath(Car& car)
{
    using namespace std::chrono_literals;

    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveForward(3.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeRight(4.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateLeft(90.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveBackward(2.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeLeft(3.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateRight(45.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.stopAllMotors();
    drawMap(car);
    std::this_thread::sleep_for(800ms);
}

/**
 * Gives the user a set of options on how to control the car.
 */
void interactiveMode()
{
    Car car;
    car.cameraOn(); // just to show that camera can be turned on/off

    char cmd = ' ';
    double value = 0.0;

    while (true) {
        drawMap(car);
        std::cout << "Commands:\n";
        std::cout << "  w d  : Move Forward  by d units\n";
        std::cout << "  s d  : Move Backward by d units\n";
        std::cout << "  a d  : Strafe Left    by d units\n";
        std::cout << "  d d  : Strafe Right  by d units\n";
        std::cout << "  q a  : Rotate Left    by a degrees\n";
        std::cout << "  e a  : Rotate Right  by a degrees\n";
        std::cout << "  c    : Toggle Camera On/Off\n";
        std::cout << "  x    : Stop All Motors\n";
        std::cout << "  z    : Quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;

        if (!std::cin) {
            return;
        }

        if (cmd == 'z') {
            break;
        }

        if (cmd == 'c') {
            // Toggle camera.
            // We cannot directly read camera state,
            // but we know startStream()/stopStream() exist.
            // For simplicity, just call start or stop alternatively.
            static bool cameraOnFlag = true;
            if (cameraOnFlag) {
                car.cameraOff();
                cameraOnFlag = false;
            } else {
                car.cameraOn();
                cameraOnFlag = true;
            }
            continue;
        }

        if (cmd == 'x') {
            car.stopAllMotors();
            continue;
        }

        std::cout << "Enter value: ";
        std::cin >> value;
        if (!std::cin) {
            return;
        }

        switch (cmd) {
        case 'w':
            car.moveForward(value);
            break;
        case 's':
            car.moveBackward(value);
            break;
        case 'a':
            car.strafeLeft(value);
            break;
        case 'd':
            car.strafeRight(value);
            break;
        case 'q':
            car.rotateLeft(value);
            break;
        case 'e':
            car.rotateRight(value);
            break;
        default:
            std::cout << "Unknown command.\n";
            break;
        }
    }
}

/**
 * Main method for running the simulator
 */
int main()
{
    //TODO: include the userinterface.
    //TODO: Integrate into UserInterface.cpp
    
    Controller controller;
    controller.run();
    std::cout << "=== Mecanum Car GUI / Visualizer ===\n\n";
    std::cout << "1) Run demo path\n";
    std::cout << "2) Interactive mode\n";
    std::cout << "Choice: ";

    //TODO:Integrate into the controller get inputs.
    // TODO: choice (INT)
    //TODO: inlcude the controller class.
    int choice = 0;
    std::cin >> choice;

    if (!std::cin) {
        return 0;
    }

    if (choice == 1) {
        Car car;
        car.cameraOn();
        runDemoPath(car);
        std::cout << "Demo finished.\n";
    } else {
        interactiveMode();
    }

    std::cout << "Exiting visualizer.\n";
    return 0;
}