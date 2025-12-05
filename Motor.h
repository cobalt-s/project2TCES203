#ifndef MOTOR_H
#define MOTOR_H

#include <string>

// pigpio is only for linux, so I put this here so it uses our like test library so the code still compiles on windows.
#ifdef __linux__
    #include <pigpio.h>
#else
    #include "pigpio_mock.h"
#endif

/**
 * Header file for a motor of an RC car
 * 
 * Jonathan Lee
 * Cobalt Stamey
 * TCES 203 A
 * Project 2
 */

/**
 * Enumerated type to represent the current direction of the motor
 */
enum class Direction {
    Forward,
    Backward,
    Left,
    Right,
    Stop
};

/*
 * Represents a single DC motor driven by an L298N driver.
 */
class Motor {
private:
    std::string name;
    int speedPercent;   // from -100 to +100
    bool enabled;   
    Direction direction;

    // L298N control pins
    int input1Pin{}; // IN1 or IN3
    int input2Pin{}; // IN2 or IN4

    static bool pigpioInitialized;
    static int instanceCount;

    void updateMotorOutput() const;

public:
    Motor(std::string  motorName, int in1, int in2);
    ~Motor();

    bool initialize(int in1, int in2);
    void setDirection(Direction newDirection);
    Direction getDirection() const;
    int getSpeedPercent();

    void enable();
    void disable();
    bool isEnabled() const;

    std::string getName() const;
};

#endif 