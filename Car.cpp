#include "Car.h"
#include <algorithm>   
#include <cmath>       
#include <string>
#include <iostream>

/**
 * Main code file used to represent a four-wheeled RC Car
 * 
 * Jonathan Lee
 * TCES 203 A
 * Project 2
 */

 /**
  * Represents a camera for the car.
  */
Camera::Camera()
    : streaming(false)
{
}

/**
 * Start streaming from the camera.
 */
void Camera::startStreaming()
{
    streaming = true;
}

/**
 * Stop streaming from the camera.
 */
void Camera::stopStreaming()
{
    streaming = false;
}

void Camera::captureFrame(double captureX, double captureY) {
    std::cout << "Hello" << "\n";
}

/**
 * Check to see if the camera is still running.
 */
bool Camera::isStreaming() const
{
    return streaming;
}

/**
 * Constructor for a four-wheeled RC car
 */
Car::Car()
    : frontLeft("front-left"),
      frontRight("front-right"),
      rearLeft("rear-left"),
      rearRight("rear-right"),
      camera(),
      x(0.0),
      y(0.0),
      headingDeg(0.0)
{
}

/**
 * Used to update the car's position on a 2D grid.
 */
void Car::updatePose(double dx, double dy, double dThetaDeg)
{
    x += dx;
    y += dy;
    headingDeg += dThetaDeg;

    // Normalize heading to [0, 360)
    headingDeg = std::fmod(headingDeg, 360.0);
    if (headingDeg < 0.0) {
        headingDeg += 360.0;
    }
}

/**
 * Move the car forward in its current direction.
 */
void Car::moveForward(double distance)
{
    // Forward increases y
    updatePose(0.0, distance, 0.0);

    // Simple symmetric speeds (illustrative)
    frontLeft.setSpeed(50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(50);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Back the car up in its current direction.
 */
void Car::moveBackward(double distance)
{
    updatePose(0.0, -distance, 0.0);

    frontLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(-50);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Have the car strafe to the left from its current position.
 */
void Car::strafeLeft(double distance)
{
    updatePose(-distance, 0.0, 0.0);

    // Simple pattern for strafing (not physically accurate, but okay for our GUI)
    frontLeft.setSpeed(-50);
    rearLeft.setSpeed(50);
    frontRight.setSpeed(50);
    rearRight.setSpeed(-50);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Have the car strafe to the right from its current position.
 */
void Car::strafeRight(double distance)
{
    updatePose(distance, 0.0, 0.0);

    frontLeft.setSpeed(50);
    rearLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
    rearRight.setSpeed(50);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Rotate the car to the left in its current position. 
 */
void Car::rotateLeft(double angleDeg)
{
    updatePose(0.0, 0.0, angleDeg);

    frontLeft.setSpeed(-40);
    rearLeft.setSpeed(-40);
    frontRight.setSpeed(40);
    rearRight.setSpeed(40);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Rotate the car to the right in its current position.
 */
void Car::rotateRight(double angleDeg)
{
    updatePose(0.0, 0.0, -angleDeg);

    frontLeft.setSpeed(40);
    rearLeft.setSpeed(40);
    frontRight.setSpeed(-40);
    rearRight.setSpeed(-40);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

/**
 * Stop the car!!!
 */
void Car::stopAllMotors()
{
    frontLeft.setSpeed(0);
    frontRight.setSpeed(0);
    rearLeft.setSpeed(0);
    rearRight.setSpeed(0);

    frontLeft.disable();
    frontRight.disable();
    rearLeft.disable();
    rearRight.disable();
}

/**
 * Turn the car's camera on.
 */
void Car::cameraOn()
{
    camera.startStreaming();
}

/**
 * Turn the car's camera off.
 */
void Car::cameraOff()
{
    camera.stopStreaming();
}

/**
 * Return the car's x-coordinate.
 */
double Car::getX() const
{
    return x;
}

/**
 * Return the car's y-coordinate.
 */
double Car::getY() const
{
    return y;
}

/**
 * Return the car's heading degree.
 */
double Car::getHeadingDeg() const
{
    return headingDeg;
}

/**
 * Return the car's front left motor.
 */
Motor Car::getFrontLeftMotor() const
{
    return frontLeft;
}
/**
 * Return the car's front right motor.
 */
Motor Car::getFrontRightMotor() const
{
    return frontRight;
}

/**
 * Return the car's rear left motor.
 */
Motor Car::getRearLeftMotor() const
{
    return rearLeft;
}

/**
 * Return the car's rear right motor.
 */
Motor Car::getRearRightMotor() const
{
    return rearRight;
}

/**
 * Return a snapshot of the car at a moment in time.
 */
CarSnapshot Car::getSnapshot() const
{
    CarSnapshot snap;

    snap.x = x;
    snap.y = y;
    snap.headingDeg = headingDeg;
    snap.cameraStreaming = camera.isStreaming();

    snap.frontLeft.name = frontLeft.getName();
    snap.frontLeft.speedPercent = frontLeft.getSpeed();
    snap.frontLeft.enabled = frontLeft.isEnabled();

    snap.frontRight.name = frontRight.getName();
    snap.frontRight.speedPercent = frontRight.getSpeed();
    snap.frontRight.enabled = frontRight.isEnabled();

    snap.rearLeft.name = rearLeft.getName();
    snap.rearLeft.speedPercent = rearLeft.getSpeed();
    snap.rearLeft.enabled = rearLeft.isEnabled();

    snap.rearRight.name = rearRight.getName();
    snap.rearRight.speedPercent = rearRight.getSpeed();
    snap.rearRight.enabled = rearRight.isEnabled();

    return snap;
}

/**
 * Applys a movement given a command and distance/angle.
 * @param cmd the movement command.
 * @param value the value distance or angle.
 */
void Car::applyCommand(MovementCommand cmd, double value)
{
    switch (cmd) {
        case MovementCommand::MoveForward:
            moveForward(value);
            break;
        case MovementCommand::MoveBackward:
            moveBackward(value);
            break;
        case MovementCommand::StrafeLeft:
            strafeLeft(value);
            break;
        case MovementCommand::StrafeRight:
            strafeRight(value);
            break;
        case MovementCommand::RotateLeft:
            rotateLeft(value);
            break;
        case MovementCommand::RotateRight:
            rotateRight(value);
            break;
        case MovementCommand::Stop:
            stopAllMotors();
            break;
    }
}

/**
 * Applys a movement given just a command.
 * @param cmd the movement command.
 */
void Car::applyCommand(MovementCommand cmd)
{
    const double distance = 10; // meters?
    const double angle = 5;
    switch (cmd) {
    case MovementCommand::MoveForward:
        moveForward(distance);
        break;
    case MovementCommand::MoveBackward:
        moveBackward(distance);
        break;
    case MovementCommand::StrafeLeft:
        strafeLeft(distance);
        break;
    case MovementCommand::StrafeRight:
        strafeRight(distance);
        break;
    case MovementCommand::RotateLeft:
        rotateLeft(angle);
        break;
    case MovementCommand::RotateRight:
        rotateRight(angle);
        break;
    case MovementCommand::Stop:
        stopAllMotors();
        break;
    }
}








