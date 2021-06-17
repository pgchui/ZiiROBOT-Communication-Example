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
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  moveStraight(80, address);
  delay(1000);
  turn(30, 80, address);
  delay(1000);
  turn(80, 30, address);
  delay(1000);
  moveStraight(-60, address);
  delay(1000);
  stop(address);
  delay(1000);
}

/**
#include <Arduino.h>
#include <Wire.h>
const uint8_t address = 0x09;
void setup(){
  Serial.begin(9600);
  Wire.begin();
}

void loop(){
  Wire.beginTransmission(address);
  Wire.write("hello?");
  Wire.endTransmission(true);
}
*/