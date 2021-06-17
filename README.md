# ZiiRobots-Example
@author Ellie Zhang (eyz2002)

This project is an example of how to use the I2C communication protocol between a controller seeeduino xiao board and an agent arduino mega2560 board.
The controller sends signals that are received by the agent. Specifically, the controller describes the movement and power (as a percentage of full power) of the robot.
The receiving agent then prints out the received signals, which details the power behind each wheel of the robot as set by the controller. In this case, negative numbers indicate a backwards trajectory. 

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
# Commander
Commander folder contains an example project of sending commands to ZiiROBOT series robots from an Seeeduino XIAO. The project can be used as a start point of developing your own software to control the robot from a device of your choice instead of using the Wireless Module that comes with the robot. 