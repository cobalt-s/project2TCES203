#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <thread>

#include "Simulator.h"
#include "Car.h"
#include "Controller.h"
#include "Motor.h"
#include "UserInterface.h"

/**
 * Simulator for an RC Car's functionality by running it through a 2D grid.
 *
 * Jonathan Lee, Cobalt Stamey
 * Project 2
 * TCES 203 A
 */

// Size of the "map" shown in the console.
static constexpr int MAP_WIDTH  = 21;
static constexpr int MAP_HEIGHT = 21;

//constructor

Simulator::Simulator()
= default;

/**
 * Convert world coordinates (x, y) to map indices.
 * We assume the world origin (0,0) is at the center of the map.
 * @param
 */
void Simulator::worldToMap(double x, double y, int& outRow, int& outCol)
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
void Simulator::drawMap(const Car& car)
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

    const Motor& fl = car.getFrontLeftMotor();
    const Motor& fr = car.getFrontRightMotor();
    const Motor& rl = car.getRearLeftMotor();
    const Motor& rr = car.getRearRightMotor();

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
void Simulator::runDemoPath(Car& car)
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
void Simulator::interactiveMode()
{
    Car car;
    car.cameraOn(); // just to show that camera can be turned on/off

    char cmd = ' ';
    double value = 0.0;

    while (true) {
        drawMap(car);
        UserInterface::printSimulationInteractiveModeMenu();
        std::cout << "Enter command: ";
        cmd = Controller::getUserChoiceChar();

        if (cmd == 'z') {
            break;
        }

        if (cmd == 'c') {
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
            UserInterface::printError("Invalid command.");
            break;
        }
    }
}

/**
 * Main method for running the simulator
 */
int Simulator::startSimulator()
{
    UserInterface::printSimulationMenu();
    int choice = 0;
    choice = Controller::getUserChoiceInt();
    if (choice == 1) {
        Car car;
        car.cameraOn();
        runDemoPath(car);
        UserInterface::printInfo("Demo finished.");
        return 1;
    } else {
        interactiveMode();
    }
    UserInterface::printInfo("Exiting visualizer.");
    return 0;
}