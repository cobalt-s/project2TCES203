#include "LogFile.h"
#include <filesystem>
#include <iostream>
#include "UserInterface.h"

/**
 * Creates the logfile dir if none is made, starts the
 * logging.
 */
LogFile::LogFile()
{
    std::filesystem::create_directories("logfiles");

    file.open("logfiles/log.txt");
    file << "---LOG START---\n";

    // printing the absolute path
    std::filesystem::path logPath = std::filesystem::absolute("logfiles/log.txt");
    std::cout << "log file saved to: " << logPath << "\n";
}

/**
 * Ends the logging process and closes the file.
 */
LogFile::~LogFile()
{
    file << "---LOG ENDED---\n";
    file.close();
}

void LogFile::logLeft()
{
    file << "Left\n";
}

void LogFile::logRight()
{
    file << "Right\n";
}

void LogFile::logRotateLeft()
{
    file << "Rotate left\n";
}

void LogFile::logRotateRight()
{
    file << "Rotate right\n";
}

void LogFile::logBack()
{
    file << "Backward\n";
}

void LogFile::logForward()
{
    file << "Forward\n";
}

void LogFile::logStop()
{
    file << "Stop\n";
}

/**
 * Logs the camera state
 * @param state the camera state
 */
void LogFile::logCamera(const std::string &state)
{
    file << "CAMERA: " << state << "\n";
}
