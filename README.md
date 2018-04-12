# CS207 Autonomous race car project 1.0
===================================

This project is an arduino uno based autonomus race car. The goal of this project is to convert a existing RC car to a autonomus car that no longer needs user input to drive. The car will used ultra sonic sensors
to detect and avoid objects in its path.

Repository Contents
============
* **/src** - where the files that should be uploaded to the arduino are stored
* **/LICENSE** - MIT
* **/README.md**

Requirements and Materials
============
Dependencies: 
* none

Bill of Materials:
* 4 x Red LEDs
* 1 x hc-sr04 Ultrasonic sensor
* 1 x L298N motor driver board
* 1 x 9V battery
* 2 x 560 ohm Resistor
* 1 x breadboard
* 1 x arduino uno

Build Instructions
==================

### 1. Removing the RC car's micro controller

The first step to building an autonomous RC car is removing the car's built in micro controller. To do this you must first remove the battery from the car. Then you should locate and remove the screws on the bottom of the car that hold the top of the car in place. Once you remove the top of the car, locate the cars micro controller. After you have located the cars micro controller cut the wires that are connecting it to the front and back motors. make sure to cut off the least amount of wire until you know exactly how long you will want them to be.

### 2. Signal LEDs



### Ultrasonic Sensor

### Motor driver

### Batteries

![alt text] [Schematic_Build_View]

[Schematic_Build_View]: https://github.com/weRthem/CS207-Patrick-Larsen/blob/master/img/schematic_Build_View_schem.jpg

Usage
=====

Usage of this project is pretty simple you just upload the code to the arduino. After the code is uploaded disconnect the car from the computer. From there you need to plug the battery pack into the arduino and press the reset button on the arduino. Once all of this is done all you need to do is place the car on the floor and let it drive around. If you want to make the car stop driving all you have to do is place your hand 5cm or less infront of the ultrasonic sensor and the car will stop moving. To get the car going again all you have to do is press the reset button on the arduino.

Credits
=======

* Dejan Nedelkovski at www.HowToMechatronics.com - Ultrasonic Sensor HC-SR04 code
* jesper birk at http://www.instructables.com/id/Autonomous-Race-Car/ - The project idea and instructions
