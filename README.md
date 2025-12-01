# project2TCES203

# TCES 230 Group Project 2

This is a project meant to control a car in the lab, simulate the car moving with a simulator gui, and more. 

Authors: 
- Cobalt Stamey
- Jon 

## The structure for this program is as follows: 

### Car.cpp & Car.h
This is the code for the car controller, it functions as a way to initalize the motors, move the car, and more. 


### Controller.cpp & Controller.h
This is the program controller, it functions as the way to go throughout the program and all the menus. 

### LogFile.cpp & LogFile.h
This is the loggin capability, it allows you to log to a file which can save all the events that happen in the
program.

### Motor.cpp & Motor.h
This is the Motor Class it functions as a way to setup all the motors on the pi and a way to move them.

### pigpio_mock.h

This a mock library to let this program compile on windows since pigpio (the driver for the l298n for the pi is only
supported on linux.)

### Simulator.cpp & Simulator.h
This is the simulator for the program it simulates the car moving around a 2D grid and tests all the functions of the car.

### UserInterface.cpp & UserInterface.h
This is the user interface class it allows us to easily add and edit all the GUI for the program. 

## Steps to get working: 

### On the rasberry pi:
Install pigpio on Rasberry Pi: 

To get pigpio installed
- sudo apt-get update
- sudo apt-get install pigpio pigpio-dev

Then to compile do: 
- example code very cool. 

Then have fun! 



