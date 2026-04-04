int leftPhotoSensor = A0;
int rightPhotoSensor = A3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leftValue = analogRead(leftPhotoSensor);
  int rightValue = analogRead(rightPhotoSensor);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print("   Right: ");
  Serial.println(rightValue);

  delay(200);
}