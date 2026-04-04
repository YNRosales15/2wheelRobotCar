#include <Servo.h>

Servo myServo;
const int servoPin = 10;

// Adjust as needed based on how Servo is installed
int center = 90;
int left   = 150;   
int right  = 30;    

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  // Middle
  myServo.write(center);
  delay(1000);

  // Left
  myServo.write(left);
  delay(1000);

  // Back to middle
  myServo.write(center);
  delay(1000);

  // Right
  myServo.write(right);
  delay(1000);

  // Back to middle
  myServo.write(center);
  delay(1000);
}