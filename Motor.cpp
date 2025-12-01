#include "Motor.h"  
#include <string>
#include <iostream>

/**
 * Main code file used to represent one of the motors for an RC car
 * 
 * Jonathan Lee
 * TCES 203 A
 * Project 2
 */


 //static member initalization.
 bool Motor::pigpioInitialized = false;
 int Motor::instanceCount = 0;

 /**
  * Parameter-less constructor for the nameless Motor
  */
Motor::Motor(): name("unnamed"), speedPercent(0), enabled(false), direction(Direction::Stop), enablePin(-1), input1Pin(-1), input2Pin(-1) {
    instanceCount++; 
 }

/**
 * Parameter-less constructor for a named Motor
 */
Motor::Motor(const std::string& motorName): name(motorName), speedPercent(0), enabled(false), 
            direction(Direction::Stop) {
                instanceCount++;
            }



/**
 * Constructor with pin initialization
 */
Motor::Motor(const std::string& motorName, int ena, int in1, int in2): name(motorName), speedPercent(0), enabled(false), direction(Direction::Stop) {
    instanceCount++; 
    initialize(ena, in1, in2);
 }

 /**
  * destructor.
  */
 Motor::~Motor() {
    disable();
    instanceCount--;
    if (instanceCount == 0 && pigpioInitialized) {
        gpioTerminate();
        pigpioInitialized = false;
    }
 }

/**
 * Initialize pigpio and set pin modes
 */
bool Motor::initialize(int ena, int in1, int in2) {
    if (!pigpioInitialized) {
        if (gpioInitialise() < 0) {
            std::cerr << "Failed to initialize pigpio" << std::endl;
            return false;
        }
        pigpioInitialized = true;
    }
    
    enablePin = ena;
    input1Pin = in1;
    input2Pin = in2;
    
    // setting pin modes for each pin. 
    gpioSetMode(enablePin, PI_OUTPUT);
    gpioSetMode(input1Pin, PI_OUTPUT);
    gpioSetMode(input2Pin, PI_OUTPUT);
    
    // initalize to a stopping state. 
    gpioWrite(input1Pin, 0);
    gpioWrite(input2Pin, 0);
    gpioPWM(enablePin, 0);
    
    return true;
}

/**
 * updating the motor outputs based on direction and speed. 
 */
void Motor::updateMotorOutput() {
    if (!enabled || enablePin == -1) {
        if (enablePin != -1) {
            gpioPWM(enablePin, 0);
            gpioWrite(input1Pin, 0);
            gpioWrite(input2Pin, 0);
        }
        return;
    }
    
    // converting speed percntage to pwm (pulse width modulation)
    int pwmValue = (abs(speedPercent) * 255) / 100;
    
    switch(direction) {
        case Direction::Forward:
            gpioWrite(input1Pin, 1);
            gpioWrite(input2Pin, 0);
            gpioPWM(enablePin, pwmValue);
            break;
        case Direction::Backward:
            gpioWrite(input1Pin, 0);
            gpioWrite(input2Pin, 1);
            gpioPWM(enablePin, pwmValue);
            break;
        case Direction::Stop:
        default:
            gpioWrite(input1Pin, 0);
            gpioWrite(input2Pin, 0);
            gpioPWM(enablePin, 0);
            break;
    }
}
 

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
    
    updateMotorOutput();
}

/**
 * Used to set the current direction of the motor.
 */
void Motor::setDirection(Direction newDirection) {
    if (newDirection == Direction::Forward || newDirection == Direction::Backward ||
        newDirection == Direction::Left || newDirection == Direction::Right ||
        newDirection == Direction::Stop) {
        direction = newDirection;

        updateMotorOutput();
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
    //TODO: turn on the motors using the driver.
    enabled = true;
    updateMotorOutput();
}

/**
 * Used to turn off the car's motor.
 */
void Motor::disable() {
    enabled = false;
    speedPercent = 0;
    updateMotorOutput();
}

/**
 * Check to see if the car's motor is on.
 */
bool Motor::isEnabled() const {
    return enabled;
}