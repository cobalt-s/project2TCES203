#ifndef PIGPIO_MOCK_H
#define PIGPIO_MOCK_H

#include <iostream>

#define PI_OUTPUT 1

inline int gpioInitialise() {
    //std::cout << "[MOCK] pigpio initialized" << std::endl;
    return 0;
}

inline void gpioTerminate() {
    //std::cout << "[MOCK] pigpio terminated" << std::endl;
}

inline int gpioSetMode(int gpio, int mode) {
    //std::cout << "[MOCK] Set GPIO " << gpio << " to mode " << mode << std::endl;
    return 0;
}

inline int gpioWrite(int gpio, int level) {
    //std::cout << "[MOCK] Write GPIO " << gpio << " = " << level << std::endl;
    return 0;
}

inline int gpioPWM(int gpio, int dutycycle) {
    //std::cout << "[MOCK] PWM GPIO " << gpio << " = " << dutycycle << std::endl;
    return 0;
}

#endif