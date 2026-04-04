// Testing script to make sure  the motots work

const int left_Dir = 2; // controls direction of left motor connected on A1
const int left_speed = 5; // controls speed of left motor 
const int right_Dir = 4; // controls direction of right motor connected on B1
const int right_speed = 6; // controls speed of right motor


void setup(){
  pinMode(left_Dir, OUTPUT);//Direction motor A1 (Left side)
  pinMode(left_speed, OUTPUT); // Speed of motor A1 (Left side)
  pinMode(right_Dir, OUTPUT); //Direction motor B1 (Right side)
  pinMode(right_speed, OUTPUT); // Speed of motor B1 (Right side)
}

void loop(){
// Forwrd
  digitalWrite(left_Dir,HIGH); //D2 digital I/O port controls the direction of the motor in A1
  analogWrite(left_speed,50); // D5 digital I/O port outputs PWM signal to control the speed of the motor in A1
  digitalWrite(right_Dir,LOW);// D4 digital I/O port controls the direction of the motor in B1
  analogWrite(right_speed,50); // D6 digital I/O port outputs PWM signal to control the speed of the motor in B1
  delay(2000); // delay in seconds in this case 2sec

  // backward
  digitalWrite(left_Dir,LOW);
  digitalWrite(right_Dir,LOW);
  delay(2000);

// turn left
  digitalWrite(left_Dir,LOW);
  digitalWrite(right_Dir,HIGH);
  delay(2000);

  // turn right
  digitalWrite(left_Dir,HIGH);
  digitalWrite(right_Dir,LOW);
  delay(2000);

// stop
  analogWrite(left_speed,0);
  analogWrite(right_speed,0);
  delay(2000);

}
