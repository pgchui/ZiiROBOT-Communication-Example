/**
 * @file: Receiver
 * @brief: Code allowing agent to communicate with controller. Agent receives signal from controller and reads its messages.
 * @author: Ellie Zhang
 * @bug: No known bugs
*/

#include <Arduino.h>
#include <Wire.h>

/**
 * @brief: Converts negative numbers sent by controller from twos complement to standard decimal form
 * @param: Integer sent by controller in twos complement form
 * @return: Original integer as sent by controller
*/
inline int checkNegative(int num){
  if (num > 127){
    num = num - 256;
  }
  return num;
}

/**
 * @brief: Reads message from controller
 * @param: Arbitrary integer 
 * @return: None
*/
void receiveEvent(int number){
  char c = Wire.read();
  Serial.print(c);
  int x = Wire.read();
  Serial.println(checkNegative(x));
  char d = Wire.read();
  Serial.print(d);
  int y = Wire.read();
  Serial.println(checkNegative(y));
  while (Wire.available())
  {
    Wire.read();
  }

/**
 * @brief: Initiates agent communication with controller
 * @param: None
 * @return: None
*/
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  const uint8_t address = 0x09;
  Wire.begin(address);
  Wire.onReceive(receiveEvent);
}

/**
 * @brief: Runs repeatedly with small delay
 * @param: None
 * @return: None
*/
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
