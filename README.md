# ZiiRobots-Example
/**
@author Ellie Zhang (eyz2002)

This project is an example of how to use the I2C communication protocol between a controller seeeduino xiao board and an agent arduino mega2560 board.
The controller sends signals that are received by the agent. Specifically, the controller describes the movement and speed (as a percentage of full speed) of the robot.
The receiving agent then prints out the received signals, which details the power behind each wheel of the robot as set by the controller. In this case, negative numbers indicate a backwards trajectory. 

*/
