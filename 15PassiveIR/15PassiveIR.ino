int LEDpin = 13; // Connect RED LED at 13 pin
int obstaclePin = 2;
int hasObstacle = LOW; // LOW MEANS NO OBSTACLE

void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  hasObstacle = digitalRead(obstaclePin);
  
  if (hasObstacle == HIGH) {
    Serial.println("Stop");
    digitalWrite(LEDpin, HIGH);
  } else {
    Serial.println("Go");
    digitalWrite(LEDpin, LOW);
  }
  
  delay(200);
}
