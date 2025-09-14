#include <Servo.h>
#include <SoftwareSerial.h>

//This sketch is created by Masee! Feel free to use it as a reference for your projects.

// Defining Motor Pins for DC movement motors (3-12v and 25000 RPM)
const int ENA = 6; // Speed control pin
const int IN1 = 5; // Direction #1 pin
const int IN2 = 11; // Direction #2 pin

// Defining Ultrasonic sensor pins
const int trigPin = 4;
const int echoPin = 7;
const int trigPin2 = 8;
const int echoPin2 = 10;

// Variables for storing pulse info:
long duration;
long duration2;
int distance;
int distance2;

// Defining MGS90 Pin
Servo myservo;

// Defining HC-05 and commands related to it
char bluetooth;

// Tracking the state:
bool movingForward = false;
bool movingBackward = false;
bool movingLeft = false;
bool movingRight = false;

// Debounce timer variables:
unsigned long lastcommandTimer = 0;
const unsigned long debounceDelay = 100;

// Move forward function:
void moveForward(){
  analogWrite(ENA, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

// Move Backwards Function:
void moveBackward(){
  analogWrite(ENA, 255);
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
  movingForward = movingBackward = false;
}

//Ultra-sonic Brake Function:
void brake(){
  if (distance <= 35){
    if (movingForward == true) {
      // If osbtacle is in the front, reverse a bit to kill momentum and stop.
      movingForward = false;
      moveBackward();
      delay(350);
      stopCar();
  }}
  if (distance2 <= 35) {
    if (movingBackward == true) {
      // If obstacle is in the back, go forward a bit to kill momentum and stop.
      movingBackward = false;
      moveForward();
      delay(350);
      stopCar(); 
  }}
}

void setup() {
  // Declaring outputs/inputs:
  myservo.attach(9);
  centerServo();
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
// Sending a Pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Storing the Pulse in the duration variable we defined above:
  duration = pulseIn(echoPin, HIGH);
  // Converting duration to distance:
  distance = (duration*.0343)/2; 

// Sensor #2:
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  //Sensor #2:
  duration2 = pulseIn(echoPin2, HIGH);
  //Sensor 2:
  distance2 = (duration2*.0343)/2;

  // This part makes the car move and steer, the car moves forward/backward -
  // on the press of a button and will not stop until the button is pressed again:
  if (Serial.available() > 0){
    bluetooth = Serial.read(); // This line checks if there is a signal available, if it is, it will be assigned to bluetooth. 
    if (millis() - lastcommandTimer >= debounceDelay) {
      lastcommandTimer = millis(); // This line of code adds a 210ms delay between presses by introducing a debounce delay, it checks if
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
          myservo.write(40);
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
          myservo.write(150);
        }
        else {
          movingRight = false;
          centerServo();
        }
      }
  } }
  //Check if it needs to brake:
  brake();
}
