# ZiiRobots-Example
@author Ellie Zhang (eyz2002)

This project is an example of how to use the I2C communication protocol between a controller seeeduino xiao board and ZiiROBOT series robots.
The controller sends signals that are received by the robots. Specifically, the controller describes the movement and power (as a percentage of full power) of the robot.

# I2C Slave Address of ZiiROBOT
0x09
# I2C Packet
```
int8_t power1, power2; // power of left and right motor respectively
int8_t command[4];
command[0] = 'l';
command[1] = power1; // [-100, 100]
command[2] = 'r';
command[3] = power2; // [-100, 100]
```
# I2C Bus Pull-Up Resistors
By default, ZiiROBOT's on-board pull-up resistors of I2C bus are disconnected. To make the I2C bus work properly, enable the internal pull-up resistors of your microcontroller or connect the jumpers to use on-board pull-up resistors.
# Commander
Commander folder contains an example project of sending commands to ZiiROBOT series robots from an Seeeduino XIAO. The project can be used as a start point of developing your own software to control the robot from a device of your choice instead of using the Wireless Module that comes with the robot. 