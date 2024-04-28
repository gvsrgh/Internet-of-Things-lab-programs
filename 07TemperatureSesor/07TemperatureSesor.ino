#include <dht.h>   // Include the DHT library

dht DHT;           // Create an instance of the DHT object
#define DHT11_PIN 8 // Define the pin number to which the DHT11 sensor is connected

void setup() {
  Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);  // Read data from the DHT11 sensor connected to pin 8
  if (chk == DHTLIB_OK) {  // Check if the reading was successful
    Serial.print("Temperature= ");     // Print the label for temperature
    Serial.println(DHT.temperature);   // Print the temperature value read from the sensor
    Serial.print("Humidity= ");        // Print the label for humidity
    Serial.println(DHT.humidity);      // Print the humidity value read from the sensor
  } else {
    Serial.println("Error reading from DHT sensor!");  // Print an error message if reading failed
  }
  delay(1000);                        // Delay for 1 second
}
