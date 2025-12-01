#include "Car.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#define DISTANCE 15
#define ANGLE 5

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

void Camera::captureFrame(double captureX, double captureY)
{
    std::cout << "Hello" << "\n";
    // TODO: Implement captureX, capture Y in Log File and terminal.
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
    // initializing motors with the gpio pins for the l298n motor drivers.
    //  we probably will need to adjust this based on which car we get.
    //  this may have to change I need to look at the car and what pins they
    //  are in.

    frontLeft.initialize(23, 3, 5);  // ENA, IN1, IN2
    frontRight.initialize(23, 7, 11); // ENB, IN2, IN3
    rearLeft.initialize(23, 13, 15);     // ENC, IN4, IN5
    rearRight.initialize(23, 19, 21);    // END, IN6, IN7
}

/**
 * Used to update the car's position on a 2D grid.
 */
void Car::updatePose(const double dx, const double dy, const double dThetaDeg)
{
    x += dx;
    y += dy;
    headingDeg += dThetaDeg;

    // Normalize heading to [0, 360)
    headingDeg = std::fmod(headingDeg, 360.0);
    if (headingDeg < 0.0)
    {
        headingDeg += 360.0;
    }
}

/**
 * Move the car forward in its current direction.
 */
void Car::moveForward(const double distance)
{
    // Forward increases y
    updatePose(0.0, distance, 0.0);

    frontLeft.setDirection(Direction::Forward);
    frontRight.setDirection(Direction::Forward);
    rearLeft.setDirection(Direction::Forward);
    rearRight.setDirection(Direction::Forward);

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
void Car::moveBackward(const double distance)
{
    updatePose(0.0, -distance, 0.0);

    frontLeft.setDirection(Direction::Backward);
    frontRight.setDirection(Direction::Backward);
    rearLeft.setDirection(Direction::Backward);
    rearRight.setDirection(Direction::Backward);

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
void Car::strafeLeft(const double distance)
{
    updatePose(-distance, 0.0, 0.0);

    frontLeft.setDirection(Direction::Backward);
    frontRight.setDirection(Direction::Forward);
    rearLeft.setDirection(Direction::Forward);
    rearRight.setDirection(Direction::Backward);

    // Simple pattern for strafing (not physically accurate, but okay for our GUI)
    // may need to change this for the actual robot.
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
void Car::strafeRight(const double distance)
{
    updatePose(distance, 0.0, 0.0);

    frontLeft.setDirection(Direction::Forward);
    frontRight.setDirection(Direction::Backward);
    rearLeft.setDirection(Direction::Backward);
    rearRight.setDirection(Direction::Forward);

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
void Car::rotateLeft(const double angleDeg)
{
    updatePose(0.0, 0.0, angleDeg);

    frontLeft.setDirection(Direction::Backward);
    frontRight.setDirection(Direction::Backward);
    rearLeft.setDirection(Direction::Forward);
    rearRight.setDirection(Direction::Forward);

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
void Car::rotateRight(const double angleDeg)
{
    updatePose(0.0, 0.0, -angleDeg);

    frontLeft.setDirection(Direction::Forward);
    frontRight.setDirection(Direction::Forward);
    rearLeft.setDirection(Direction::Backward);
    rearRight.setDirection(Direction::Backward);

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
    frontLeft.setDirection(Direction::Stop);
    frontRight.setDirection(Direction::Stop);
    rearLeft.setDirection(Direction::Stop);
    rearRight.setDirection(Direction::Stop);

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
 * Get method.
 * @return the cars heading degree.
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
    switch (cmd)
    {
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
    switch (cmd)
    {
    case MovementCommand::MoveForward:
        moveForward(DISTANCE);
        break;
    case MovementCommand::MoveBackward:
        moveBackward(DISTANCE);
        break;
    case MovementCommand::StrafeLeft:
        strafeLeft(DISTANCE);
        break;
    case MovementCommand::StrafeRight:
        strafeRight(DISTANCE);
        break;
    case MovementCommand::RotateLeft:
        rotateLeft(ANGLE);
        break;
    case MovementCommand::RotateRight:
        rotateRight(ANGLE);
        break;
    case MovementCommand::Stop:
        stopAllMotors();
        break;
    }
}
