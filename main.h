#ifndef CAR_CONTROLLER_H
#define CAR_CONTROLLER_H

#include <string>

/**
 * Prints the main menu.
 */
void printMenu();

/**
 * Prints the action menu.
 */
void printActionMenu();

/**
 * Moves the car in the specified direction.
 * @param direction the direction to move the car.
 */
void moveCar(char direction);

/**
 * Runs the action loop for controlling the car.
 * @return 0 if it runs successfully, non-zero otherwise.
 */
int actionLoop();

/**
 * Reads a line from standard input into `out`.
 * @param out string to store the line.
 * @return true if a line was read, false if input is closed.
 */
bool readLine(std::string &out);

/**
 * Gets the user's menu choice.
 * @return the choice as an int, or -1 on invalid input.
 */
int getUserChoice();

/**
 * Reads configuration from a file into speed and cameraMode.
 * @param speed output: configured speed.
 * @param cameraMode output: configured camera mode.
 */
void readFile(std::string &speed, std::string &cameraMode);

#endif // CAR_CONTROLLER_H