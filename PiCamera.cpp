//Code from here: https://github.com/jeffmachyo/Raspberry-Pi-Camera-C-and-CPP/blob/main/cam.cpp

#include "PiCamera.h"
#include <signal.h>
#include <unistd.h>
#include <string>

static pid_t pid = 0;

/**
 * Takes a picture with the PiCam.
 * @param filename put the file name you want.
 */
void takePic (char* filename)
{
    if((pid = fork()) == 0)
    {
        execl("/usr/bin/raspistill",
            "/usr/bin/raspistill",
            "-n",
            "-vf",
            "-o",
            filename,
            NULL);
    }
}