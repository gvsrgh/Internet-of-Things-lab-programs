int ir = 2;  // Pin number for the IR sensor
int led = 3; // Pin number for the LED

void setup() {
  pinMode(ir, INPUT);   // Set IR sensor pin as INPUT
  pinMode(led, OUTPUT); // Set LED pin as OUTPUT
}

void loop() {
  int statusSensor = digitalRead(ir); // Read the status of the IR sensor
  
  if (statusSensor == 1) {
    digitalWrite(led, LOW); // Turn the LED OFF
  } else {
    digitalWrite(led, HIGH); // Turn the LED ON
  }
}
