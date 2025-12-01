//
// Created by Cobalt Stamey on 11/29/25.
//

#ifndef LOGFILE_H
#define LOGFILE_H
#include <fstream>
#include <string>

class LogFile {
    public:
        LogFile();
        ~LogFile();

        void logLeft();
        void logRight();
        void logRotateLeft();
        void logRotateRight();
        void logBack();
        void logForward();
        void logStop();
        void logCamera(const std::string& state);
    private:
        std::ofstream file;

};

#endif //LOGFILE_H
