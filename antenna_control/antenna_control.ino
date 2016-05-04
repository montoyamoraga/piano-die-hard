//antenna_control
//by corbin ordel and aaron montoya
//may 2016

//include interval file by tom igoe
#include "interval.h"

//declare variable for selecting output pin
int actuatorPin;

//declare variable for delaying
int delayTime;

//setup
void setup() {

  //initialize the global variables
  initGlobalVariables();

  // initialize digital pin 3 as an output.
  pinMode(actuatorPin, OUTPUT);

}

//method for setting up the global variables
void initGlobalVariables() {

  //set the pin as output
  actuatorPin = 3;

  //set the delay time
  delayTime = 8000;
   
}

//draw loop
// the loop function runs over and over again forever
void loop() {
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);
}
