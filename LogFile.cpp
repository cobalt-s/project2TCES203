//
// Created by Cobalt Stamey on 11/29/25.
//

#include "LogFile.h"
#include <filesystem>
#include <iostream>

/**
 * Creates the logfile dir if none is made, starts the
 * logging.
 */
LogFile::LogFile()
{
    std::filesystem::create_directories("logfiles");

    file.open("logfiles/log.txt");
    file << "---LOG START---\n";

    //printing the absolute path
    std::filesystem::path logPath = std::filesystem::absolute("logfiles/log.txt");
    std::cout << "log file saved to: " << logPath << std::endl;
}

/**
 * Ends the logging process and closes the file.
 */
LogFile::~LogFile()
{
    file << "---LOG ENDED---\n";
    file.close();
}

/**
 * Logs left
 */
void LogFile::logLeft()
{
    file << "LEFT\n";
}

/**
 * Logs right
 */
void LogFile::logRight()
{
    file << "RIGHT\n";
}

/**
 * Logs back
 */
void LogFile::logBack()
{
    file << "BACKWARD\n";
}

/**
 * Logs forward.
 */
void LogFile::logForward()
{
    file << "FORWARD\n";
}

/**
 * Logs stop.
 */
void LogFile::logStop()
{
    file << "STOP\n";
}

/**
 * Logs the camera state
 * @param state the camera state
 */
void LogFile::logCamera(const std::string &state)
{
    file << "CAMERA: " << state << "\n";
}


