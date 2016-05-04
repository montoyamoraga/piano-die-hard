//antenna_control
//by corbin ordel and aaron montoya
//may 2016

//declare variable for left and right pin
int directionPin;

//declare variable for delaying
int delayTime;

//declare speed of serial port
int serialRate;

//declare variable for storing current data
int rawData;

//declare variable to store data from max
int explosion;

//declare current state of the machine
boolean goesLeft;

//setup
void setup() {

  //initialize the global variables
  initGlobalVariables();

  //method for setting digital pin modes
  declarePinModes();

  //set serial port communication
  Serial.begin(serialRate);
}

//loop
void loop() {
  // put your main code here, to run repeatedly:

  //receive data from serial
  getSerial();

  //update the values
  updateValues();

  //decide direcion to go next
  decideDirection();

}

//method for setting up the global variables
void initGlobalVariables() {

  //set the pin for left and right
  directionPin = 3;

  //set the delay time
  delayTime = 200;

  //set the speed for serial communication
  serialRate = 9600;

  //variable to store data from max
  explosion = 0;

  //declare current state of the machine
  goesLeft = true;
}

//set the digital pin modes
void declarePinModes() {
  //set pin for left and right as output
  pinMode(directionPin, OUTPUT);
}

//get info from serial
void getSerial() {

  //check for incoming message
  if (Serial.available() > 0) {

    rawData = Serial.read();

    if (rawData == 48) {
      explosion = 1;
    }
    else if (rawData == 49) {
      explosion = 0;
    }
    else {
      rawData = 1 - rawData;
    }
  }
}


//update values in arduino
//according to info from max
void updateValues() {

  if (explosion == 0) {
    goesLeft = true;
  }
  else if (explosion == 1) {
    goesLeft = false;
  }

}

//decide direction according
//to info from max
void decideDirection() {
  if (goesLeft) {
    moveLeft();
  }
  else {
    moveRight();
  }
}

//move antenna to the left
void moveLeft() {
  digitalWrite(directionPin, LOW);
  delay(delayTime);
}

//move antenna to the righr
void moveRight() {
  digitalWrite(directionPin, HIGH);
  delay(delayTime);
}
