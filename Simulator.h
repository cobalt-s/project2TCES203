#ifndef SIMULATOR_H
#define SIMULATOR_H

class Car;   // forward declaration so we can use Car& and const Car&

/**
 * Header file for the Simulator Class
 *
 * Jonathan Lee, Cobalt Stamey
 * TCES 203 A
 * Project 2
 */
class Simulator {
public:
    Simulator();
    static void worldToMap(double x, double y, int& outRow, int& outCol);
    static void drawMap(const Car& car);
    static void runDemoPath(Car& car);
    static void interactiveMode();
    static int startSimulator();
};

#endif