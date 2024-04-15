int slotSensor = 2; // Corrected variable name (no spaces allowed)
int led = 13;

void setup() {
  pinMode(slotSensor, INPUT);
  pinMode(led, OUTPUT); // Corrected the usage of pinMode for the LED pin
}

void loop() {
  int value = digitalRead(slotSensor);
  if (value == HIGH) { // HIGH is used instead of 1 for better readability
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
