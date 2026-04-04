//Detect a quick hand wave (close distance)
//Toggle a variable: robotEnabled
//If OFF → robot stays still
//If ON → robot runs your logic
#include <Servo.h>

// Ultrasonic
const int trigPin = 12;
const int echoPin = 13;

// Motors
const int leftDir  = 2;
const int leftPwm  = 5;
const int rightDir = 4;
const int rightPwm = 6;

// Line sensors
const int leftLinePin  = 7;
const int rightLinePin = 9;

// Servo
const int servoPin = 10;
Servo scanServo;

// -------- SETTINGS --------
int motorSpeed = 120;
int turnSpeed  = 130;

int obstacleThreshold = 15;

// servo positions, this are adjusted based on how the servo was mounted
int servoCenter = 90;
int servoLeft = 150;
int servoRight = 30;

// Gesture detection
int gestureDistance = 10;   // cm (hand close)
bool robotEnabled = false;
bool handDetected = false;

// -------- FUNCTIONS --------
float readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return 999;

  return (duration * 0.0343) / 2.0;
}

void stopCar() {
  analogWrite(leftPwm, 0);
  analogWrite(rightPwm, 0);
}

void forward() {
  digitalWrite(leftDir, HIGH);
  digitalWrite(rightDir, HIGH);
  analogWrite(leftPwm, motorSpeed);
  analogWrite(rightPwm, motorSpeed);
}
void backward() {
  digitalWrite(leftDir, LOW);
  digitalWrite(rightDir, LOW);
  analogWrite(leftPwm, motorSpeed);
  analogWrite(rightPwm, motorSpeed);
}

void turnLeft() {
  digitalWrite(leftDir, LOW);
  digitalWrite(rightDir, HIGH);
  analogWrite(leftPwm, turnSpeed);
  analogWrite(rightPwm, turnSpeed);
}

void turnRight() {
  digitalWrite(leftDir, HIGH);
  digitalWrite(rightDir, LOW);
  analogWrite(leftPwm, turnSpeed);
  analogWrite(rightPwm, turnSpeed);
}

// -------- LINE TRACKING --------
const int BLACK = 0;   // may need to flip

void lineTrack() {
  int left  = digitalRead(leftLinePin);
  int right = digitalRead(rightLinePin);

  if (left == BLACK && right == BLACK) {
    forward();
  }
  else if (left == BLACK) {
    turnLeft();
  }
  else if (right == BLACK) {
    turnRight();
  }
  else {
    forward();
  }
}

// -------- OBSTACLE AVOID --------
void avoidObstacle() {
  stopCar();
  delay(200);

  backward();
  delay(250);
  stopCar();
  delay(200);

  // Middle
  scanServo.write(servoCenter);
  delay(300);

  // Look left
  scanServo.write(servoLeft);
  delay(500);
  float leftDistance = readDistanceCM();

  // Back to middle
  scanServo.write(servoCenter);
  delay(300);

  // Look right
  scanServo.write(servoRight);
  delay(500);
  float rightDistance = readDistanceCM();

  // Back to middle
  scanServo.write(servoCenter);
  delay(300);

  Serial.print("Left distance: ");
  Serial.print(leftDistance);
  Serial.print(" | Right distance: ");
  Serial.println(rightDistance);

  if (leftDistance > rightDistance) {
    turnLeft();
    delay(400);
  } else {
    turnRight();
    delay(400);
  }

  stopCar();
}
// -------- SETUP --------
void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(leftDir, OUTPUT);
  pinMode(leftPwm, OUTPUT);
  pinMode(rightDir, OUTPUT);
  pinMode(rightPwm, OUTPUT);

  pinMode(leftLinePin, INPUT);
  pinMode(rightLinePin, INPUT);

  scanServo.attach(servoPin);
  scanServo.write(servoCenter);

  stopCar();
  delay(500);
}

// -------- LOOP --------
void loop() {
  scanServo.write(servoCenter); // this allows for the sensor to face foward
  float distance = readDistanceCM();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" | Enabled: ");
  Serial.println(robotEnabled);

  // -------- GESTURE DETECTION --------
  if (distance < gestureDistance && !handDetected) {
    robotEnabled = !robotEnabled;   // TOGGLE
    handDetected = true;

    Serial.println("TOGGLED STATE!");
    delay(500); // debounce
  }

  if (distance >= gestureDistance) {
    handDetected = false;
  }

  // -------- ROBOT OFF --------
  if (!robotEnabled) {
    stopCar();
    return;
  }

  // -------- ROBOT ON --------
  if (distance < obstacleThreshold) {
    avoidObstacle();
  } else {
    lineTrack();
  }

  delay(50);
}