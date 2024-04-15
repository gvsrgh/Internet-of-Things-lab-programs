int in1 = 6;
int in2 = 7;
int enA = 9;
int Speed = 0;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

// Enter value 0 or 1 to select motor direction, 0 for Backward, 1 for Forward
void loop() {
  val = analogRead(A0); // Read potentiometer value to change the Motor speed
  Speed = map(val, 0, 1023, 0, 255);

  if (Serial.available() > 0) {
    char state = Serial.read();
    // FORWARD rotation
    if (state == '1') {
      analogWrite(enA, Speed);
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      Serial.println("FORWARD");
      delay(1000);
    }
    // BACKWARD rotation
    if (state == '0') {
      analogWrite(enA, Speed);
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      Serial.println("BACKWARD");
      delay(1000);
    }
  }
}
