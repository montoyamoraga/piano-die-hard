//antenna_control
//by corbin ordel and aaron montoya
//may 2016

//declare variable for left and right pin
int directionPin;

//declare variable for delaying
int delayTime;

//declare variable to store output state
int state;

//declare speed of serial port
int serialRate;

//declare variable to store data from max
int explosion;

//declare current state of the machine
boolean goesLeft;


void setup() {

  //initialize the global variables
  initGlobalVariables();

  //method for setting digital pin modes
  declarePinModes();

  //set serial port communication
  Serial.begin(serialRate);
}

void loop() {
  // put your main code here, to run repeatedly:

  updateValues();

  if (goesLeft) {
    moveLeft();
  }
  else {
    moveRight();
  }

}

//method for setting up the global variables
void initGlobalVariables() {

  //set the pin for left and right
  directionPin = 3;
  
  //set the delay time
  delayTime = 200;

  //set the initial state of the
  state = HIGH;

  //set the speed for serial communication
  serialRate = 9600;

  //variable to store data from max
  explosion = 0;

  //declare current state of the machine
  goesLeft = true;

}

void declarePinModes() {
  //set pin for left and right as output
  pinMode(directionPin, OUTPUT);
}

void updateValues() {

  if (explosion == 0) {
    goesLeft = true;
  }
  else if (explosion == 1) {
    goesLeft = false;
  }

}

void moveLeft() {
  digitalWrite(directionPin, LOW);
  delay(delayTime);
}

void moveRight() {
  digitalWrite(directionPin, HIGH);
  delay(delayTime);
}
