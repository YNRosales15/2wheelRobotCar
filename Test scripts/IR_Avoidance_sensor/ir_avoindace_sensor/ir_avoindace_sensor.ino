int right_AvoidSensor = A1; // Declaration of the pin used
int left_AvoidSensor = A2;

int rightvalue;
int leftvalue;

void setup() {
  pinMode(right_AvoidSensor, INPUT_PULLUP);
  pinMode(left_AvoidSensor, INPUT_PULLUP);

  Serial.begin(9600); // initializes the baud rate serial monitor
  Serial.println("Running..."); 
}

void loop() {
   rightvalue = digitalRead(right_AvoidSensor);
   leftvalue = digitalRead(left_AvoidSensor);

   Serial.print("Right: ");
   Serial.print(rightvalue);
    Serial.print(" | Left: ");
   Serial.print(leftvalue);

    if (rightvalue == HIGH && leftvalue == HIGH) {
        Serial.println("Forward");
    }
    else if (rightvalue == HIGH && leftvalue == LOW) {
        Serial.println("Turn Right");
    }
    else if (rightvalue == LOW && leftvalue == HIGH) {
        Serial.println("Turn Left");
    }
    else {
      Serial.println("Stop / BACK");
    }
    delay(200);
}

