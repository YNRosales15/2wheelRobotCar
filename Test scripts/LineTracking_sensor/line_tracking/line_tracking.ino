void Infrared_Tracing() {
  int Left_Tra_Value = 1;
  int Right_Tra_Value = 1;
  int Black = 0;

  Left_Tra_Value = digitalRead(7);
  Right_Tra_Value = digitalRead(9);

  // 🔍 DEBUG PRINTS
  Serial.print("Left: ");
  Serial.print(Left_Tra_Value);
  Serial.print(" | Right: ");
  Serial.println(Right_Tra_Value);

  if (Left_Tra_Value != Black && Right_Tra_Value != Black) {
    Serial.println("FORWARD");
    digitalWrite(2, HIGH);
    analogWrite(5, 50);
    digitalWrite(4, LOW);
    analogWrite(6, 50);
  }
  else if (Left_Tra_Value == Black && Right_Tra_Value != Black) {
    Serial.println("TURN RIGHT");
    digitalWrite(2, LOW);
    analogWrite(5, 60);
    digitalWrite(4, LOW);
    analogWrite(6, 60);
  }
  else if (Left_Tra_Value != Black && Right_Tra_Value == Black) {
    Serial.println("TURN LEFT");
    digitalWrite(2, HIGH);
    analogWrite(5, 60);
    digitalWrite(4, HIGH);
    analogWrite(6, 60);
  }
  else if (Left_Tra_Value == Black && Right_Tra_Value == Black) {
    Serial.println("STOP");
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, LOW);
    analogWrite(6, 0);
  }

  Serial.println("----------------");
}
void setup(){
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(9, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  Infrared_Tracing();

}