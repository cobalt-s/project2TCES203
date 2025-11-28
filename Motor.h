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

public:
    Motor();
    Motor(const std::string& motorName);

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