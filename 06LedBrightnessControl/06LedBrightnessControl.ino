int led = 11;        // Define the pin number for the LED
int value = 0;       // Variable to store the raw analog reading
int ledvalue = 0;    // Variable to store the mapped value for LED brightness

void setup() {
    pinMode(led, OUTPUT);   // Set the LED pin as an output
}

void loop() {
    value = analogRead(A0);            // Read the analog input from pin A0
    ledvalue = map(value, 0, 1024, 0, 255);  // Map the analog input value to a range suitable for PWM (0-255)
    analogWrite(led, ledvalue);        // Write the PWM value to control the brightness of the LED
}
