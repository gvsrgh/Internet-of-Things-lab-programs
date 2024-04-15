void setup() {
    pinMode(13, OUTPUT);  // Set pin 13 as an output
    Serial.begin(9600);   // Initialize serial communication with a baud rate of 9600
}

void loop() {
    if (Serial.available() > 0) {  // Check if there is data available to read from serial
        char state = Serial.read();  // Read a single character from serial

        if (state == '1') {  // If the received character is '1'
            digitalWrite(13, HIGH);  // Turn on the LED connected to pin 13
            Serial.println("LED ON");  // Print message to serial monitor
        }

        if (state == '0') {  // If the received character is '0'
            digitalWrite(13, LOW);  // Turn off the LED connected to pin 13
            Serial.println("LED OFF");  // Print message to serial monitor
        }
    }
    delay(100);  // Delay to avoid reading serial too quickly
}
