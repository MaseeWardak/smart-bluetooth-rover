// Created by Masee! The code functions as intended, if you want a homemade bluetooth car then this is what you
need to upload to your Arduino!

#include <Servo.h>
#include <SoftwareSerial.h>


// Defining Motor Pins for DC movement motors (3-12v and 25000 RPM)
const int ENA = 6; // Speed control pin
const int IN1 = 5; // Direction #1 pin
const int IN2 = 11; // Direction #2 pin

// Defining MG90S Pin
Servo myservo;

// Defining HC-05 and commands related to it
SoftwareSerial bluetoothSerial(2, 3); // RX, TX
char bluetooth;
char lastCommand;

// Tracking the state:
bool movingForward = false;
bool movingBackward = false;
bool movingLeft = false;
bool movingRight = false;

// Debounce timer variables:
unsigned long lastcommandTimer = 0;
const unsigned long debounceDelay = 210;

// Move forward function:
void moveForward(){
  analogWrite(ENA, 240);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

// Move Backwards Function:
void moveBackward(){
  analogWrite(ENA, 240);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

//Steering centered Function:
void centerServo() {
  myservo.write(90);
}

// Stop Function:
void stopCar(){
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void setup() {
  // Declaring that the motor is an output:
  myservo.attach(9);
  centerServo();
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // This part makes the car move and steer, the car moves forward/backward -
  // on the press of a button and will not stop until the button is pressed again:
  if (bluetoothSerial.available() > 0){
    bluetooth = bluetoothSerial.read(); // This line checks if there is a signal available, if it is, it will be assigned to bluetooth. 
    if (millis() - lastcommandTimer >= debounceDelay) {
      lastCommand = millis(); // This line of code adds a 210ms delay between presses by introducing a debounce delay, it checks if
      // millis() - lastcommandTimer is greater than or equal to the debounce delay. If it is, then it will initiate the rest of the code that follows.
      // if it isn't, the loop is effectively skipped and the car will not receive the command entered within the 210ms after a command that was initiated.
      if (bluetooth == 'F') {
        if (movingForward == false) {
          movingForward = true;
          movingBackward = false;
          moveForward();
        } // The rest of code controls the movement using the functions and variables defined on the top of the sketch.
        else {
          movingForward = false;
          stopCar();
        }
      }
      else if (bluetooth == 'B') {
        if (movingBackward == false) {
          movingBackward = true;
          movingForward = false;
          moveBackward();
        }
        else {
          movingBackward = false;
          stopCar();
      }}
      else if (bluetooth == 'L') {
        if (movingLeft == false) {
          movingLeft = true;
          movingRight = false;
          myservo.write(0);
        }
        else {
          movingLeft = false;
          centerServo();
        }
      }
      else if (bluetooth == 'R') {
        if (movingRight == false) {
          movingRight = true;
          movingLeft = false;
          myservo.write(180);
        }
        else {
          movingRight = false;
          centerServo();
        }
      }
  } }
}
