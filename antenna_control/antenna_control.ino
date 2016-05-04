//antenna_control
//by corbin ordel and aaron montoya
//may 2016


//include interval file by tom igoe
#include "interval.h"

//declare variable for selecting output pin
int actuatorPin;

//declare variable for delaying
int delayTime;

//declare variable to store output state
int state;

//declare speed of serial port
int speed;

//declare timer
Timer testing;

//setup
void setup() {

  //initialize the global variables
  initGlobalVariables();

  // initialize digital pin 3 as an output.
  pinMode(actuatorPin, OUTPUT);

  //set serial port communication
  Serial.begin(speed);

}

//method for setting up the global variables
void initGlobalVariables() {

  //set the pin as output
  actuatorPin = 3;

  //set the delay time
  delayTime = 8000;

  //set the initial state of the
  state = HIGH;

  //set the speed for serial communication
  speed = 9600;

}

//draw loop
// the loop function runs over and over again forever
void loop() {

  //output state
  digitalWrite(3, state);

  //toggle state
  state = !state;

  //wait
  delay(delayTime);

  //output state
  digitalWrite(3, state);

  //toggle state
  state = !state;

  //wait
  delay(delayTime);
}
