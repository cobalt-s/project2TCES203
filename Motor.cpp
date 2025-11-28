#include "Motor.h"  
#include <string>
/**
 * Main code file used to represent one of the motors for an RC car
 * 
 * Jonathan Lee
 * TCES 203 A
 * Project 2
 */

 /**
  * Parameter-less constructor for the nameless Motor
  */
Motor::Motor(): name("unnamed"), speedPercent(0), enabled(false), direction(Direction::Stop) { }

/**
 * Parameter-less constructor for a named Motor
 */
Motor::Motor(const std::string& motorName): name(motorName), speedPercent(0), enabled(false), 
            direction(Direction::Stop) { }

/**
 * Used to set the current speed of the motor.
 * If the incoming speed percentage is above 100 or below -100,
 * the speed will be simply set at either of those respective values.
 */
void Motor::setSpeed(int newSpeedPercent) {
    if (newSpeedPercent > 100)
        speedPercent = 100;
    else if (newSpeedPercent < -100)
        speedPercent = -100;
    else
        speedPercent = newSpeedPercent;
}

/**
 * Used to set the current direction of the motor.
 */
void Motor::setDirection(Direction newDirection) {
    if (newDirection == Direction::Forward || newDirection == Direction::Backward ||
        newDirection == Direction::Left || newDirection == Direction::Right ||
        newDirection == Direction::Stop) {
        direction = newDirection;
    }
}

/**
 * Used to retrieve the current speed of the motor/car.
 */
int Motor::getSpeed() const {
    return speedPercent;
}

/**
 * Used to retrieve the name of the motor.
 */
std::string Motor::getName() const {
    return name;
}

/**
 * Used to retrieve the current direction of the motor.
 */
Direction Motor::getDirection() const {
    return direction;
}

/**
 * Used to turn on the car's motor.
 */
void Motor::enable() {
    enabled = true;
}

/**
 * Used to turn off the car's motor.
 */
void Motor::disable() {
    enabled = false;
    speedPercent = 0;
}

/**
 * Check to see if the car's motor is on.
 */
bool Motor::isEnabled() const {
    return enabled;
}