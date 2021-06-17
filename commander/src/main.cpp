/**
 * @file: Controller.cpp
 * @brief: Code allowing controller to communicate with agent 
 * @brief: Controller sends robot movement instructions to agent
 * @author: Ellie Zhang
 * @bug: No known bugs
*/



#include <Arduino.h>
#include <Wire.h>

const uint8_t address = 0x09;

/**
 * @brief: Sets the power/speed of the robots movement for left and right wheels
 * @param: Power of left wheel as a percentage
 * @param: Power of right wheel as a percentage
 * @param: binary address of agent that controller sends message to
 * @return: None
 */
void setPower(int leftWheel, int rightWheel, uint8_t address){
  Wire.beginTransmission(address);
  Wire.write('l');
  Wire.write(leftWheel);
  Wire.write('r');
  Wire.write(rightWheel);
  Wire.endTransmission(true);
}
void moveStraight(int power, uint8_t address){
  setPower(power,power, address);
}
void turn(int leftWheel, int rightWheel, uint8_t address){
  setPower(leftWheel, rightWheel, address);
}
void stop(uint8_t address){
  moveStraight(0, address); 
}

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP); // enable internal pull-up resistor of SDA
  pinMode(5, INPUT_PULLUP); // enable internal pull-up resistor of SCL
  Wire.begin();
}

void loop() {
  moveStraight(80, address);  // move forward at power of 80%
  delay(1000);
  turn(30, 80, address);  // turn left at power of 30% (left) and 80% (right)
  delay(1000);
  turn(80, 30, address);  // turn right at power of 80% (left) and 30% (right)
  delay(1000);
  moveStraight(-60, address); // move back at power of 60%
  delay(1000);
  stop(address);  // stop
  delay(1000);
}
