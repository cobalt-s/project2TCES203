#include "Motor.h"
#include <string>
#include <iostream>
#include <utility>

/**
 * Main code file used to represent one of the motors for an RC car
 *
 * Jonathan Lee
 * TCES 203 A
 * Project 2
 */

// static member initialization.
bool Motor::pigpioInitialized = false;
int Motor::instanceCount = 0;

/**
 * Constructor with pin initialization
 */
Motor::Motor(std::string motorName, int in1, int in2) : name(std::move(motorName)), speedPercent(0), enabled(false), direction(Direction::Stop)
{
    instanceCount++;
    initialize(in1, in2);
}

Motor::~Motor()
{
    disable();
    instanceCount--;
    if (instanceCount == 0 && pigpioInitialized)
    {
        gpioTerminate();
        pigpioInitialized = false;
    }
}

/**
 * Initialize pigpio and set pin modes
 */
bool Motor::initialize(const int in1, const int in2)
{
    if (!pigpioInitialized)
    {
        if (gpioInitialise() < 0)
        {
            std::cerr << "Failed to initialize pigpio" << std::endl;
            return false;
        }
        pigpioInitialized = true;
    }

    input1Pin = in1;
    input2Pin = in2;

    // setting pin modes for each pin.
    gpioSetMode(input1Pin, PI_OUTPUT);
    gpioSetMode(input2Pin, PI_OUTPUT);

    // initalize to a stopping state.
    gpioWrite(input1Pin, 0);
    gpioWrite(input2Pin, 0);

    return true;
}

/**
 * updating the motor outputs based on direction and speed.
 */
void Motor::updateMotorOutput() const
{
    if (!enabled)
    {
        gpioWrite(input1Pin, 0);
        gpioWrite(input2Pin, 0);
        return;
    }

    switch (direction)
    {
    case Direction::Forward:
        gpioWrite(input1Pin, 1);
        gpioWrite(input2Pin, 0);
        break;
    case Direction::Backward:
        gpioWrite(input1Pin, 0);
        gpioWrite(input2Pin, 1);
        break;
    case Direction::Stop:
    default:
        gpioWrite(input1Pin, 0);
        gpioWrite(input2Pin, 0);
        break;
    }
}


/**
 * Used to set the current direction of the motor.
 */
void Motor::setDirection(Direction newDirection)
{
    if (newDirection == Direction::Forward || newDirection == Direction::Backward ||
        newDirection == Direction::Stop)
    {
        direction = newDirection;
        updateMotorOutput();
    }
}

/**
 * Used to retrieve the name of the motor.
 */
std::string Motor::getName() const
{
    return name;
}

/**
 * Used to retrieve the current direction of the motor.
 */
Direction Motor::getDirection() const
{
    return direction;
}

/**
 * Used to turn on the car's motor.
 */
void Motor::enable()
{
    enabled = true;
    updateMotorOutput();
}

/**
 * Used to turn off the car's motor.
 */
void Motor::disable()
{
    enabled = false;
    updateMotorOutput();
}

/**
 * Check to see if the car's motor is on.
 */
bool Motor::isEnabled() const
{
    return enabled;
}