#include "Car.h"
#include <algorithm>   // std::clamp (C++17; if not available, replace with manual clamp)
#include <cmath>       // std::fmod

/**
 * Coding Activity 14
 * 
 * Jonathan Lee
 */

// --------------------
// Motor implementation
// --------------------

Motor::Motor()
    : name("unnamed"), speedPercent(0), enabled(false)
{
}

Motor::Motor(const std::string& motorName)
    : name(motorName), speedPercent(0), enabled(false)
{
}

void Motor::setSpeed(int newSpeedPercent)
{
if (newSpeedPercent > 100)
    speedPercent = 100;
else if (newSpeedPercent < -100)
    speedPercent = -100;
else
    speedPercent = newSpeedPercent;

}

int Motor::getSpeed() const
{
    return speedPercent;
}

void Motor::enable()
{
    enabled = true;
}

void Motor::disable()
{
    enabled = false;
    speedPercent = 0;
}

bool Motor::isEnabled() const
{
    return enabled;
}

std::string Motor::getName() const
{
    return name;
}

// -----------------------
// PiCamera implementation
// -----------------------

// PiCamera::PiCamera()
//     : streaming(false)
// {
// }

// void PiCamera::startStream()
// {
//     streaming = true;
// }

// void PiCamera::stopStream()
// {
//     streaming = false;
// }

// bool PiCamera::isStreaming() const
// {
//     return streaming;
// }

// ------------------------
// Car implementation
// ------------------------

Car::Car()
    : frontLeft("front-left"),
      frontRight("front-right"),
      rearLeft("rear-left"),
      rearRight("rear-right"),
    //   camera(),
      x(0.0),
      y(0.0),
      headingDeg(0.0)
{
}

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

// void Car::cameraOn()
// {
//     camera.startStream();
// }

// void Car::cameraOff()
// {
//     camera.stopStream();
// }

double Car::getX() const
{
    return x;
}

double Car::getY() const
{
    return y;
}

double Car::getHeadingDeg() const
{
    return headingDeg;
}

Motor Car::getFrontLeftMotor() const
{
    return frontLeft;
}

Motor Car::getFrontRightMotor() const
{
    return frontRight;
}

Motor Car::getRearLeftMotor() const
{
    return rearLeft;
}

Motor Car::getRearRightMotor() const
{
    return rearRight;
}

CarSnapshot Car::getSnapshot() const
{
    CarSnapshot snap;

    snap.x = x;
    snap.y = y;
    snap.headingDeg = headingDeg;
    // snap.cameraStreaming = camera.isStreaming();

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








