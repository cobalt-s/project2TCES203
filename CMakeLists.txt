cmake_minimum_required(VERSION 3.16)
project(PROJECT2TCES203)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PROJECT2TCES203
    main.cpp
    #Car.cpp
    #Motor.cpp
    Simulator.cpp
        UserInterface.cpp
        UserInterface.h
        Controller.cpp
        Controller.h
        LogFile.cpp
        LogFile.h
        PiCamera.cpp
        PiCamera.h
)