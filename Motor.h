#ifndef MOTOR_H
#define MOTOR_H
#include <string>

/**
 * Represents a motor for a car (particularly an RC car for Project 2)
 * 
 * Jonathan Lee
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

    void enable();
    void disable();
    bool isEnabled() const;

    std::string getName() const;
};

#endif 