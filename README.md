# CS207 Autonomous race car project 1.0
===================================

This project is an arduino uno based autonomus race car. The goal of this project is to convert an existing RC car to a autonomus car so that no longer needs any user input to drive. The car will used ultra sonic sensors to detect and avoid objects in its path. It will also use a motor driver board to control the speed and direction of the cars motors as well as let the motors be powered by an external power supply. The car will also use four LEDs to indicate which direction it will turn as it approaches an object.

Repository Contents
============
* **/hardware** - This is where the fritzing schematic is stored
* **/img** - where images of the project and schematic are stored
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
* 1 x 9V battery clip
* 1 x 9V battery
* 5 x AA batteries
* 1 x 5xAA battery holder
* 2 x 560 ohm Resistor
* 1 x breadboard
* 1 x arduino uno

Useful materials:
* female to male jumpers

Build Instructions
==================

### 1. Removing the RC car's micro controller

The first step to building an autonomous RC car is removing the car's built in micro controller. To do this you must first remove the battery from the car. Then you should locate and remove the screws on the bottom of the car that hold the top of the car in place. Once you remove the top of the car, locate the cars micro controller. After you have located the cars micro controller cut the wires that are connecting it to the front and back motors. make sure to cut off the least amount of wire until you know exactly how long you will want them to be.

### 2. Signal LEDs

The next step is to install the LEDs that are going to be used to signal the direction that the car is going to turn. To install the LEDs connect a numbered digital pin on the arduino to a Terminal strip on the breadboard. Then connect the ground pin on the arduino to a ground rail on the breadboard. From there you will want to use the 560 ohm resistor to connect the ground rail on the breadboard to a Terminal strip on the breadboard that is directly adjacent to the one connected to the digital pin. Once one Terminal strip is connected to the ground rail and the other is connected a digital pin you can connect two LEDs to the Terminal strips either directly or using a jumper. The long leg of the LEDs connects to the Terminal strip that goes to the digital pin and the short leg connects to the Terminal strip that goes to the ground. Repeat this one more time so that you have two LEDs to signal left and two LEDs to signal right.

### Ultrasonic Sensor

Once the LEDs are done it is time to move on to the Ultrasonic Sensor. The Ulstrasonic sensor only requires four jumpers to connect it to the arduino. First connect the ground pin on the Ultrasonic sensor to either the ground rail on the breadboard or an open ground pin on the arduino. Then connect the power pin on the ultrasonic sensor to either the 5v pin on the arduino or if the 5v pin is connected to the breadboard connect it to the positive rail on the breadboard. After the ultrasonic sensor has power connect both the trigger and echo pins on the sensor to two different digital pins on the arduino. I personally prefer to connect the echo and trigger to none pwm pins so that I can use them for other things that may need analog outputs or inputs.

### Motor driver

There are three stages to setting up the motor driver board. The first stage is connecting the motors to the board. To connect the motors to the board the first step would be to strip a bit of insulation from the wires connecting to the motors so that they can make a proper connection with the "OUT" ports on the board. Once that is finished place the front motors wires in the "OUT1" and "OUT2" ports on the board. Then place the rear motors wires in the "OUT3" and "OUT4" spots on the board. The order that the wires are placed in the board does not matter it only changes the direction that the motors go which can be fixed in code. 

The second step is to connect the motor driver board to the arduino. First connect the "ENA" and "ENB" pins to two PWM pins on the arduino. Then connect the "IN1", "IN2", "IN3", and "IN4" pins on the motor driver board to any digital pins on the arduino. Once all of the pins are connected to the arduino, connect the on the motor driver board's ground port to the grounded rail on the breadboard.

### Power Supply's

After the project is fully assembled and good to go it is time to connect the batteries to make it run. The first part that should be powered is the motor driver board since the car won't drive until the arduino has power and has the code uploaded. To connect the motor driver board to the 9V battery, connect the 9V battery to the 9V battery clip. Then strip the ends of the 9V battery clips wires so that they will fit into the ports on the motor driver board. Once the wires are stripped connect the red wire to the 12V port on the motor driver board. Then connect the black wire to the ground port on the motor driver board with the ground that is running to the breadboard. Once the motors have power place the 5 AA's in to the battery holder and then plug the battery holder into the arduino.


### Final build schematic 

![alt text][Schematic]

[Schematic]: https://github.com/weRthem/CS207-Patrick-Larsen/blob/master/img/schematic_Build_View_schem.jpg "final build Schematic"

Usage
=====

Usage of this project is pretty simple you just upload the code to the arduino. After the code is uploaded disconnect the car from the computer. From there you need to plug the battery pack into the arduino and press the reset button on the arduino. Once all of this is done all you need to do is place the car on the floor and let it drive around. If you want to make the car stop driving all you have to do is place your hand 5cm or less in front of the ultrasonic sensor and the car will stop moving. To get the car going again all you have to do is press the reset button on the arduino.

Credits
=======

* Dejan Nedelkovski at www.HowToMechatronics.com - Ultrasonic Sensor HC-SR04 code
* jesper birk at http://www.instructables.com/id/Autonomous-Race-Car/ - The project idea and instructions
