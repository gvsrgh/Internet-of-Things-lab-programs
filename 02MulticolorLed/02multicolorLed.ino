int red = 2;   // Pin number for the red LED
int green = 3; // Pin number for the green LED
int blue = 4;  // Pin number for the blue LED

void setup() {
  // Initialize LED pins as an output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // Turn the RED LED on, and others off
  digitalWrite(red , 1);
  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  delay(1000); // Wait for a second
  
  // Turn the GREEN LED on, and others off
  digitalWrite(red, 0);
  digitalWrite(green, 1);
  digitalWrite(blue, 0);
  delay(1000); // Wait for a second
  
  // Turn the BLUE LED on, and others off
  digitalWrite(red, 0);
  digitalWrite(green, 0);
  digitalWrite(blue, 1);
  delay(1000); // Wait for a second
}
