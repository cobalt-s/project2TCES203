#ifndef CAR_H
#define CAR_H
#include <string>
#include "Motor.h"

/**
 * Header file used to represent a four-wheeled RC Car
 * 
 * Jonathan Lee
 * TCES 203 A
 * Project 2
 */

/**
 * Camera for the RC car
 */
class Camera {
    private:
        bool streaming;
    public:
        Camera();
        void startStreaming();
        void stopStreaming();
        void captureFrame(double captureX, double captureY);
        bool isStreaming() const;
};

// Enumerated type for high-level movement commands.
enum class MovementCommand {
    MoveForward,
    MoveBackward,
    StrafeLeft,
    StrafeRight,
    RotateLeft,
    RotateRight,
    Stop
};

// Structure to capture the state of a single motor at one instant.
struct MotorSnapshot {
    std::string name;
    int speedPercent;
    bool enabled;
};

// Structure to capture the full state of the car at one instant.
struct CarSnapshot {
    double x;
    double y;
    double headingDeg;
    bool cameraStreaming;

    MotorSnapshot frontLeft;
    MotorSnapshot frontRight;
    MotorSnapshot rearLeft;
    MotorSnapshot rearRight;
};


/**
 * Main class for representing a four-wheeled RC car
 */
class Car {
    private:
        Motor frontLeft;
        Motor frontRight;
        Motor rearLeft;
        Motor rearRight;

        double x;           // current x position
        double y;           // current y position
        double headingDeg;  // current heading in degrees [0, 360)
        Camera camera;

        void updatePose(double dx, double dy, double dThetaDeg);

    public:
        Car();

        void moveForward(double distance);
        void moveBackward(double distance);
        void strafeLeft(double distance);
        void strafeRight(double distance);
        void rotateLeft(double angleDeg);
        void rotateRight(double angleDeg);

        void stopAllMotors();

        void cameraOn();
        void cameraOff();

        double getX() const;
        double getY() const;
        double getHeadingDeg() const;

        Motor getFrontLeftMotor() const;
        Motor getFrontRightMotor() const;
        Motor getRearLeftMotor() const;
        Motor getRearRightMotor() const;


        /**
         * Applys a movement given a command and distance/angle.
         * @param cmd the movement command.
         * @param value the value distance or angle.
         */
        void applyCommand(MovementCommand cmd, double value);

        /**
         * Applys a movement given just a command.
         * @param cmd the movement command.
         */
        void applyCommand(MovementCommand cmd);

        // New in Activity 14:
        // Return a CarSnapshot that captures the full current state.
        CarSnapshot getSnapshot() const;
};

#endif