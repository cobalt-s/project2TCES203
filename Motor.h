#ifndef MOTOR_H
#define MOTOR_H
#include <string>

/**
 * Header file for a motor of an RC car
 * 
 * Jonathan Lee
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
    int enablePin; // ena or enb for the PWM
    int input1Pin; // IN1 or IN3
    int input2Pin; // IN2 or IN4

    static bool pigpioInitalized;
    static int instanceCount;

    void updateMotorOutput();

public:
    Motor();
    Motor(const std::string& motorName);
    Motor(const std::string& motorName, int ena, int in1, int in2);
    //~Motor();

    bool initalize(int ena, int in1, int in2);
    void setSpeed(int newSpeedPercent);
    void setDirection(Direction newDirection);
    int getSpeed() const;
    Direction getDirection() const;

    void enable();
    void disable();
    bool isEnabled() const;

    std::string getName() const;
};

#endif 