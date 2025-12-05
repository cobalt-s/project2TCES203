#ifndef SIMULATOR_H
#define SIMULATOR_H

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
        void worldToMap(double x, double y, int& outRow, int& outCol);
        void drawMap(const Car& car);
        void runDemoPath(Car& car);
        void interactiveMode();
        int start();
};

#endif